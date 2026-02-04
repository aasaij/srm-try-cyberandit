//Program to demonstrate Stack operations
#include <stdio.h>
#include <stdlib.h>
//typedef enum boolean {false, true} boolean;
typedef enum boolean {true=1,false=0} boolean;
typedef struct Book{
	int id;
	char title[30];
	double price;
}book;
typedef struct Stack{
	//to store the capacity of stack
	int capacity;
	//to store the actual size of the stack
	int size;
	//to store the address where the stack elements are stored
	book *books;
}stack;

stack* createStack(int max){
	stack *st = (stack*)malloc(sizeof(stack));
	st->capacity = max;
	st->size = -1;
	st->books = (book*)malloc(sizeof(book)*max);
	return st;
}
boolean isEmpty(stack *st){
//	if (st->size == -1)
//		return true;
//	return false;
	return	(st->size == -1);
}
boolean isFull(stack *st) {
	return st->size == st->capacity-1;
}
boolean push(stack *st, book b){
	if (isFull(st))
		return false;
//	st->size++;
//	st->books[st->size] = b;
	st->books[++st->size] = b;
	return true;
}
book* pop(stack *st){
	if (isEmpty(st))	
		return NULL;
	return &st->books[(st->size)--];
}
book* peek(stack *st){
	if (isEmpty(st))	
		return NULL;
	return &st->books[st->size];
}
int stackSize(stack* st){
	return st->size+1;
}
void printMenu(){
	printf("\nStack operations demo\n");
	printf("*********************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Stack Size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}
book getBook(){
	book b;
	printf("Book Id    : ");
	scanf("%d", &b.id);
	printf("Book Title : ");
	scanf("\n%[^\n]s", b.title);
	printf("Book Price : ");
	scanf("%lf", &b.price);
	return b;
}
void printBook(book b){
	printf("Book Id    : %d\n", b.id);
	printf("Book Title : %s\n", b.title);
	printf("Book Price : %.2lf\n", b.price);	
}


int main(){
	int sSize;
	stack *myStack;	
	scanf("%d", &sSize);
	myStack = createStack(sSize);
	while(true){
		int choice;
		printMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (!isFull(myStack)){
					push(myStack, getBook());
					printf("Pushed..\n");
				}
				else
					printf("Stack overflow\n");
				break;
			case 2:{
				book *b = pop(myStack);
				if (b){
					printBook(*b);
				}
				else
					printf("Stack is empty\n");
				break;
			}
			case 3:{
				book *b = peek(myStack);
				if (b){
					printBook(*b);
				}
				else
					printf("Stack is empty\n");
				break;
			}
			case 4:
				printf("Stack Actual Size : %d\n", stackSize(myStack));
				break;
			default:
				printf("Thank you so much for being very interactive in the class!\n");
				return 0; // exit(0)
		}
	}	
	return 0;
}