//Program to demonstrate circular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *nxt;
}node;
node* createNode(int data){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->nxt = NULL;
	return temp;
}
node* addFirst(node* tail, int data){
	node* newNode = createNode(data);
	if (!tail){
		//list is empty
		newNode->nxt = newNode;
		tail = newNode;
	}
	else{
		newNode->nxt = tail->nxt;
		tail->nxt = newNode;
	}
	return tail;
}
node* addLast(node* tail, int data){
	node* newNode = createNode(data);
	if (!tail){
		//list is empty
		newNode->nxt = newNode;
		tail = newNode;
	}
	else{
		newNode->nxt = tail->nxt;
		tail->nxt = newNode;
		tail = newNode;
	}
	return tail;	
}
void printList(node* tail){
	if (tail){
		printf("\n[");
		node* temp;
		for (temp=tail->nxt; temp!=tail; temp=temp->nxt)
			printf("%d,", temp->data);
		printf("%d]", tail->data);
	}
	else
		printf("\n[]");
}
node* deleteFirst(node* tail){
	if (tail){
		//list is not empty
		if (tail->nxt == tail){
			free(tail);
			return NULL;
		}
		node* temp = tail->nxt;
		tail->nxt = temp->nxt;
		free(temp);
	}
	return tail;
}
node* deleteLast(node* tail){
	if (tail){
		if (tail->nxt==tail){
			free(tail);
			return NULL;
		}
		node* temp;
		for (temp=tail->nxt; temp->nxt!=tail; temp=temp->nxt);
		node* temp1 = tail;
		temp->nxt = tail->nxt;
		tail = temp;
		free(temp1);
	}
	return tail;
}

int main(){
	node* tail = NULL;
	printList(tail);
	tail = addFirst(tail, 10);
	tail = addFirst(tail, 20);
	printList(tail);
	tail = addLast(tail, 30);
	printList(tail);
	tail = deleteFirst(tail);
	printList(tail);
	tail = deleteLast(tail);
	printList(tail);
}