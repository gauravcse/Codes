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


void assignLevel(bst* root,int level) {
	if(root == NULL) {
		return ;
	}
	else {
		root->level = level;
		assignLevel(root->right,level + 1);
		assignLevel(root->left, level + 1);
	}
}


bool isBalanced(bst *root) {
	if (root->left == NULL && root->right == NULL)
		return true;
	else if(root->left == NULL && root->right != NULL) {
		if(root->right->left == NULL && root->right->right == NULL)
			return true;
		else
			return false;
	}
	else if(root->right == NULL && root->left != NULL) {
		if(root->left->left == NULL && root->left->right == NULL)
			return true;
		else
			return false;
	}
	else if(isBalanced(root->right) && isBalanced(root->left) && abs(root->left->level - root->right->level) <= 1) {
		//cout<<root->data<<" ";
		return true;		
	}

	else
		return false;
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
	assignLevel(branch,1);
	cout<<"HEIGHT BALANCED : "<<isBalanced(branch)<<endl;
}
