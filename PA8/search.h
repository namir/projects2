#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

struct car {
	int inventoryID;
	char make[15];
	char model[15];
	int year;
	int mileage;
	int price;
};

struct bst {
	struct car c;
	struct bst *left;
	struct bst *right;
};

void addNewCar(struct car newCar);
struct car findCheapestCarOfModel(char model[]);
void listAllCarsOfModelPriced(char model[], int minPrice, int maxPrice);
void listAllCarsOfModelWithMaxMileageOf(char model[], int maxMilleage);
void listAllCarsOfModelNewerThan(char model[], int year);
void deleteCar(int inventoryID);
void printCar(struct car aCar);
void printCarFromNode(struct bst *node);

void inorder(struct bst *root);
struct bst *newNode(struct car newCar);
struct bst *treeByCarYear(struct bst *root, struct car newCar);
struct bst *treeByCarPrice(struct bst *root, struct car newCar);
struct bst *treeByCarMileage(struct bst *root, struct car newCar);
struct bst *search(struct bst *root, char key[]);
struct bst *findLeftmostNost(struct bst *node);
void inorderByMinMax(struct bst *root, char model[], int min, int max);
void inorderForMax(struct bst *root, char model[], int max);
void inorderLargerThanMax(struct bst *root, char model[], int max);

struct bst * delete(struct bst *root, char inventoryID[], char type);
struct bst *findNodeInABinaryTree(struct bst *root, int data);
char* getString(struct car aCar, char type);

// For Testing Only
void inorderTreeByYear();
void inorderTreeByPrice();
void inorderTreeByMileage();
