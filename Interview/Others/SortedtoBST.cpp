#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int val;
	struct node *l,*r;
};

struct node* newNode(int val) {
	struct node* ptr = (node*) malloc(sizeof(node));
	ptr->val = val;
	ptr->l = ptr->r = NULL;
	return ptr;
}

void arraytoBst(int arr[],int left,int right,struct node** root) {
	if(left > right) {
		return ;
	}
	else if(left == right) {
		*root = newNode(arr[left]);
	}
	else {
		int mid = (left + right)/2;
		*root = newNode(arr[mid]);
		arraytoBst(arr,left,mid-1,&((*root)->l));
		arraytoBst(arr,mid+1,right,&((*root)->r));
	}
}

void printPreorder(struct node* root) {
     if (root == NULL)
          return;
 	printf("%d ", root->val);
    printPreorder(root->l);
    printPreorder(root->r);
}

int main(void) {
	int array[] = {2,3,4,5,6,7,8,9};
	struct node* root = newNode(0);
	arraytoBst(array,0,8,&root);
	printPreorder(root);
}
