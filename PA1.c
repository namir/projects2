/*
* Namir Hassan
* September 23, 2017
* Programming Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>

#define END -1
#define SIZE 32

typedef int E;
typedef enum {false = 0, true = 1} boolean; 

void add(E item); 
void _add(int pos, E item); // c does not support function overloading, renamed add() to _add()
boolean contains(E item); 
int size();
boolean isEmpty(); 
E get(int pos);
E _remove(int pos); // remove() conflicts with remove() in stdio.h, renamed to _remove()
void displayList();

E *globalarray; // this is the dynamic array which will go and sync while program run
E *tmp;
E arraysize = 0; // this will keep the size of dynamic array 


int main()
{

	globalarray = malloc(0 * sizeof(int)); // mem alloc 1 element

	char buffer[SIZE];

	int item;
	int pos;


	while(1){

	printf("\n");
	printf("a.) Add item to end of the List or at position in the List\n");
	printf("c.) Check if item is in the List\n");
	printf("s.) Return the number of items in the List\n");
	printf("e.) Check if the List is empty\n");
	printf("g.) Return the item at position in the List\n");
	printf("r.) Remove and return item at position in the List\n");
	printf("d.) Display List\n");
	printf("q.) Quit\n");
	printf("\nEnter choice: ");

		if(fgets(buffer, sizeof(buffer), stdin) != NULL){

			switch(*buffer) {

				case 'a':
				case 'A':
							printf("Enter a number: ");
							fgets(buffer, sizeof(buffer), stdin);
							item = atoi(buffer);
							printf("\n");

							printf("Enter a position to insert in List (-1 for end, or any positive number): ");
							fgets(buffer, sizeof(buffer), stdin);
							pos = atoi(buffer);
							printf("\n");

							if(pos < 0) {

								add(item);
							} else {
								_add(pos, item);
							}
							break;
				case 'c':
				case 'C':
							printf("Enter a number: ");
							fgets(buffer, sizeof(buffer), stdin);
							item = atoi(buffer);
							printf("\n");

							contains(item);
							break;
				case 's':
				case 'S':
							printf("Size (number of items in list): %d\n", size());
							break;
				case 'e':
				case 'E':
							isEmpty();
							break;
				case 'g':
				case 'G':
							printf("Enter a position to get number from List (a positive number): ");
							fgets(buffer, sizeof(buffer), stdin);
							pos = atoi(buffer);
							printf("\n");

							if(pos < 0) {

								printf("Error: Position can not be negative.");
							} else {
								printf("%d is at position %d\n", get(pos), pos);
							}
							break;
				case 'r':
				case 'R':
							printf("Enter a position to remove from List (a positive number): ");
							fgets(buffer, sizeof(buffer), stdin);
							pos = atoi(buffer);
							printf("\n");
							printf("Removed %d from %d\n", _remove(pos), pos);

							break;
				case 'q':
				case 'Q':
							printf("\nExiting...\n\n");
							exit(1);
				case 'd':
				case 'D':
							displayList();
							break;
			}
		}
	}
	return 0;
}

void add(E item)
{
	tmp = (int *) realloc(globalarray, (arraysize + 1) * sizeof(int));

	if(tmp != NULL){
		arraysize++;

		globalarray[arraysize - 1] = item;
 	}

}

void _add(int pos, E item)
{
 	if((pos < 0) || (pos > (arraysize - 1)))
	{
		printf("Error: pos %d is out of range.\n", pos);
		exit(1);
	} 
	// increase size by 1
	arraysize++;
	// reallocating space at the end of array
	tmp = (int *) realloc(globalarray, (arraysize) * sizeof(int));
	if(tmp != NULL){
		for(int i = (arraysize - 1); i > pos; i--) {
		// now shifting left
		
		globalarray[i] = globalarray[i - 1]; 
		//printf("\n\nINDEX %d, ITEM: %d\n", i, globalarray[i]);

		}
		globalarray[pos] = item;
	} else {
	printf("Error: points to NULL\n");
	exit(1);
	}
}						

boolean contains(E item)
{
	int arr = size();

	for(int i = 0; i < arr; i++) {

		if(globalarray[i] == item) {

			printf("\nItem %d is in the List\n", item);

			return true;
		}
	}
	printf("\nItem %d is not in the List\n", item);
	return false;
}

int size()
{
	return arraysize;
}

boolean isEmpty()
{
	if(arraysize <= 0) {
		printf("List is empty!\n");
		return true;
	} else {
		printf("List is not empty!\n");
		return false;
	}
}

E get(int pos)
{
	if((pos < 0) || (pos > (arraysize - 1)))
	{
		printf("Error: pos %d is out of range.\n", pos);
		exit(1);
	}

	return globalarray[pos];
}
E _remove(int pos)
{
	int item;

	if((pos < 0) || (pos > (arraysize - 1)))
	{
		printf("Error: pos %d is out of range.\n", pos);
		exit(1);
	} 
	item = globalarray[pos];

	for(int i = (pos + 1); i < (arraysize); i++) {
		// now shifting left
		globalarray[i - 1] = globalarray[i]; 
	}
	// reducing size by 1 after shifting left
	arraysize--; 

	// realloc
	tmp = (int *) realloc(globalarray, (arraysize) * sizeof(int));

	return item;
}

void displayList()
{
	int i;
	int tmpsize = size();

	printf("\nArray: { ");
	for(i = 0; i < tmpsize; i++){
		printf("%d ", globalarray[i]);
	}
	printf("}\n");
}
