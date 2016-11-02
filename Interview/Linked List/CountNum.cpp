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

int countN(node **head,int val) {
	if((*head) == NULL)
		return 0;
	else {
		if((*head)->data == val)
			return countN(&((*head)->next),val) + 1;
		else
			return countN(&((*head)->next),val);
	}
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	addNode(&head,1);
	addNode(&head,4);
	addNode(&head,1);
	addNode(&head,12);
	addNode(&head,14);
	addNode(&head,1);
	printList(&head);
	cout<<"OCCURRED : "<<countN(&head,1)<<endl;
	//printList(&head);
	//cout<<head->data<<" "<<head->next->data;
}
