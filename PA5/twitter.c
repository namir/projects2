/*
* @author Namir Hassan
* @date 11/1/17
* @name Programming Assignment 5
*/

#include "twitter.h"
#include "graph.h"

#include <stdio.h>
#include <string.h>

void Follow(int from, int to) { 
	addEdge(from, to);
}

void unFollow(int from, int to ) {
	deleteEdge(from,to);
}

void sendTweet( int from, char tweet[] ) {


node_t *sender = node[from];

int k = sender->nbTweetsSent ;
strcpy ( sender->messageSent [k]
        , tweet );

sender->nbTweetsSent++;

for (int i = 0; i < N; i++)
    if ( A[i][from] == 1)
    receiveTweet ( i, tweet );
}


void receiveTweet( int to, char tweet[] ) {
node_t *receiver = node[to];
int k = receiver->nbTweetsReceived ;
strcpy ( receiver->messageReceived[k]
        , tweet );

printf("%s:  I received a new tweet: %s\n", receiver->name,
       receiver->messageReceived[k] );

receiver->nbTweetsReceived++;

}


