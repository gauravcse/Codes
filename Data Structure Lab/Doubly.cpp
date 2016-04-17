#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	void* data;
	struct node *next;
	struct node *prev;
}node;

node *head,*last;

node *createnode() {
	node* ptr=(node*)malloc(sizeof(node));
	ptr->data=(char*)malloc(sizeof("Hello"));
	
	ptr->next=ptr->prev=NULL;
	return ptr;
}

node *insert_after_head(node *ptr,node *head) {
	if(head->next!=NULL) {
		ptr->next=head->next;
		head->next->prev=ptr;
		head->next=ptr;
		ptr->prev=head;
		return head;
	}
	else {
		head->next=ptr;
		ptr->prev=head;	
		return head;
	}
}

int main() {
	head=(node*)malloc(sizeof(node));
	head->data=(int*)12;
	head->next=NULL;
	head->prev=NULL;
	last=NULL;
	head=insert_after_head(createnode(),head);
	printf("%d   %d\n",head->data,head->next->data);
}
