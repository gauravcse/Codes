#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct node {
	int value;
	struct node *next;
};
int main() {
	struct node *root;
	root=(struct node*)(malloc(1*sizeof(struct node)));
	root->next=NULL;
	root->value=15;
	struct node *conductor;
	conductor=root;
	if(conductor!=0){
		while(conductor->next!=0){
			conductor=conductor->next;
		}
	}
}
