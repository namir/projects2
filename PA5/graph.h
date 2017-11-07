
#define N 16
#define M 10

typedef struct {
        char name[10];
        int nbTweetsSent;
        char messageSent[M][140];
        int nbTweetsReceived;
        char messageReceived[M][140];
} node_t;


node_t *node[N];

int A[N][N];

void addNode(char name[]);
void addEdge(int from, int to);

void deleteNode(node_t n);
void deleteEdge(int from, int to);
