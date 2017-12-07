


struct node {
int key;
char  typeNode;
struct node *parent;
struct node *right;
struct node *left;

};

void printDF_InOrder(struct node *n);
struct node *RR(struct node *n);
struct node *LL(struct node *n);
struct node *LR(struct node *n);
struct node *RL(struct node *n);
void printNode(struct node *n);
int FindHeight(struct node *n);
