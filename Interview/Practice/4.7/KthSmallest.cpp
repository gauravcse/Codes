#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node {
	int data;
	int le;	// LEFT ELEMENTS
	struct node* left,*right;
}bst;

void insert(bst **root,int data,int park = 0) { 
	if(*root == NULL) {
		bst *node = (bst*)malloc(sizeof(bst));
		node->data = data;
		node->left = node->right = NULL;
		node->le = park;
		*root = node;
	}
	else if((*root)->data > data) {
		(*root)->le += 1;
		int p =(*root)->le;
		insert(&((*root)->left),data,p - 1);
	}
	else {
		int p =(*root)->le;
		insert(&((*root)->right),data,p + 1);
	}
		
}

int kthSmallest(bst *root,int k) {
	if(root->le == k)
		return root->data;
	else if(root->le < k)
		return kthSmallest(root->right,k);
	else
		return kthSmallest(root->left,k);
}

void inorder(bst* root) {
	if(root == NULL) {
		return;
	}
	else {
		inorder(root->left);
		cout<<root->data<<"->"<<root->le<<"\t";
		inorder(root->right);
	}
}


int main(void) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = 10;
	branch->left = branch->right = NULL;
	branch->le = 1;
	insert(&branch,3);
	insert(&branch,11);
	insert(&branch,7);
	insert(&branch,13);
	insert(&branch,8);
	//cout<<"2nd Smallest : "<<kthSmallest(branch,2);
	inorder(branch);
}
