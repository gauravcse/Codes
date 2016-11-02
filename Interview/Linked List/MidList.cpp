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

void midList(node **head) {
	node *slow = *head;
	node *fast = *head;
	int count = 0;
	while(fast->next != NULL ) {
		if(fast->next->next == NULL) {
			count += 1;
			fast = fast->next;
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
		count += 2;
	}
	if(count % 2 == 0)
		cout<<slow->data<<endl;
	else
		cout<<slow->data<<" And "<<slow->next->data<<endl;
}

int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 2;
	head->next = NULL;
	addNode(&head,1);
	addNode(&head,4);
	addNode(&head,1);
	addNode(&head,12);
	addNode(&head,14);
	printList(&head);
	midList(&head);
	
	//printList(&head);
}
