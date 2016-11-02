#include<iostream>
#include<cstdlib>
#include<stack>
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

bool isPalin(node **head) {
	stack<int> value;
	node *ptr = *head;
	while(ptr != NULL) {
		value.push(ptr->data);
		ptr = ptr->next;
	}
	ptr = *head;
	while(!value.empty() && value.top() == ptr->data) {
		ptr = ptr->next;
		value.pop();
	}
	if(!value.empty())
		return false;
	else
		return true;
}


int main(void) {
	node* head = (node*)malloc(sizeof(node));
	head->data = 2;
	head->next = NULL;
	//addNode(&head,1);
	addNode(&head,2);
	addNode(&head,4);
	addNode(&head,2);
	addNode(&head,2);
	cout<<isPalin(&head)<<endl;
	//addNode(&head,14);
	//head->next->next->next = head->next->next;
	//printList(&head);
	
}
