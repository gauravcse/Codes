#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node {
	int data;
	int level;
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

void inorder(bst* root) {
	if(root == NULL) {
		return;
	}
	else {
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void mirrorTree(bst *root) {
	if(root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	}
	else {
		bst *temp1 = root->left;
		bst *temp2 = root->right;
		root->right = temp1;
		root->left = temp2;
		mirrorTree(temp1);
		mirrorTree(temp2);
	}
}

int main(void) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = 10;
	branch->left = branch->right = NULL;
	insert(&branch,3);
	insert(&branch,11);
	insert(&branch,7);
	insert(&branch,13);
	insert(&branch,8);
	insert(&branch,15);
	mirrorTree(branch);
	inorder(branch);
	
}
