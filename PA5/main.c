#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "twitter.h"

void printFollowersOf(int to);
void printFollowing(int from);
void commonFollowersOf(int i, int j);
void mostFollowedUser();
void printUsersBySortedNumberOfFollowers();

int main() {

	printf("Twitter\n");

	addNode("namir0");
	addNode("namir1");
	addNode("namir2");
	addNode("namir3");
	addNode("namir4");
	addNode("namir5");
	addNode("namir6");
	addNode("namir7");
	addNode("namir8");
	addNode("namir9");
	addNode("namir10");
	addNode("namir11");
	addNode("namir12");
	addNode("namir13");
	addNode("namir14");
	addNode("namir15");

	Follow(0,2);
	Follow(1,2);
	Follow(3,2);

	Follow(0,7);
	Follow(4,3);
	Follow(12,5);
	Follow(11,10);
	Follow(4,8);
	Follow(4,6);

	Follow(15,7);
	Follow(14,7);
	Follow(13,7);
	Follow(12,7);
	Follow(11,7);
	Follow(10,7);

	Follow(0,8);
	Follow(1,7);
	Follow(3,6);
	Follow(0,5);
	Follow(1,5);
	Follow(3,8);

	for(int i=0; i<N; i++){
		for(int j=0; j<N;j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("\n");

	printFollowersOf(2);
	printFollowing(2);
	printFollowing(3);
	printFollowersOf(7);
	commonFollowersOf(2, 7);
	commonFollowersOf(8, 6);
	mostFollowedUser();
	printUsersBySortedNumberOfFollowers();
	printf("\n");


}

void printFollowersOf(int to){
	printf("printFollowersOf: User: %s, Follower: ", node[to]->name);

	for(int from = 0; from < N; from++){
		//printf("%d, %d\n", from, to);
		if(A[from][to] == 1){
			printf("%s ", node[from]->name);
		}
	}
	printf("\n");
}

void printFollowing(int from){
	printf("printFollowing: Follower: %s, Following: ", node[from]->name);

	for(int to = 0; to < N; to++){
			if(A[from][to] == 1)
				printf("%s ", node[to]->name);
		}
	printf("\n");
}

void commonFollowersOf(int i, int j){
	printf("commonFollowersOf: Following: %s, %s, Follower: ", node[i]->name, node[j]->name);
	for(int from =0; from < N; from++){
			if((A[from][i] == 1) && (A[from][j] == 1))
				printf("%s ", node[from]->name);
		}
	printf("\n");
}

void mostFollowedUser(){
	int index = -1;
	int count = 0;
	int max = 0;
	for(int to = 0; to < N; to++){
		count = 0;
		for(int from = 0; from < N; from++){
			if(A[from][to] == 1)
				count++;
		}
		if(count > max){
			max = count;
			index = to;
		}
	}
	printf("mostFollowedUser: %s\n", node[index]->name);
}

void printUsersBySortedNumberOfFollowers(){
int followers[N];
int count = 0;

for(int to = 0; to < N; to++){
		count = 0;
		for(int from = 0; from < N; from++){
			if(A[from][to] == 1)
				count++;
		}
	
		followers[to]= count;
}

int max = 0;
int index = -1;
for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
		if(followers[j] > max){
			
			index = j;
			max = followers[j];
		}
	}
		if(max > 0)
			printf("\nName: %s, #OfFollowers: %d\n", node[index]->name, max);
		followers[index]=0; 
		index = -1;
		max = 0;

}
	printf("\n");
}

