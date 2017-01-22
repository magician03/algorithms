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

void delete(struct node** start, int val){

	struct node* begin = *start;
	
	while(begin->right != NULL) {

		if(begin->right->data == val){
			
			begin->right = begin->right->right;
			struct node* temp = begin->right;
			temp->left = begin;
		
		}
		
		begin = begin->right;

	}

}
//main function
int main(void){

	struct node* start = (struct node*)malloc(sizeof(struct node));;
	struct node* end = NULL;
	
	start->right = NULL;
	start->left = NULL;
	start->data = -1;
	int i = 0;

	for(i = 0 ; i < 10; i++){
		insert_end(&start, i*i);
		//insert_end(&end, i*i - 1);
	}
	start = start->right;

	
	//printf("%d", start->data + start->right->data);
	delete(&start, 16);
	
	//printf("%d", start->right->data);
	//start = start->right;
	for(i = 0; i < 10; i++){
		printf("%d->", start->data);
		start = start->right;
	}

	return 0;
}

//user defined functions implementation


