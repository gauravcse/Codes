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

void addList(node *list1,node *list2,node *add,int l1,int l2) {
	if(list1 == NULL && list2 == NULL)
		return;
	else if(list1 == NULL && list2 != NULL) {
		//node *ptr = 
	}
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 20;
	head->next = NULL;
	//addNode(&head,1);
	addNode(&head,4);
	addNode(&head,15);
	addNode(&head,10);
	printList(&head);
}
