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

bool isLeaf(bst *root) {
	if(root->right == NULL && root->left == NULL)
		return true;
	else
		return false;
}

bst *leaf = NULL;

void postOrder(bst *root) {
	if(root == NULL)
		return;
	else  {
		if(isLeaf(root) && leaf == NULL) {
			leaf = (bst*)malloc(sizeof(bst));
			leaf = root;
			//cout<<"HE"<<root->data<<" "<<leaf->data<<endl;
		}
		else if(isLeaf(root) && leaf != NULL) {
			leaf->right = root;
			leaf = root;
			//cout<<"SHE"<<root->data<<"  "<<leaf->data<<endl;
		}
		postOrder(root->left);
		postOrder(root->right);
	}
}

int main(void) {
	bst* branch = (bst*)malloc(sizeof(bst));
	branch->data = 6;
	branch->left = branch->right = NULL;
	insert(&branch,8);
	insert(&branch,4);
	insert(&branch,12);
	insert(&branch,10);
	insert(&branch,1);
	insert(&branch,3);
	//insert(&branch,25);
	//assignLevel(branch,1);
	//boundaryTraverse(branch);
	postOrder(branch);
	cout<<branch->left->left->right->data<<" "<<branch->left->left->data<<branch->left->left->right->right->data;
	
}
