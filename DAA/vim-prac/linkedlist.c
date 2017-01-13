#include <stdio.h>
#include <stdlib.h>

//node struct
struct node{
	struct node* left;
	int data;
	struct node* right;
};
	


//user-defined functions
void insert_begin(struct node** start, int val){

	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = val;
	
	(*start)->left = newNode;
	newNode->right = *start;
	newNode->left = NULL;

	*start = newNode;

}

void insert_end(struct node** start, int val){

	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = val;

	struct node* begin = *start;

	while(begin->right != NULL)
		begin = begin->right;

	begin->right = newNode;
	newNode->left = begin;

}

//main function
int main(void){

	struct node* start = (struct node*)malloc(sizeof(struct node));;
	struct node* end = NULL;

	int i = 0;

	for(i = 0 ; i < 10; i++){
		insert_end(&start, i*i);
		//insert_end(&end, i*i - 1);
	}
	for(i = 0; i < 10; i++){
		printf("%d->", start->data);
		start = start->right;
	}

	return 0;
}

//user defined functions implementation


