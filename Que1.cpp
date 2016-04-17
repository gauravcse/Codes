#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define LOOP1 for(int j=0;j<n;j++)
#define TEST while(t--)

struct node {
	int data;
	struct node *next;
};

struct node* create(int key) {
	struct node* ptr=(node*)malloc(sizeof(node));
	ptr->data=key;
	ptr->next=NULL;
}

struct node* begin(struct node* head,int value) {
	struct node *ptr=create(value);
	ptr->next=head;
	head=ptr;
	return head;
}

struct node* middle(struct node* head,int value,int pos) {
	struct node *ptr=create(value);
	struct node *temp=head;
	while(pos--) {
		temp=temp->next;
	}
	if(temp==NULL) {
		head->next=ptr;
	}
	else {
		ptr->next=temp->next;
		temp->next=ptr;
	}
	return head;
}

struct node* end(struct node* head,int value) {
	struct node* ptr=create(value);
	struct node *temp=head;
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=ptr;
	return head;
}

int length(struct node *head) {
	struct node *temp=head;
	int l=0;
	while(temp!=NULL) {
		temp=temp->next;
		l++;
	}
	return l;
}

int cmpfunc(const void *a,const void *b) {
	return (*(int*)b-*(int*)a);
}

int main(void) {
	int t;
	scanf("%d",&t);
	TEST {
		int n;
		scanf("%d",&n);
		int arr[n];
		int sorted[n];
		int rank[n];
		LOOP {
			scanf("%d",&arr[i]);
			sorted[i]=arr[i];
		}
		LOOP {
			scanf("%d",&rank[i]);
		}
		qsort(sorted,n,sizeof(int),cmpfunc);

		
		struct node *head;
		
		LOOP {
			int num=sorted[i];
			if(i==0) {
				head=create(num);
				continue;
			}
			int pos=0;
			LOOP1 {
				if(num==arr[j]){
					pos=j;
					break;
				}
			}
			int rnk=rank[pos];
			int l=length(head);
			if(rnk>=l) {
				head=end(head,num);
			}
			else {
				if(rnk==0) {
					head=begin(head,num);
						continue;
				}
				else
					head=middle(head,num,rnk-1);
			}
		}
		struct node *temp=head;
		while(temp!=NULL) {
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
