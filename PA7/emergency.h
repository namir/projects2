#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 20

typedef enum {
	false, true
} boolean;

struct patient {
	char name[25];
	int age;
	int arrival;
};

struct emergencyPatient {
	struct patient p;
	int priority;
};

void newArrival(char name[], int age);
struct patient getNextPatient();
int getCurrentTime();

void incrementMin();
int getFromMinHeap();
void setFromMinHeap(int count);

int getLeftChildIndex(int parentIndex);
int getRightChildIndex(int parentIndex);
int getParentIndex(int childIndex);
boolean hasLeftChild(int index);
boolean hasRightChild(int index);
boolean hasParent(int index);

struct emergencyPatient leftChild(int index);
struct emergencyPatient rightChild(int index);
struct emergencyPatient parent(int index);
void swap(int indexOne, int indexTwo);

void ensureExtraCapacity();
struct emergencyPatient peek() ;
void heapifyDown();
struct emergencyPatient delete();
void heapifyUp();
void add(struct emergencyPatient item);

// Builds a heap using integer array dynamically.
void MinHeap(int cap);
void printItems();
int getminheapsize();
void adjustMinHeapPriority(int index);

void incrementMax();
int getFromMaxHeap();
void setFromMaxHeap(int count);
struct emergencyPatient maxleftChild(int index);
struct emergencyPatient maxrightChild(int index);
struct emergencyPatient maxparent(int index);
void maxswap(int indexOne, int indexTwo);
void maxensureExtraCapacity();
struct emergencyPatient maxpeek();
void maxheapifyDown();
struct emergencyPatient maxdelete();
void maxheapifyUp();
void maxadd(struct emergencyPatient item);
void MaxHeap(int cap);
void maxprintItems();
int getmaxheapsize();
void adjustMaxHeapPriority(int index);

void incrementQueue();
int getFromQueue();
void setFromQueue(int count);
void Queue(int cap);
void queueensureExtramax_capacity();
struct emergencyPatient queuepeek();
void enqueue(struct emergencyPatient item);
struct emergencyPatient dequeue();
void queueprintItems();
int getqueuesize();
