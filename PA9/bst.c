/**
* @author Namir Hassan
* @date 12/3/17
* @name Programming Assignment 9
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// uncomment these for testing

//int keys[] = { 3, 5, 61, 9, 32, 7, 1, 45, 26, 6 };
//int keys[] = { 3, 5, 61, 9, 32, 7, 1, 45, 26 };
//int keys[] = { 3, 5, 61, 9, 32, 7, 1, 45 };
//int keys[] = { 3, 5, 61, 9, 32, 7, 1 };
//int keys[] = { 3, 5, 61, 9, 32, 7 };
//int keys[] = { 3, 5, 61, 9, 32 };
//int keys[] = { 3, 5, 61, 9};
//int keys[] = { 3, 5, 61};

struct node *root = NULL;

struct node *makeNode(int key) {
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;

	return n;
}

int findBalanceOfNode(struct node *n) {
	int balance = 0;
	int lh = 0;
	int rh = 0;
	if (n != NULL) {
		lh = FindHeight(n->left) + 1;
		lh = (lh < 0) ? 0 : lh; 
		rh = FindHeight(n->right) + 1;
		rh = (rh < 0) ? 0 : rh; 
		balance = lh - rh;
	}
	return (balance);
}

struct node *checkBalance(struct node *n) {
	int lb;

	lb = findBalanceOfNode(n);
	if (lb == 2) {
				if(findBalanceOfNode(n->left) < 0) 
					n = LR(n);

		if(findBalanceOfNode(n->left) > 0)
			n = LL(n);

	}
	if (lb == -2) {
		if(findBalanceOfNode(n->right) < 0) 

		if(findBalanceOfNode(n->right) > 0) 
			n = RL(n);
	}

	return n;
}

void insertKeyBST(struct node *n, int key) {
	int nb = 0;
	if (n->key > key) {
		if (n->left == NULL) {
			n->left = makeNode(key);
			n->left->parent = n;
			n->left->typeNode = 'L';
			printf("\nInserting %d as %c", key, 'L');
		} else {
			insertKeyBST(n->left, key);
		}
	}
	if (n->key < key) {
		if (n->right == NULL) {
			n->right = makeNode(key);
			n->right->parent = n;
			n->right->typeNode = 'R';

		} else {
			insertKeyBST(n->right, key);
		}
	}

	nb = findBalanceOfNode(n);
		if(nb ==2 || nb == -2){
			if(n->parent == NULL){ 
				root = checkBalance(n);
				printf("This is root node: %d\n", n->key);

			} else{
				struct node *nodeParent = n->parent;

                if(nodeParent->right == n){
                	nodeParent->right = checkBalance(n);
                	nodeParent->right->parent = nodeParent;
                	nodeParent->right->typeNode = 'R';
                }
                else{
                	nodeParent->left = checkBalance(n);
                	nodeParent->left->parent = nodeParent;
                    nodeParent->left->typeNode = 'L';
                }
			}
		}

}

void printNode(struct node *n) {

	if (n == NULL)
		return;
	printf("\n Node: %d %c ", n->key, n->typeNode);

	if (n->parent != NULL)
		printf("Parent = %d %c ", n->parent->key, n->parent->typeNode);
	else
		printf("Parent = NULL ");

	if (n->left != NULL)
		printf("Left = %d %c ", n->left->key, n->left->typeNode);
	else
		printf("Left = NULL ");

	if (n->right != NULL)
		printf("Right = %d %c ", n->right->key, n->right->typeNode);
	else
		printf("Right = NULL ");

}

void printDF_InOrder(struct node *n) {

	if (n == NULL)
		return;
	printDF_InOrder(n->left);
	printNode(n);
	printDF_InOrder(n->right);

}

struct node *rotateRight(struct node *n) {
	struct node *tmp;
	tmp = n->left;
	n->left = tmp->right;
	if(n->left != NULL){
		n->left->parent = n;
		n->left->typeNode = 'L';
	}
	tmp->right = n;
	tmp->right->parent = tmp;
	tmp->typeNode = n->typeNode;
	n->typeNode = 'R';

	return tmp;
}
struct node *rotateLeft(struct node *n) {
	struct node *tmp;
	tmp = n->right;
	tmp->parent = n->parent;
	n->right = tmp->left;
	if(n->right != NULL){
		n->right->parent = n;
		n->right->typeNode = 'R';
	}
	tmp->left = n;
	tmp->typeNode = n->typeNode;
	tmp->left->parent = tmp;
	n->typeNode = 'L';

	return tmp;
}

struct node *RR(struct node *n) {
	return (rotateLeft(n));
}
struct node *LL(struct node *n) {
	return (rotateRight(n));
}
struct node *LR(struct node *n) {
	n->left = rotateLeft(n->left);
	return (rotateRight(n)); 
}
struct node *RL(struct node *n) {
	n->right = rotateRight(n->right);
	return (rotateLeft(n));
}

int FindHeight(struct node *n) {
	if (n == NULL)
		return -1; 
	int lh = FindHeight(n->left);
	int rh = FindHeight(n->right);
	return ((lh > rh ? lh : rh) + 1);
}

int main() {

	root = makeNode(keys[0]);

	for (int i = 1; i < sizeof(keys) / sizeof(int); i++)
		insertKeyBST(root, keys[i]);

	printDF_InOrder(root);
	printf("\nHeight: %d\n", FindHeight(root));

}
