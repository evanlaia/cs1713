#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* number of nodes to have in linked list */
#define N 20

/* DO NOT CHANGE
 * struct for a single node in a linked list.  info contains the data stored in this node.
 * next contains a pointer to the node with the next piece of data.
 */
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

node *inserthead(node *head, int data);

/*
 * copyLinkedList is recursive function.  It makes a copy of a singly linked list
 * that is provided as a parameter and returns a pointer to the new linked list.
 *
 * (don't call inserthead but feel free to use code from it)
 */

node *copyLinkedList(node *head){

    if (head == NULL) {
        return NULL;
    }
    node* copy = malloc(sizeof(struct node));  
    copy->info = head->info;
    copy->next = copyLinkedList(head->next);
    return copy;

}

/*
 * sortedInsert is recursive function.  It inserts a new node containing the variable data
 * into a sorted singly linked list that is provided as a parameter.  The data in the linked
 * should be in increasing order.
 *
 * It returns the pointer that the previous node in the linked list should point to.
 *
 * Feel free to call inserthead in your function.
 */
node *sortedInsert(node *head, int data){
    if (head == NULL) {
        return inserthead(head, data);
    } else if (data < head->info) {
        return inserthead(head, data);
    }else if (data >= head->info) {
        head->next = sortedInsert(head->next, data);
    }
    return head;
}


/* DO NOT CHANGE
 *
 * printLinkedList is recursive function.  It prints all of the data in a singly linked list
 * that is provided as a parameter.
 */
void printLinkedList(node *head){
    if(head == NULL)
        printf("\n");
    else
    {
        printf("%d ",head->info);
        printLinkedList(head->next);
    }
}

/* DO NOT CHANGE
 *
 * modifyLinkedList is recursive function.  It adds the parameter factor to all of the data in a singly linked list
 * that is provided as a parameter.
 */
void modifyLinkedList(node *head, int factor){
    if(head != NULL)
    {
        head->info+=factor;
        modifyLinkedList(head->next,factor);
    }
}


/* DO NOT CHANGE
 *
 * freeLinkedList is recursive function.  It frees all of the nodes in a singly linked list
 * that is provided as a parameter.
 */
void freeLinkedList(node *head){
    if(head != NULL)
    {
        freeLinkedList(head->next);
        free(head);
    }
}


/* DO NOT CHANGE
 *
 * insertHead creates a new node in a singly linked list inserts
 * a node containing data onto the front of the provided list that is
 * provided as a parameter and returns a pointer to the new node.
 */
node *inserthead(node *head, int data)
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->info = data;
    ptr->next = head;
    return ptr;
}

/* DO NOT CHANGE
 *
 * Test code.
 */
int main(void)
{
    node *oldList=NULL, *newList=NULL, *sortList=NULL;
    int i;

    /* seed random number generator */
    srand(time(NULL));

    /* Create a linked list */
    for(i=0; i<=N; i++){
        oldList = inserthead(oldList, 10*(N-i));
    }

    /* Print this linked list */
    printf("Old linked list: \n");
    printLinkedList(oldList);
    printf("\n");

    /* Copy linked list to a new one */
    newList = copyLinkedList(oldList);

    /* Print copied linked list */
    printf("Copied linked list: \n");
    printLinkedList(newList);
    printf("\n");

    /* Update values in linked lists */
    modifyLinkedList(oldList,-1);
    modifyLinkedList(newList,1);

    /* Print updated old linked list */
    printf("Numbers should be 1 less: \n");
    printLinkedList(oldList);
    printf("\n");

    /* Print updated new linked list */
    printf("Numbers should be 1 more: \n");
    printLinkedList(newList);
    printf("\n");

    /* Create a sorted linked list */
    for(i=0; i<=N; i++){
        sortList = sortedInsert(sortList, rand()%N);
    }

    /* Print updated old linked list */
    printf("Numbers should be in sorted order: \n");
    printLinkedList(sortList);
    printf("\n");

    /* Free created lists */
    freeLinkedList(oldList);
    freeLinkedList(newList);
    freeLinkedList(sortList);

    return 0;
}