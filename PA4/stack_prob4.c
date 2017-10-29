#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_t {
        int data;
        struct node_t * next;
};

struct node_t * push(struct node_t *head, int tmp);
int pop(struct node_t **head);
void addFront(int *a, int item); 
void addRear(int *a, int item);
void deleteFront(int *a);
void deleteRear(int *a);
void shiftLeft(int *a);
void shiftRight(int *a);
bool isFullD(int *a);
bool isEmptyD(int *a);
bool isEmpty(struct node_t *head);
int get_rear(int *a);
int get_front(int *a);
void print_deque(int *a);
void print_stack(struct node_t *head);


int front = -1;
int rear = -1; 
int size = 0;
int main(void)
{
        char buf[32];
        int size1, size2;

        printf("Enter the number of elements for deque to be added from the front: ");
        fgets(buf, 32, stdin);
        size1 = atoi(buf); //Size of the first list

        printf("Enter the number of elements for deque to be added from the rear: ");
        fgets (buf, 32, stdin);
        size2 = atoi(buf); //Size of the second list

        size = size1 + size2;
        int *deque = (int *) malloc((size1 + size2) * sizeof(int));
        struct node_t *mainStack = NULL;

        for(int i = 0; i < size1; i++) {
                printf("Enter the element from the front: ");
                fgets(buf,32, stdin);
                int tmp = atoi(buf);
                addFront(deque, tmp);
        }
        print_deque(deque);

        for (int i = 0; i < size2; i++) {
                printf("Enter the element from the back: ");
                fgets(buf, 32, stdin);
                int tmp = atoi(buf);
                addRear(deque, tmp);
        }
        print_deque(deque);

        while (!isEmptyD(deque)) {
                int tmp = get_front(deque);
                deleteFront(deque);
                mainStack = push(mainStack, tmp);
                if (isEmptyD(deque))
                        break;
                tmp = get_rear(deque);
                deleteRear(deque);
                mainStack = push(mainStack, tmp);
                if (isEmptyD(deque))
                        break;
        }
        print_stack(mainStack);
        int sizeEven = 0;
        while(!isEmpty(mainStack)) {
                int tmp = pop(&mainStack);
                if ((tmp % 2) == 0) {
                        addFront(deque, tmp);
                        sizeEven++;
                }
                else 
                        addRear(deque, tmp);
        }
        print_deque(deque);
        while (sizeEven) {
                int tmp = get_front(deque);
                deleteFront(deque);
                mainStack = push(mainStack, tmp);
                sizeEven--;
        }
        while(!isEmptyD(deque)) {
                int tmp = get_rear(deque);
                deleteRear(deque);
                mainStack = push(mainStack, tmp);
        }
        print_stack(mainStack);
        
        free(deque);
        while( !isEmpty(mainStack)) {
                pop(&mainStack);
        }
        return 0;
}
struct node_t *push(struct node_t *head, int tmp)
{
        if (head == NULL) {
                head = malloc(sizeof(struct node_t));
                head -> data = tmp;
                head -> next = NULL;
        } else {
                struct node_t *tmp1 = malloc(sizeof(struct node_t));
                tmp1 -> data = tmp;
                tmp1 -> next = head;
                head = tmp1;
        }
        return head;
}
int pop(struct node_t **head)
{
        int tmp = (*head) -> data;
        struct node_t *tmp1 = (*head) -> next;
        free((*head));
        (*head) = tmp1;
        return tmp;
}
void addFront(int *a, int item) 
{
        if(isFullD(a)) {
                printf("Error: Deque is Full. Element %d is not added. In addfront\n", item);
                return;
        }
        if (front == -1) {
                front++;
                rear++;
        } 
        else if (front == 0) {
                shiftRight(a);
        } else {
                front--;
        }
        a[front] = item;
}
void shiftRight(int *a)
{
        for (int i = rear; i >= front; i--) {
                a[i + 1] = a[i];
        }
        rear++;
}
void addRear(int *a, int item)
{
        if (isFullD(a)) {
                printf("Error: Deque is Full. Element %d is not added In addrear\n", item);
                return;
        }
        if (rear == -1) {
                front++;
                rear++;
        } else if (rear == size - 1) {
                shiftLeft(a);
        } else {
                rear++;
        }
        a[rear] = item;
}
void shiftLeft(int *a) 
{
        for (int i = front; i <= rear; i++) {
                a[i - 1] = a[i];
        }
        front--;
        
}

void deleteFront(int *a)
{
        if (isEmptyD(a)) {
                printf("Error: Deque is empty. In deletefront\n");
                return;
        } if (front == rear) {
                front = -1;
                rear = -1;
        } else 
                front++;
}
void deleteRear(int *a)
{
        if (isEmptyD(a)) {
                printf("Error: Deque is empty In deleterear \n");
                return;
        } else if (front == rear) {
                rear = -1;
                front = -1;
        } else 
                rear--; 
}

bool isFullD(int *a) 
{
        if (rear == size - 1)
                return true;
        return false;
}
bool isEmptyD(int *a)
{
        if(front == -1)
                return true;
        return false;
}
bool isEmpty(struct node_t *head)
{
        if (head == NULL)
                return true;
        return false;
}
int get_front(int *a)
{
        return a[front];
}
int get_rear(int *a)
{
        return a[rear];
}
void print_deque(int *a)
{
        printf("Deque:\t");
        for(int i = front; i <= rear; i++) {
                printf("%d\t", a[i]);
        }
        printf("\n");
}
void print_stack(struct node_t *head)
{
        struct node_t *tmp = head;
        printf("Stack:\t");
        while(tmp) {
                printf("%d\t", tmp -> data);
                tmp = tmp -> next;
        }
        printf("\n");
}

