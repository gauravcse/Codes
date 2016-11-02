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
		cout<<root->data<<"->"<<root->level<<"\t";
		inorder(root->right);
	}
}


void printLeftSubtree(bst *root) {
	if(root->left == NULL && root->right == NULL)
		return;
	else {
		cout<<root->data<<" ";
		if(root->left != NULL)
			printLeftSubtree(root->left);
		else
			printLeftSubtree(root->right);
	}
	
}

void postOrder(bst *root) {
	if(root->left == NULL && root->right == NULL) {
		cout<<root->data<<" ";
	}
	else {
		if(root->left != NULL)
			postOrder(root->left);
		if(root->right != NULL)
			postOrder(root->right);
	}
}

void printRightSubtree(bst *root) {
	if(root->left == NULL && root->right == NULL) {
		return ;
	}
	else {
		if(root->right != NULL)
			printRightSubtree(root->right);
		else
			printRightSubtree(root->left);
		cout<<root->data<<" ";
	}
}


void boundaryTraverse(bst *root) {
	printLeftSubtree(root);
	postOrder(root);
	printRightSubtree(root->right);
	cout<<endl;
}

int main(void) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = 20;
	branch->left = branch->right = NULL;
	insert(&branch,8);
	insert(&branch,4);
	insert(&branch,12);
	insert(&branch,10);
	insert(&branch,14);
	insert(&branch,22);
	insert(&branch,25);
	//assignLevel(branch,1);
	boundaryTraverse(branch);
	cout<<endl;
	
}
