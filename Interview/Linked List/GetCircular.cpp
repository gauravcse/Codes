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

bool checkCircular(node **head) {
	node *ptr = (*head)->next;
	while(ptr != NULL && ptr != *head) {
		ptr = ptr->next;
	}
	return (ptr == *head);
}


int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 20;
	head->next = NULL;
	//addNode(&head,1);
	addNode(&head,4);
	addNode(&head,15);
	addNode(&head,10);
	//head->next->next->next = head;
	cout<<"Is Circular : "<<checkCircular(&head);
}
