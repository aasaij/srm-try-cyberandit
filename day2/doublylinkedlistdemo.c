//Program to demonstrate doubly linked lsit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	struct Node *prev;
	char str[30];
	struct Node *nxt;
}node;

node* createNode(char element[]){
	node* temp =(node*) malloc(sizeof(node));
	strcpy(temp->str,element);
	temp->nxt = temp->prev = NULL;
	return temp;
}
node* addFirst(node* list, char str[]){
	node* newNode = createNode(str);
	if (list){
		//list is not empty
		newNode->nxt = list;
		list->prev = newNode;	
	}
	list = newNode;
	return list;	
}
node* addLast(node* list, char element[]){
	node* newNode = createNode(element);
	if (list){
		//list is not empty
		node* temp;
		for (temp = list; temp->nxt!=NULL; temp=temp->nxt);
		newNode->prev = temp;
		temp->nxt = newNode;
	}
	else //list is empty
		list = newNode;
	return list;
}
node* deleteFirst(node* list){
	if (list){
		//list is not empty
		node* temp = list;
		if (!list->nxt)
			//list contains only one node
			list = NULL;
		else{
			//list is having more than one node
			list = temp->nxt;
			list->prev = NULL;
		}
		free(temp);	
	}
	return list;
}
node* deleteLast(node* list){
	if (list){
		if (!list->nxt){
			node* temp  = list;
			list = NULL;
			free(temp);
		}
		else{
			node* temp;
			for (temp = list; temp->nxt->nxt;temp=temp->nxt);
			free(temp->nxt);
			temp->nxt = NULL;
		}
	}
	return list;
}
void printList(node* list){
	if (list){
		printf("Forward Traversal : ");
		printf("\n[");
		node* temp;
		for (temp = list; temp->nxt; temp = temp->nxt)
			printf("\"%s\",", temp->str);
		printf("\"%s\"]\n", temp->str);			
		printf("Reverse Traversal : ");
		printf("\n[");
		for (;temp->prev!=NULL; temp=temp->prev)
			printf("\"%s\",", temp->str);
		printf("\"%s\"]\n", temp->str);				
	}
	else
		printf("\n[]");
}

int main(){
	node* root = NULL;
	root = addFirst(root, "Dinesh");
	root = addFirst(root, "Krishna");
	root = addFirst(root, "Sachin");
	printList(root);
	root - addLast(root, "Chandraakanth");
	printList(root);
	root = deleteFirst(root);
	printList(root);
	root = deleteLast(root);
	printList(root);
	return 0;
}