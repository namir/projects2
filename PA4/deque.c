#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int Deque[N];

int front = -1;
int rear = -1;

void printDeque(){
	printf("front: %d, rear: %d\n", front, rear);
	printf("Deque: ");
	for(int k=front; k<=rear; k++)
	printf("%d ", Deque[k]);
	printf("\n");
}

void shiftRight() {
//	printf("shiftRight: front: %d, rear: %d\n", front, rear);
	rear++;
	for(int r = rear; r > front; r-- ){
		Deque[r] = Deque[r-1];
	}
}

void shiftLeft() {
//	printf("shiftLeft: front: %d, rear: %d\n", front, rear);
	for(int f=front; f < rear; f++){
			Deque[f] = Deque[f+1];
		}
	Deque[rear] = -1;
		rear--;
		printDeque();
}

void addFront(int item) {
//	printf("addFront: ");
//	printDeque();
if (isFull()) return;
if (front == -1) { front = 0; rear = 0;}
else if (front == 0)
        shiftRight();
else front--;
Deque[front] = item;
//printDeque();
}

void addRear(int item) {
//	printf("addRear: ");
//	printDeque();
 if ( isFull() ) return;
 if (rear == -1) { front = 0; rear = 0; }
 else if (rear == N-1) shiftLeft();
 else rear++;
 Deque[rear] = item;
// printDeque();
 }

void deleteFront() {
	//printf("deleteFront: front: %d, rear: %d\n", front, rear);
	if(issEmpty()) return;
	if(front == 0)
		shiftLeft();
	else
		front++;
}
void deleteRear() {
	//printf("deleteRear: front: %d, rear: %d\n", front, rear);
	if(issEmpty()) return;
	if(rear == N-1)
		shiftRight();
	else
		rear--;
}

int getFirst() {
	return(Deque[front]);
}
int getLast() {
	return(Deque[rear]);
}

boolean issEmpty() { if ((front == -1) || (rear == -1)) return true; return false;}

boolean isFull() {
 if (rear - front + 1 == N)
    return true;
    else
    return false;
}
