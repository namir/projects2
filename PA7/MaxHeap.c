/*
* @author Namir Hassan
* @date 11/17/17
* @name Programming Assignment 7
*/

#include "emergency.h"


struct emergencyPatient *maxheap = NULL;
int max_heap_size = 0;
int fromMaxHeap = 0;

void incrementMax(){
	fromMaxHeap++;
}
int getFromMaxHeap(){
	return fromMaxHeap;
}
void setFromMaxHeap(int count){
	fromMaxHeap = count;
}
int maxgetLeftChildIndex(int parentIndex) {
	return (2 * parentIndex + 1);
}
int maxgetRightChildIndex(int parentIndex) {
	return (2 * parentIndex + 2);
}
int maxgetParentIndex(int childIndex) {
	return (childIndex - 1) / 2;
}

boolean maxhasLeftChild(int index) {
	return maxgetLeftChildIndex(index) < max_heap_size;
}
boolean maxhasRightChild(int index) {
	return maxgetRightChildIndex(index) < max_heap_size;
}
boolean maxhasParent(int index) {
	return maxgetParentIndex(index) >= 0;
}

struct emergencyPatient maxleftChild(int index) {
	return maxheap[maxgetLeftChildIndex(index)];
}
struct emergencyPatient maxrightChild(int index) {
	return maxheap[maxgetRightChildIndex(index)];
}
struct emergencyPatient maxparent(int index) {
	return maxheap[maxgetParentIndex(index)];
}

void maxswap(int indexOne, int indexTwo) {
	struct emergencyPatient tmp = maxheap[indexOne];
	maxheap[indexOne] = maxheap[indexTwo];
	maxheap[indexTwo] = tmp;
}


struct emergencyPatient maxpeek() {
	if (max_heap_size == 0) {
		printf("Error: heap_size can not be 0, exiting...\n");
		exit(1);
	}
	return (maxheap[0]);
}


void maxheapifyDown() {

	int index = 0; 

	while (maxhasLeftChild(index)) { 
		adjustMaxHeapPriority(index); 
		adjustMaxHeapPriority(getLeftChildIndex(index)); 
		if (hasRightChild(index))
			adjustMaxHeapPriority(getRightChildIndex(index)); 

			int biggerChildIndex = maxgetLeftChildIndex(index);
		
			if (maxhasRightChild(index) && maxrightChild(index).priority > maxleftChild(index).priority){
				biggerChildIndex = maxgetRightChildIndex(index);
				
			}
			if (maxheap[index].priority > maxheap[biggerChildIndex].priority) { 
			
				break;
			} else {
			
				maxswap(index, biggerChildIndex);
			}
		
			index = biggerChildIndex;
	}

}

struct emergencyPatient maxdelete() {
	struct emergencyPatient item = {{"Empty", 0, 0}, 0};
	if (max_heap_size == 0) {
		printf("Error: heap is empty, Can't remove any item...existing...\n");
		
	} else {
	item = maxheap[0];

	maxheap[0] = maxheap[max_heap_size - 1];
	max_heap_size--;
	maxheapifyDown();
	}
	return (item);
}

void maxheapifyUp() {
	int index = max_heap_size - 1; 

		
			while (maxhasParent(index) && maxparent(index).priority < maxheap[index].priority) {
				adjustMaxHeapPriority(getParentIndex(index)); 
				maxswap(maxgetParentIndex(index), index);
				index = maxgetParentIndex(index); 
			}
}
void maxadd(struct emergencyPatient item) {
	maxheap[max_heap_size] = item;
	max_heap_size++;
	maxheapifyUp();
}


void MaxHeap(int cap) {
	if(maxheap == NULL){
	max_heap_size = 0; 
	maxheap = calloc(cap, sizeof(struct patient)); 
	if (!maxheap) {
		printf("Could not allocate array for heap.\n");
		exit(1);
	}
	}
}
void maxprintItems() {
	printf("MaxHeap: ");
	for (int i = 0; i < max_heap_size; i++)
		printf("%d ", maxheap[i].p.age);
	printf("\t\t");
}
int getmaxheapsize(){
	return max_heap_size;
}

void adjustMaxHeapPriority(int index){
	int currentTime = getCurrentTime();

	if((currentTime - maxheap[index].p.arrival)/2 >= 7)
		if((maxheap[index].priority + 10) < 110){
			maxheap[index].priority += 10; 
			printf("\tAdjustMaxHeapPriority: patient: %d, Priority: %d, currentTime: %d, arrival time: %d  \n", maxheap[index].p.age, maxheap[index].priority, currentTime, maxheap[index].p.arrival);
		}
}
