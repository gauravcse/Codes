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

void lastNth(node **head,int n) {
	node *fast = *head;
	node *slow = *head;
	for(int i = 1; i < n; i++) {
		fast = fast->next;
	}
	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	cout<<"Data : "<<slow->data<<endl;
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 2;
	head->next = NULL;
	addNode(&head,1);
	addNode(&head,4);
	addNode(&head,5);
	addNode(&head,12);
	addNode(&head,14);
	printList(&head);
	lastNth(&head,6);
}
