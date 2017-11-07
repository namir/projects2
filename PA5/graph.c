/*
* @author Namir Hassan
* @date 11/1/17
* @name Programming Assignment 5
*/

#include <stdio.h>
#include "graph.h"
#include <string.h>
#include <stdlib.h>

int nbUsers = 0;


void addNode(char name[]) {
    node[nbUsers] = (node_t *) malloc( sizeof (node_t ));
    strcpy( node[nbUsers]->name, name  );
      nbUsers++;
}

void addEdge(int from, int to) {
    A[from][to] = 1;
}

void deleteNode(node_t n ) {

	for(int userIndex=0; userIndex < nbUsers; userIndex++){
		if(strcmp(node[userIndex]->name, n.name) == 0 )
			node[userIndex] = NULL;
		else
			printf("Could not find %s to delete.\n", n.name);
	}
}


void deleteEdge(int from, int to) {
  A[from][to] = 0;
}
