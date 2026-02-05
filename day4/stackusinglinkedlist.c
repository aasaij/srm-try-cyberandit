//Program to implement stack using Linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *nxt;
}node;
typedef struct Stack{
	int size;
	node* top;
}stack;
//function proto-type
bool isEmpty(stack*);

node* createNode(int data){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->nxt = NULL;
	return temp;
}
stack* createStack(){
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->size = 0;
	temp->top = NULL;
	return temp;
}
stack* push(stack* st, int data){
	node* newNode = createNode(data);
	newNode->nxt = st->top;
	st->top  = newNode;
	st->size++;
	return st;
}
stack* pop(stack* st, int *element){
	if (!isEmpty(st)){
		*element = st->top->data;
		node* temp = st->top;
		st->top = temp->nxt;
		st->size--;
		free(temp);
	}
	return st;
}
bool isEmpty(stack *st){
	return st->top == NULL;
}
int stackSize(stack* st){
	return st->size;
}

int main(){
	stack *myStack = createStack();
	int deletedElement;
	myStack = push(myStack, 10);
	myStack = push(myStack, 20);
	myStack = push(myStack, 30);
	myStack = pop(myStack, &deletedElement);
	printf("\nStack Size : %d\n", stackSize(myStack));
	printf("Removed Element : %d\n", deletedElement);
	
	return 0;
}