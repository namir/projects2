/*
* @author Namir Hassan
* @date 11/17/17
* @name Programming Assignment 7
*/

#include "emergency.h"

struct emergencyPatient *items = NULL; // pointer to array of elements in heap
int min_heap_size = 0; // Current number of elements in min heap
int fromMinHeap = 0;


void incrementMin(){
	fromMinHeap++;
}

int getFromMinHeap(){
	return fromMinHeap;
}

void setFromMinHeap(int count){
	fromMinHeap = count;
}

int getLeftChildIndex(int parentIndex) {
	return (2 * parentIndex + 1);
}

int getRightChildIndex(int parentIndex) {
	return (2 * parentIndex + 2);
}

int getParentIndex(int childIndex) {
	return (childIndex - 1) / 2;
}

boolean hasLeftChild(int index) {
	return getLeftChildIndex(index) < min_heap_size;
}

boolean hasRightChild(int index) {
	return getRightChildIndex(index) < min_heap_size;
}

boolean hasParent(int index) {
	return getParentIndex(index) >= 0;
}

struct emergencyPatient leftChild(int index) {
	return items[getLeftChildIndex(index)];
}

struct emergencyPatient rightChild(int index) {
	return items[getRightChildIndex(index)];
}

struct emergencyPatient parent(int index) {
	return items[getParentIndex(index)];
}

void swap(int indexOne, int indexTwo) {
	struct emergencyPatient tmp = items[indexOne];
	items[indexOne] = items[indexTwo];
	items[indexTwo] = tmp;
}

struct emergencyPatient peek() {
	if (min_heap_size == 0) {
		printf("Error: min_heap_size can not be 0, exiting...\n");
		exit(1);
	}
	return (items[0]);
}

void heapifyDown() {
	int index = 0; 

	while (hasLeftChild(index)) { 

		adjustMinHeapPriority(index); 
		adjustMinHeapPriority(getLeftChildIndex(index)); 

		if (hasRightChild(index))
			adjustMinHeapPriority(getRightChildIndex(index)); 


		int smallerChildIndex = getLeftChildIndex(index);


		if (hasRightChild(index) && (rightChild(index).priority < leftChild(index).priority)) {
					smallerChildIndex = getRightChildIndex(index);
			}

		if (items[index].priority < items[smallerChildIndex].priority) { 
			break;
		} else {
			swap(index, smallerChildIndex);
		}

		index = smallerChildIndex;

	}
}

struct emergencyPatient delete() {
	struct emergencyPatient item = {{"Empty", 0, 0}, 0}; 

	if (min_heap_size == 0) {
		printf("Error: heap is empty, Can't remove any item...existing...\n");
	} else {
	item = items[0];
	items[0] = items[min_heap_size - 1];
	min_heap_size--;
	heapifyDown();
	}
	return (item);
}

void heapifyUp() {
	int index = min_heap_size - 1; 

	while (hasParent(index) && parent(index).priority > items[index].priority) {
		adjustMinHeapPriority(getParentIndex(index)); 
		swap(getParentIndex(index), index);
		index = getParentIndex(index); 
	}

}

void add(struct emergencyPatient item) {
	items[min_heap_size] = item;
	min_heap_size++;
	heapifyUp();
}


void MinHeap(int cap) {
	if(items == NULL){
	min_heap_size = 0; 
	items = calloc(cap, sizeof(struct patient)); 
	if (!items) {
		printf("Could not allocate array for heap.\n");
		exit(1);
	}
	}
}

void printItems() {
	printf("MinHeap: ");
	for (int i = 0; i < min_heap_size; i++)
		printf("%d ", items[i].p.age);
	printf("\t\t");
}

int getminheapsize(){
	return min_heap_size;
}

void adjustMinHeapPriority(int index){
	int currentTime = getCurrentTime();

	if((currentTime - items[index].p.arrival)/4 >= 7)
		if((items[index].priority - 3) > 0){
			items[index].priority -= 3; 
		
			printf("\tAdjustMinHeapPriority: patient: %d, Priority: %d, currentTime: %d, arrival time: %d  \n", items[index].p.age, items[index].priority, currentTime, items[index].p.arrival);
		}
}
