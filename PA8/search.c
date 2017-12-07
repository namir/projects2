/*
* @author Namir Hassan
* @date 11/23/17
* @name Programming Assignment 8
*/

#include "search.h"

struct bst *treeByYear = NULL;
struct bst *treeByPrice = NULL;
struct bst *treeByMileage = NULL;
struct bst inventory[250];

void addNewCar(struct car newCar) {
	treeByYear = treeByCarYear(treeByYear, newCar);
	treeByPrice = treeByCarPrice(treeByPrice, newCar);
	treeByMileage = treeByCarMileage(treeByMileage, newCar);
}

struct car findCheapestCarOfModel(char model[]) {
	struct car carFound = {0, "", "", 0, 0, 0};

	struct bst *node = search(treeByPrice, model);

	if(node != NULL){
		node =  findLeftmostNost(node);
		if(node != NULL){
			carFound = node->c;
		}
	}
	return (carFound);
}

void listAllCarsOfModelPriced(char model[], int minPrice, int maxPrice) {

	struct bst *node = search(treeByPrice, model);

	if(node != NULL){
		inorderByMinMax(node, model, minPrice, maxPrice);
	} else {
		printf("Model:\"%s\" with price range %d to %d) does not not exist.\n", node->c.model, minPrice, maxPrice);
	}
}

void listAllCarsOfModelWithMaxMileageOf(char model[], int maxMilleage) {

	struct bst *node = search(treeByPrice, model);

	if(node != NULL){
			printf("Model:\"%s\" with (InventoryId: %d,  mileage %d) is the model subtree's root.\n", node->c.model, node->c.inventoryID, node->c.mileage);
			inorderForMax(node, model, maxMilleage);
		} else {
			printf("Model:\"%s\" equal/less than %d mileage) does not not exist.\n", node->c.model, maxMilleage);
		}
}

void listAllCarsOfModelNewerThan(char model[], int year) {

	struct bst *node = search(treeByPrice, model);

	if(node != NULL){
			printf("Model:\"%s\" with (InventoryId: %d,  year: %d) is the model subtree's root.\n", node->c.model, node->c.inventoryID, node->c.year);
			inorderLargerThanMax(node, model, year);
		} else {
			printf("Model:\"%s\" newer than year %d) does not exist.\n", node->c.model, year);
		}
}

void deleteCar(int inventoryID) {

	struct bst *byNode = findNodeInABinaryTree(treeByYear, inventoryID);
	struct bst *bpNode = findNodeInABinaryTree(treeByPrice, inventoryID);
	struct bst *bmNode = findNodeInABinaryTree(treeByMileage, inventoryID);

	if(byNode != NULL && bpNode != NULL && bmNode != NULL){
	treeByYear = delete(treeByYear, getString(byNode->c, 'y'), 'y');
	treeByPrice = delete(treeByPrice, getString(bpNode->c, 'p'), 'p');
	treeByMileage = delete(treeByMileage, getString(bmNode->c, 'm'), 'm');
	} else {
		printf("Car with inventory Id: %d does not exist in BST\n", inventoryID);
	}
}

void printCar(struct car aCar){
	printf("InventoryID: %d, Make: %s, Model: %s, Year: %d, Mileage: %d, Price: %d\n",
			aCar.inventoryID, aCar.make, aCar.model, aCar.year, aCar.mileage, aCar.price);
}

void printCarFromNode(struct bst *node){
	if(node != NULL)
		printCar(node->c);
}
void inorderTreeByYear(){
	printf("InOrder Traverse: ");
	inorder(treeByYear);
	printf("\n");
}
void inorderTreeByPrice(){
	printf("InOrder Traverse: ");
	inorder(treeByPrice);
	printf("\n");
}
void inorderTreeByMileage() {
	printf("InOrder Traverse: ");
	inorder(treeByMileage);
	printf("\n");
}
