/*
* @author Namir Hassan
* @date 11/23/17
* @name Programming Assignment 8
*/

#include "search.h"

struct bst *gNode;

struct bst *newNode(struct car newCar) {
	struct bst *node = malloc(sizeof(struct bst));
	if (node == NULL) {
		printf("Could not allocate memory for node, exiting program\n");
		return (NULL);
	} else {
	
		node->c.inventoryID = newCar.inventoryID;
		strcpy(node->c.make, newCar.make);
		strcpy(node->c.model, newCar.model);
		node->c.year = newCar.year;
		node->c.mileage = newCar.mileage;
		node->c.price = newCar.price;
		node->left = NULL;
		node->right = NULL;

		return (node);
	}
}

void inorder(struct bst *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d, ", root->c.inventoryID);
		inorder(root->right);
	}
}

void inorderByMinMax(struct bst *root, char model[], int min, int max) {
	if (root != NULL) {
		inorderByMinMax(root->left, model, min, max);
		if ((strcmp(root->c.model, model) == 0) &&
				    root->c.price >= min &&
				    root->c.price <= max) {
			printCarFromNode(root);
		}
		inorderByMinMax(root->right, model, min, max);
	}
}

void inorderForMax(struct bst *root, char model[], int max) {
	if (root != NULL) {
		inorderForMax(root->left, model, max);
		if ((strcmp(root->c.model, model) == 0) && root->c.mileage <= max) {
			printCarFromNode(root);
		}
		inorderForMax(root->right, model, max);
	}
}

void inorderLargerThanMax(struct bst *root, char model[], int max) {
	if (root != NULL) {
		inorderLargerThanMax(root->left, model, max);
		if ((strcmp(root->c.model, model) == 0) && root->c.year > max) {
			printCarFromNode(root);
		}
		inorderLargerThanMax(root->right, model, max);
	}
}

struct bst *findLeftmostNost(struct bst *node) {
	if (node == NULL) {
		printf("No left Node, must be root of the tree.\n");
		return node;
	}
	if (node->left == NULL) {
		return node;
	}
	return (findLeftmostNost(node->left));
}

struct bst *search(struct bst *root, char key[]) {
	
	if (root == NULL || strcmp(root->c.model, key) == 0)
		return (root);
	if (strcmp(root->c.model, key) > 0)
		return search(root->left, key);

	return search(root->right, key);
}

struct bst *findNodeInABinaryTree(struct bst *root, int data) {

	if (root == NULL)
		return root;

	struct bst *resultFromLeft = NULL, *resultFromRight = NULL;

	resultFromLeft = findNodeInABinaryTree(root->left, data);
	resultFromRight = findNodeInABinaryTree(root->right, data);

	if (root->c.inventoryID == data) {
		return root; 
	}

	if (resultFromLeft != NULL)
		return (resultFromLeft); 
	else if (resultFromRight != NULL)
		return (resultFromRight); 
	else
		return (NULL);
}

char* getString(struct car aCar, char type) {
	char *tmpstr = (char *) malloc(SIZE * sizeof(char));

	if (tmpstr == NULL) {
		printf("Too bad, can not allocate memory\n");
		exit(1);
	}
	switch (type) {
	case 'y':
		snprintf(tmpstr, SIZE, "%s%d%d", aCar.model, aCar.year,
				aCar.inventoryID);
		break;
	case 'p':
		snprintf(tmpstr, SIZE, "%s%d%d", aCar.model, aCar.price,
				aCar.inventoryID);
		break;
	case 'm':
		snprintf(tmpstr, SIZE, "%s%d%d", aCar.model, aCar.mileage,
				aCar.inventoryID);
		break;

	}
	return tmpstr;
}

struct bst *delete(struct bst *root, char data[], char type) {
	if (root == NULL)
		return root;
	else if (strcmp(data, getString(root->c, type)) < 0)
		root->left = delete(root->left, data, type);
	else if (strcmp(data, getString(root->c, type)) > 0)
		root->right = delete(root->right, data, type);
	else { 

	
		if (root->left == NULL && root->right == NULL) {
			free(root); 
			root = NULL;
		}
	
		else if (root->left == NULL) { 
			struct bst *tmp = root; 
			root = root->right;
			free(tmp); 
		} else if (root->right == NULL) { 
			struct bst *tmp = root; 
			root = root->left;
			free(tmp); 
		} else { 
			struct bst *tmp = findLeftmostNost(root->right);
			root->c = tmp->c;
			root->right = delete(root->right, getString(tmp->c, type), type);
		}
	}
	return root;
}

struct bst *treeByCarYear(struct bst *root, struct car newCar) {

	if (root == NULL) {
		return newNode(newCar);
	}

	char *rootModelYear = getString(root->c, 'y');
	char *newCarModelYear = getString(newCar, 'y');

	if (strcmp(rootModelYear, newCarModelYear) > 0)
		root->left = treeByCarYear(root->left, newCar); 
	else if (strcmp(rootModelYear, newCarModelYear) < 0)
		root->right = treeByCarYear(root->right, newCar);
	return root;
}

struct bst *treeByCarPrice(struct bst *root, struct car newCar) {

	if (root == NULL)
		return newNode(newCar);

	char *rootModelPrice = getString(root->c, 'p');
	char *newCarModelPrice = getString(newCar, 'p');

	if (strcmp(rootModelPrice, newCarModelPrice) > 0)
		root->left = treeByCarPrice(root->left, newCar); 
	else if (strcmp(rootModelPrice, newCarModelPrice) < 0)
		root->right = treeByCarPrice(root->right, newCar);
	return root;
}

struct bst *treeByCarMileage(struct bst *root, struct car newCar) {
	
	if (root == NULL)
		return newNode(newCar);

	char *rootModelMileage = getString(root->c, 'm');
	char *newCarModelMileage = getString(newCar, 'm');

	if (strcmp(rootModelMileage, newCarModelMileage) > 0)
		root->left = treeByCarMileage(root->left, newCar); 
	else if (strcmp(rootModelMileage, newCarModelMileage) < 0)
		root->right = treeByCarMileage(root->right, newCar);
	return root;
}
