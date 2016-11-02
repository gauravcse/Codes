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

void getNth(node **head,int n) {
	node* ptr = *head;
	for(int i = 0; i < n; i++) {
		ptr = ptr->next;
	}
	cout<<n<<"th Node : "<<ptr->data<<endl;
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	addNode(&head,10);
	addNode(&head,30);
	addNode(&head,14);
	printList(&head);
	getNth(&head,3);
}
