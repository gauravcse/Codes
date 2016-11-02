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

int height(bst* root) {
	if(root == NULL) {
		return 0;
	}
	else {
		return max(height(root->left) + 1, height(root->right) + 1);
	}
}

void leavesProduct(bst *branch,int *arr) {
	if(branch ==  NULL) {
		return ;
	}
	else if(branch->left == NULL && branch->right == NULL) {
		arr[branch->level] += branch->data;
	}
	leavesProduct(branch->left,arr);
	leavesProduct(branch->right,arr);
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
	inorder(branch);
	cout<<endl;
	cout<<"HEIGHT : "<<height(branch)<<endl;
	int h = height(branch);
	int arr[100] = {0};
	leavesProduct(branch,arr);
	int product = 1;
	for (int i = 1 ; i <= h; i++) {
    	cout << arr[i]<<" ";
    	product *= (arr[i]==0 ? !arr[i] : arr[i]);
    }
    cout<<endl<<"RESULT : "<<product<<endl;
}
