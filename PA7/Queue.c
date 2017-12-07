/*
* @author Namir Hassan
* @date 11/17/17
* @name Programming Assignment 7
*/

#include "emergency.h"

struct emergencyPatient *queue = NULL; 
int queue_size = 0;
int fromQueue = 0;


void incrementQueue(){
	fromQueue++;
}

int getFromQueue(){
	return fromQueue;
}

void setFromQueue(int count){
	fromQueue = count;
}

void Queue(int cap) {
	if (queue == NULL) {
		queue = calloc(cap, sizeof(struct patient)); 
		if (!queue) {
			printf("Could not allocate array for Queue.\n");
			exit(1);
		}
	}
}

struct emergencyPatient queuepeek() {
	struct emergencyPatient item = {{ "Empty", 0, 0 }, 0};
	if (queue_size == 0) {
		printf("Error: queue_size is 0, exiting...\n");
		
	} else {
		item = queue[0];
	}
	return (item);
}

void enqueue(struct emergencyPatient item) {
	queue[queue_size] = item;
	queue_size++; 
}

struct emergencyPatient dequeue() {
	struct emergencyPatient item = queuepeek(); 
	if (item.p.arrival != 0) { 
		
		for (int i = 0; i < queue_size; i++) {
			queue[i] = queue[i + 1];
		}
		queue_size--; 
	}
	return item;
}

void queueprintItems() {
	printf("Queue: ");
	for (int i = 0; i < queue_size; i++)
		printf("%d ", queue[i].p.age);
	printf("\n");
}

int getqueuesize() {
	return queue_size;
}
