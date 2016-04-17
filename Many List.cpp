#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=1;i<=n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

typedef struct node {
	int data;
	struct node* next;
}node;

node *insert(node *head,int x) {
	node *ptr=(node*)malloc(sizeof(node));
	ptr->data=x;
	ptr->next=NULL;
	if(head->next==NULL){
		head->next=ptr;
		head->data++;
		return head;
	}
	node *newhead=head->next;
	node *temp=head;
	while(newhead->next!=NULL && (newhead->data)<(ptr->data)){
		temp=temp->next;
		newhead=newhead->next;
	}
	if(newhead->data==ptr->data) {
		return head;
	}
	else if(newhead->next==NULL) {
		newhead->next=ptr;
		head->data++;
		return head;
	}
	else {
		temp->next=ptr;
		ptr->next=newhead;
		head->data++;
		return head;
	}
}

int main(void) {
	int n,m;
	scanf("%d %d",&n,&m);
	node* arr[n+1];
	LOOP {
		arr[i]=(node*)malloc(sizeof(node));
		arr[i]->data=0;
		arr[i]->next=NULL;
	}
	//int flag=0;
	while(m--) {
		int query;
		scanf("%d",&query);
		if(query==0) {
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			for(int i=l;i<=r;i++) {
				arr[i]=insert(arr[i],x);
			}
		}
		else if(query==1)  {
			int size;
			scanf("%d",&size);
			printf("%d\n",arr[size]->data);
		}
	}
}
