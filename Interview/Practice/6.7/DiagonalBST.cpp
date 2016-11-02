#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node {
	int data;
	int diag;
	struct node* left,*right;
}bst;

void insert(bst** root,int val) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = val;
	branch->left = branch->right = NULL;
	bst *ptr = *root,*cur = NULL;
	while(1) {
		cur = ptr;
		int l = 0;
		if(ptr->data > val) {
			ptr = ptr->left;
			l = 0;
		}
		else if (ptr->data < val) {
			ptr = ptr->right;
			l = 1;
		}
		if(ptr == NULL) {
			if(l)
				cur->right = branch;
			else
				cur->left = branch;
			break;
		}
	}
}

void preorder(bst *root,int diag) {
	if(root ==  NULL)
		return;
	else {
		root->diag = diag;
		preorder(root->left,diag + 1);
		preorder(root->right,diag);
	}
}

void inorder(bst *root) {
	if(root ==  NULL)
		return;
	else {
		inorder(root->left);
		cout<<root->data<<" "<<root->diag<<endl;
		inorder(root->right);
	}
}


int main(void) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = 9;
	branch->left = branch->right = NULL;
	insert(&branch,3);
	insert(&branch,11);
	insert(&branch,7);
	insert(&branch,13);
	insert(&branch,10);
	insert(&branch,4);
	preorder(branch,1);
	inorder(branch);
}
