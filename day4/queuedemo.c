//program to demonstrate queue using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Employee{
	int id;
	char name[30];
	double salary;
}employee;
typedef struct Queue{
	int capacity;
	int front;
	int rear;
	employee *employee;
}queue;

queue* createQueue(int size){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = size;
	temp->front = -1;
	temp->rear = -1;
	temp->employee = (employee*)malloc(sizeof(employee)*size);
	return temp;
}
bool isFull(queue* q){
	return q->rear+1 == q->capacity && q->front == 0 || q->rear+1 == q->front;
}
bool isEmpty(queue *q){
	return q->front == -1 && q->rear == -1;
}
bool enqueue(queue* q, employee emp){
	if(!isFull(q)){
		if (q->front==-1 ) q->front = 0;
		q->rear = (q->rear + 1 )% q->capacity;
		q->employee[q->rear] = emp;		
		return true;
	}
	return false;
}
employee* dequeue(queue *q){
	if (!isEmpty(q)){
		employee *e = (employee*)malloc(sizeof(employee));
		e = &q->employee[q->front];		
		if (q->front == q->rear){
			q->front = q->rear = -1;
		}
		else{
			q->front = (q->front+1)%q->capacity;			
		}
		return e;
	}
	return NULL;
}
employee* front(queue *q){
	if (!isEmpty(q)){
		employee *e = (employee*)malloc(sizeof(employee));
		e = &q->employee[q->front];		
		return e;
	}
	return NULL;
}

int main(){
	queue *myQueue = createQueue(3);
	employee e1 = {101, "Krishna", 1000000};
	employee e2 = {102, "Iswarya", 1500000};
	employee e3 = {103, "Dinesh", 2500000};
	enqueue(myQueue, e1);
	enqueue(myQueue, e2);
	if (enqueue(myQueue, e3))
		printf("Enqueued...\n");
	else
		printf("Queue is full!\n");
	e3 = *dequeue(myQueue);
	printf("%d %s %.2lf", e1.id, e3.name, e3.salary);
	return 0;
}