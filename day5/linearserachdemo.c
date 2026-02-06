//Program to implement linear search algorithm
#include <stdio.h>
#include <string.h>
int linearSearch(int size, char names[size][20], char searchName[]){
	for (int i = 0; i<size; i++){
		if(strcmp(names[i],searchName)==0)
			return i;
	}
	return -1;
}

int main(){
	char nameList[][20]= {"Nowfal", "Chandrakanth", "Veera", "Yuvaraj", "Nithish", "Nafees"};
	char search[20];
	scanf("%s", search);
	int size = sizeof(nameList)/sizeof(nameList[0]);
	if (linearSearch(size, nameList, search)!=-1)
		printf("Found");
	else
		printf("Not Found");
	return 0;
}