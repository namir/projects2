/*
* @name Programming Assignment 4
* @author Namir Hassan
* @date 10/23/17
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

element *stackS1 = NULL;
element *stackS2 = NULL;
element *stackS3 = NULL;

element *evenQ = NULL;
element *oddQ = NULL;
element *oneQ = NULL;


int main() {

	char buffer[SIZE];
	int n;
	int m;
	int nm;
	int item;
	int i = 0;

	printf("\nEnter a number for n: ");
	if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
		n = atoi(buffer); 

		// Push all the n read items in stackS1.
		for(i = 0; i < n; i++) {
			printf("Enter a number for stackS1 item: ");
			if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
				item = atoi(buffer);
				stackS1 = push(item, stackS1);
			}
		}
		printf("\n");
		displayStackOnly(stackS1);
		printf("\n");
	} else {
		printf("Error: Can not read number for n.");
		exit(1);
	}

	printf("\nEnter a number for m: ");
	if(fgets(buffer, sizeof(buffer), stdin) != NULL) { 
		m = atoi(buffer); 

		// Push all the m read items in stackS2.
		for(i = 0; i < m; i++) {
			printf("Enter a number for stackS2 item: ");
			if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
				item = atoi(buffer);
				stackS2 = push(item, stackS2);
			}
		}
		printf("\n");
		displayStackOnly(stackS2);
		printf("\n");
	} else {
			printf("Error: Can not read number for m.");
			exit(1);
		}

	// Problem #1 Using two Queues
  while(!isEmpty(stackS1) || !isEmpty(stackS2)){

		if(!isEmpty(stackS1)){
			// get and save the number of a pop element
			item = peek(stackS1);
			//remove the element from stack using pop function.
			stackS1 = pop(stackS1);
			// analyze the saved item, to findout even or odd.
			if(item % 2 == 0){
				evenQ = enQueue(item, evenQ);
			} else {
				oddQ = enQueue(item, oddQ); 
			  }
		}
		
		if(!isEmpty(stackS2)){
			
			item = peek(stackS2);
			
			stackS2 = pop(stackS2);
		
			if(item % 2 == 0){
				evenQ = enQueue(item, evenQ); 
			} else {
				oddQ = enQueue(item, oddQ); 
			  }
		}
	}

	displayStackOnly(evenQ);
	displayStackOnly(oddQ);

	
	while ( evenQ != NULL ) {
	   item = peek(evenQ);
	   evenQ = pop(evenQ); 
	   stackS3 = push(item, stackS3);
	}

	while ( oddQ != NULL ) {
		item = peek(oddQ);
		oddQ = pop(oddQ);
		stackS3 = push(item, stackS3); 
	}

	displayStackOnly(stackS3);
	printf("\n");


	return 0;
}

element *push(int item, element *head) {

element *p = ( element *) malloc ( sizeof(element));
p->item = item;
p->next = head;
head = p;
return head;
}

element *enQueue(int item, element *head){

	element *tmp = NULL;
	element *p = ( element *) malloc ( sizeof(element));
	if(p == NULL) {
		printf("Error: Can't malloc space.\n");
		exit(1);
	}

	p->item = item;
	p->next = NULL; 

	if (head == NULL){ 
	 head = p;
	} else {
		tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next; 
		}
		
		tmp->next = p;
	}
	return head;
}

int peek(element *head) {
    return head->item;


}
boolean isEmpty(element *head) {
if (head == NULL) return true;
else
    return false;
}

element *pop(element *head) {
	int item;
	element *tmp = head;

    if ( ! isEmpty(head) ) {
    item = head->item;
    head = head->next;
    
    free(tmp);

    return head;
	}
    else return NULL;

}

void displayStack(element *head) {

printf ("\nThe stack now contains \n");

while ( ! isEmpty(head) ) {
    printf("%d\n", peek(head) );
    head = pop(head);
}

}

void displayStackOnly(element *head) {
element *p = head;

printf ("\n\nItems are: \n");
while ( p != NULL ) {
    printf( "%d\n", peek(p) );
    p = p->next;
}
printf ("\n");
}
