//program to implement queue using linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
	int data;
	struct Node *nxt;
}node;
typedef struct Queue{
	node* front;
	node* rear;
}queue;
node* createNode(int data){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->nxt = NULL;
	return newNode;
}
queue* createQueue(){
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->front = NULL;
	temp->rear = NULL;
	return temp;
}

queue* enqueue(queue *q, int data){
	node* newNode = createNode(data);
	if (q->front == NULL) {
		q->front = q->rear = newNode;
	}
	else{
		q->rear->nxt = newNode;
		q->rear =newNode;
	}
	return q;	
}
bool isEmpty(queue *q){
	return q->front == NULL && q->rear == NULL;
}

queue *dequeue(queue *q){
	if (!isEmpty(q)){
		node* temp = q->front;
		if(q->front==q->rear){
			q->front = q->rear = NULL;
		}
		else{
			q->front = temp->nxt;
		}
		free(temp);
		return q;		
	}
	return NULL;
}
int front(queue *q){
	if (!isEmpty(q))
		return q->front->data;
	return 0;	
}

int main(){
	queue *myQueue = createQueue();
	enqueue(myQueue, 10);
	enqueue(myQueue, 20);
	printf("%d", front(myQueue));
	return 0;
}