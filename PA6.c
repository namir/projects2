/*
 * @author Namir Hassan
 * @name Programming Assignment 6
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	char item; 
	struct node *left;
	struct node *right;
};

struct node *makeNode(char item) {
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->item = item;
	n->left = NULL;
	n->right = NULL;
	return n;

}

int sum(struct node *p) {

	if (p == NULL)
		return 0;
	return p->item + sum(p->left) + sum(p->right);

}

void printDF_Inorder(struct node *p) {

	if (p == NULL)
		return;

	printDF_Inorder(p->left);  
	printf("\t%c", p->item);  
	printDF_Inorder(p->right); 
}

void printDF_Preorder(struct node *p) {
	if (p == NULL)
		return;
	printf("\t%c", p->item);   
	printDF_Preorder(p->left);  
	printDF_Preorder(p->right); 
}

void printDF_Postorder(struct node *p) {
	if (p == NULL)
		return;
	printDF_Postorder(p->left); 
	printDF_Postorder(p->right);
	printf("\t%c", p->item);	
}

void mirror(struct node *p){
	struct node *tmp;
	if(p ==  NULL)
		return;
	tmp = p->left; 
	p->left = p->right; 
	p->right = tmp; 
	mirror(p->left); 
	mirror(p->right); 
}


int main() {

	struct node *root = makeNode('A'); 

	root->left = makeNode('B');
	root->left->right = makeNode('D');
	root->left->right->left = makeNode('G');
	root->left->right->left->left = makeNode('I');

	root->right = makeNode('C');
	root->right->left = makeNode('E');
	root->right->right = makeNode('F');
	root->right->left->right = makeNode('H');
	root->right->left->right->left = makeNode('J');
	root->right->left->right->right = makeNode('K');

	printf("\nPreorder of Figure 1: ");
	printDF_Preorder(root);
	printf("\nInorder of Figure 1: ");
	printDF_Inorder(root);
	printf("\nPostorder of Figure 1: ");
	printDF_Postorder(root);
	printf("\n");

	
	struct node *root2 = makeNode('A');
	root2->left = makeNode('B');
	root2->left->right = makeNode('D');

	root2->right = makeNode('C');
	root2->right->left = makeNode('E');
	root2->right->right = makeNode('F');
	root2->right->left->right = makeNode('G');

	printf("\npostorder of Figure 2 Left side: ");
	printDF_Postorder(root2);
	printf("\n");

	mirror(root2);

	mirror(root);

	printf("\nPostorder of mirror tree of Figure 2: ");
	printDF_Postorder(root2);
	printf("\n");

	printf("\nPostorder of mirror tree of Figure 1: ");
	printDF_Postorder(root);
	printf("\n");
	return 0;
}
