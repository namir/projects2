/*
* @author Namir Hassan
* @date 11/17/17
* @name Programming Assignment 7
*/

#include <string.h>
#include "emergency.h"

boolean initialized = false;
int arrivalCounter = 0;


int getCurrentTime() {
	return arrivalCounter; 
}


void printPatient(struct emergencyPatient p) {
	printf("Patient: ");
	printf("\tName: %s ", p.p.name);
	printf("\tAge: %3d ", p.p.age);
	printf("   Arrival: %3d, Priority: %d \n", p.p.arrival, p.priority);
}

void newArrival(char name[], int age) {
	struct emergencyPatient newpatient;

	if (!initialized) {
		MinHeap(20);
		MaxHeap(20);
		Queue(20);
		initialized = true;
	}
	arrivalCounter++;
	strcpy(newpatient.p.name, name);
	newpatient.p.age = age;
	newpatient.p.arrival = arrivalCounter;
	newpatient.priority = age;

	switch (newpatient.p.age) {
	case 0 ... 10: //Category1 patient
		add(newpatient); //Add to minHeap
		break;
	case 11 ... 59: //Category3 patient, between 10 and 60
		enqueue(newpatient); //add to Queue
		break;
	default: //Category2 patient, 60 years and older
		maxadd(newpatient); //add to maxHeap
		break;
	}
	printf("Adding new patient: ");
	printPatient(newpatient);
}

struct patient getNextPatient() {
	int n;
	int i;
	struct emergencyPatient nextPatient;

	
	if (getminheapsize() > 0) {
		if (getFromMinHeap() < 4) {
			nextPatient = delete();
			printPatient(nextPatient);
			incrementMin();
			return (nextPatient.p);
		}
	} else { 
		setFromMinHeap(4);
	}
	
	if (getmaxheapsize() > 0) {
		if (getFromMaxHeap() < 2) {
			nextPatient = maxdelete();
			printPatient(nextPatient);
			incrementMax();
			return (nextPatient.p);
		}
	} else {
		setFromMinHeap(2);
	}

	
	if (getqueuesize() > 0) {
		if (getFromQueue() < 1) {
			nextPatient = dequeue();
			printPatient(nextPatient);
			incrementQueue();
			return (nextPatient.p);
		}
	} else {
		setFromQueue(1);
	}

	
	if ((getFromMinHeap() + getFromMaxHeap() + getFromQueue()) == 7) { 
		printf(
				"Round Ended: Tried to get %d patients from all queues.\n\n",
				(getFromMinHeap() + getFromMaxHeap() + getFromQueue()));
		setFromMinHeap(0);
		setFromMaxHeap(0);
		setFromQueue(0);
		printItems();
		maxprintItems();
		queueprintItems();
	}
	return nextPatient.p;

}
