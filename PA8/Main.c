/*
* @author Namir Hassan
* @date 11/23/17
* @name Programming Assignment 8
*/

#include "search.h"

int main() {

	struct car newCar;

	newCar.inventoryID = 1;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "528i");
	newCar.year = 2012;
	newCar.mileage = 80000;
	newCar.price = 25000;
	addNewCar(newCar);

	newCar.inventoryID = 2;
	strcpy(newCar.make, "Nissan");
	strcpy(newCar.model, "Sentra");
	newCar.year = 2015;
	newCar.mileage = 40000;
	newCar.price = 20000;
	addNewCar(newCar);

	newCar.inventoryID = 3;
	strcpy(newCar.make, "Honda");
	strcpy(newCar.model, "CRV");
	newCar.year = 2012;
	newCar.mileage = 33000;
	newCar.price = 18000;
	addNewCar(newCar);

	newCar.inventoryID = 4;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "528i");
	newCar.year = 2017;
	newCar.mileage = 50;
	newCar.price = 60000;
	addNewCar(newCar);

	newCar.inventoryID = 5;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2015;
	newCar.mileage = 33000;
	newCar.price = 35000;
	addNewCar(newCar);

	newCar.inventoryID = 6;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "528i");
	newCar.year = 2014;
	newCar.mileage = 45000;
	newCar.price = 30000;
	addNewCar(newCar);

	newCar.inventoryID = 7;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2011;
	newCar.mileage = 63000;
	newCar.price = 25000;
	addNewCar(newCar);

	newCar.inventoryID = 8;
	strcpy(newCar.make, "Nissan");
	strcpy(newCar.model, "Sentra");
	newCar.year = 2010;
	newCar.mileage = 60000;
	newCar.price = 16000;
	addNewCar(newCar);

	newCar.inventoryID = 9;
	strcpy(newCar.make, "Honda");
	strcpy(newCar.model, "CRV");
	newCar.year = 2016;
	newCar.mileage = 5000;
	newCar.price = 25000;
	addNewCar(newCar);

	newCar.inventoryID = 10;
	strcpy(newCar.make, "Honda");
	strcpy(newCar.model, "CRV");
	newCar.year = 2008;
	newCar.mileage = 80000;
	newCar.price = 10000;
	addNewCar(newCar);

	newCar.inventoryID = 11;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2010;
	newCar.mileage = 53000;
	newCar.price = 26000;
	addNewCar(newCar);

	newCar.inventoryID = 12;
	strcpy(newCar.make, "Nissan");
	strcpy(newCar.model, "Sentra");
	newCar.year = 2010;
	newCar.mileage = 90000;
	newCar.price = 10000;
	addNewCar(newCar);

	newCar.inventoryID = 13;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2010;
	newCar.mileage = 35000;
	newCar.price = 30000;
	addNewCar(newCar);

	newCar.inventoryID = 14;
	strcpy(newCar.make, "Honda");
	strcpy(newCar.model, "CRV");
	newCar.year = 2017;
	newCar.mileage = 5000;
	newCar.price = 30000;
	addNewCar(newCar);

	newCar.inventoryID = 15;
	strcpy(newCar.make, "Nissan");
	strcpy(newCar.model, "Sentra");
	newCar.year = 2010;
	newCar.mileage = 40000;
	newCar.price = 20000;
	addNewCar(newCar);

	newCar.inventoryID = 16;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2013;
	newCar.mileage = 53000;
	newCar.price = 20000;
	addNewCar(newCar);

	newCar.inventoryID = 17;
	strcpy(newCar.make, "BMW");
	strcpy(newCar.model, "328i");
	newCar.year = 2016;
	newCar.mileage = 13000;
	newCar.price = 40000;
	addNewCar(newCar);

	newCar.inventoryID = 18;
	strcpy(newCar.make, "Nissan");
	strcpy(newCar.model, "Sentra");
	newCar.year = 2010;
	newCar.mileage = 60000;
	newCar.price = 15000;
	addNewCar(newCar);



	printf("Testing .....\n");
	printf("Cheapest car for model: \"%s\"::\n", "328i");
	struct car cheapest = findCheapestCarOfModel("328i");
	printCar(cheapest);

	printf("\nCars with model: \"%s\" within (%d, %d) price range::\n", "528i",
			30000, 55000);
	listAllCarsOfModelPriced("528i", 30000, 55000);

	printf("\nCars with model: \"%s\" within (%d, %d) price range::\n", "328i",
			30000, 40000);
	listAllCarsOfModelPriced("328i", 30000, 40000);

	printf("\nCars with model: \"%s\" with equal/less than %d mileage::\n",
			"528i", 30000);
	listAllCarsOfModelWithMaxMileageOf("528i", 30000);

	printf("\nCars with model: \"%s\" with newer than year %d::\n", "528i",
			2010);
	listAllCarsOfModelNewerThan("528i", 2010);

	int inventoryId = 16;
	printf("\nAll BST contents before deleting inventory Id: %d\n",inventoryId);
	inorderTreeByYear();
	inorderTreeByPrice();
	inorderTreeByMileage();
	deleteCar(16);
	printf("\nBST contents after deleting inventory Id: %d\n",inventoryId);
	inorderTreeByYear();
	inorderTreeByPrice();
	inorderTreeByMileage();

	return 0;
}
