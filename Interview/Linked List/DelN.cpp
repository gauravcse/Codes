#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;
void printList(node**) ;

void addNode(node **head,int val) {
	//cout<<"threr"<<endl;
	node *ptr = *head;
	node *cur = (node*)malloc(sizeof(node));
	cur->data = val;
	cur->next = NULL;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = cur;
	//printList(head);
}

void printList(node **head) {
	node* ptr = *head;
	while(ptr != NULL) {
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<endl;
}

void delNth(node **ptr) {
	if((*ptr)->next == NULL) {
		*ptr=NULL;
	}
	else {
		node *cur = (*ptr)->next;
		//node *cur1 = (*ptr)->next->next;
		(*ptr)->next = cur->next;
		(*ptr)->data = cur->data;
		free (cur);
	}
	//printList()
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 2;
	head->next = NULL;
	addNode(&head,1);
	addNode(&head,4);
	addNode(&head,1);
	addNode(&head,12);
	printList(&head);
	delNth(&(head));
	printList(&head);
	delNth(&(head->next));
	printList(&(head));
}
