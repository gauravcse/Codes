#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* create() {
	struct Node* ptr=(Node*)malloc(sizeof(Node));
	return ptr;
}
struct Node* initialize(int info,struct Node* ptr) {
	ptr->data=info;
	ptr->next=NULL;
	return ptr;
}

void print_list(struct Node* head) {
	struct Node* ptr;
	ptr=head;
	if(head==NULL) {
		printf("Empty Linked List");
	    return;	
	}
	else {
		while(ptr->next!=NULL) {
		    printf("%d -> ",ptr->data);
		    ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}

struct Node* insert_head(struct Node* head,struct Node* ptr) {
	ptr->next=head;
	head=ptr;
	return head;
}

struct Node* insert_tail(struct Node* head,struct Node* ptr) {
	struct Node* temp;
	temp=head;
	if(temp==NULL) {
		temp=ptr;
		head=temp;
		return head;
	}
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=ptr;
	return head;
}

struct Node* insert_mid(struct Node* head,struct Node* ptr) {
	if(head->data > ptr->data) {
		return insert_head(head,ptr);
	}
	int pos=1;
    struct Node* temp;
    temp=head;
    while(temp!=NULL) {
    	if(temp->data < ptr->data) 
    	    pos++;
		else 
			break;
		temp=temp->next;
	}
	if(temp==NULL)
	    return insert_tail(head,ptr);
	else {
		struct Node* t;
		t=head;
		for(int i=1;i<pos-1;i++) {
			t=t->next;
		}
		t->next=ptr;
		ptr->next=temp;
		return head;
	}

}

struct Node* reverse_list(struct Node* head) {
	struct Node* temp;
	struct Node* previous=NULL;
	while(head!=NULL) {
		temp=head->next;
		head->next=previous;
		previous=head;
		head=temp;
	}
	return previous;
}

struct Node* delete_element(struct Node* head,int value) {
	if(head==NULL) {
		printf("The Linked List is Empty\n");
		return head;
	}
	else if(head->data==value) {
		head=head->next;
		return head;
	}
	else {
		struct Node* ptr;
		ptr=head;
		while(ptr->next!=NULL && ptr->next->data!=value) {
			ptr=ptr->next;
		}
		if(ptr->next->data==value) {
			ptr->next=ptr->next->next;
			return head;
		}
	}
}

int main(void) {
	struct Node* head; // Head of the linked list
	struct Node* temp;
	printf("Enter the length of the linked list to be created : ");
	int number;
	scanf("%d",&number);
	if(number==0) {
		printf("NULL\n");
		exit(0);
	}
	else {
		head=create();
		printf("Enter the element at the %dth position :",number);
		int info;
		scanf("%d",&info);
		head=initialize(info,head);
		temp=head;
		printf("\n");
	}
	while(--number) {
		struct Node* ptr;
		ptr=create();
		printf("Enter the element at the %dth position :",number);
		int info;
		scanf("%d",&info);
		ptr=initialize(info,ptr);
		temp->next=ptr;
		temp=ptr;
		printf("\n");
	}
	print_list(head);
	
	// Add to the head of the List
	printf("\nAdd to the head of the List \n");
	struct Node* newptr;
	newptr=create();
	int info;
	printf("Enter the data of the elememt to be inserted at the head : ");
	scanf("%d",&info);
	newptr=initialize(info,newptr);
	head=insert_head(head,newptr);
	
	print_list(head);
	
	// Add to the tail of the list 
	printf("\nAdd to the tail of the List \n");
	newptr=create();
	printf("Enter the data of the elememt to be inserted at the tail : ");
	scanf("%d",&info);
	newptr=initialize(info,newptr);
	head=insert_tail(head,newptr);
	
	print_list(head);
	
	// Insert in the middle of the list
	printf("\nInsert in the middle of the list\n");
	newptr=create();
	printf("\nEnter the data of the element to be inserted : ");
	scanf("%d",&info);
	newptr=initialize(info,newptr);
	head=insert_mid(head,newptr);
	
	print_list(head);
	
	// Reverse the List and return the head
	printf("\n");
	struct Node* header;
	header=reverse_list(head);

	print_list(header);
	
	//Search for an Element
	printf("\n");
	int element;
	printf("Enter the Value to be searched : ");
	scanf("%d",&element);
	struct Node* newhead;
	newhead=delete_element(header,element);
	
	print_list(newhead);
}
