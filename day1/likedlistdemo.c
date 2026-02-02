//Program to demonstrate linked list
#include <stdio.h>
#include <stdlib.h>
//declaration of node
typedef struct Node{
	char element; // 1	
	struct Node *nxt; // 8
}node;

//void* malloc(size_t size);
//void* calloc(size_t n, size_t size_of_block);

node* createNode(char data){
	node* temp =(node*) malloc(sizeof(node));
	temp->element = data;
	temp->nxt = NULL;
	return temp;
}

node* addFirst(node* list, char data){
	node* newNode = createNode(data);
	newNode->nxt =list;
	list = newNode;
	return list;
}

node* addLast(node* list, char data){
	node* newNode = createNode(data);
	node *temp;
	for (temp = list;temp->nxt; temp = temp->nxt);	
	temp->nxt = newNode;
	return list;	
}
node* addAt(node* list, int loc, char data){
	if (loc == 0 || loc == 1)
		return addFirst(list, data);
	//checking whether the location is > 1
	if (loc > 1){
		//checking whether the list is empty
		if (!list)
			return addFirst(list, data);
		//checking whether list contains only one node			
		if (!list->nxt)
			return addLast(list, data);
		//the list contains more than one node
		node* temp= list;
		for (int i = 2; i<loc && temp->nxt; i++)
			temp = temp->nxt;
		node* newNode = createNode(data);
		newNode->nxt = temp->nxt;
		temp->nxt = newNode;
	}
	return list;
}
node* deleteFirst(node* list){	
	if (list){
		//list is not empty
		node* temp = list;
		list = temp->nxt;
		free(temp)	;
	}
	return list;
}
node* deleteLast(node* list){
	if (list){
		//list contains only one node
		if (!list->nxt){
			free(list);
			return NULL;
		}
		node* temp;
		for (temp = list; temp->nxt->nxt; temp = temp->nxt);
		free(temp->nxt);
		temp->nxt = NULL;
	}
	return list;
}
void printList(node* list){
	printf("\n[");
	node* temp;
	for (temp = list; temp->nxt; temp=temp->nxt)
		printf("'%c',", temp->element);
	printf("'%c']", temp->element)	;
}

int main(){
	node* root = NULL;
	root = addFirst(root, 'A');
	root = addLast(root, 'C');
	root = addAt(root, 2, 'B');
	root = addFirst(root, 'F');
	root = addAt(root,1, 'J');
	root = addAt(root, 10,'Z');
	printList(root);
	root = deleteFirst(root);
	printList(root);
	root = deleteLast(root);
	printList(root);
	return 0;
}