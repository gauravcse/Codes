#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* heightBalanced(int *arr,int i,int j) {
	if(i > j)
		return NULL;
	else if(i == j) {
		node* ptr = (node*)malloc(sizeof(node));
		ptr->left = ptr->right = NULL;
		ptr->data = arr[i];
		return ptr;
	}
	else {
		int mid = (i + j) / 2;
		node *leftSub = heightBalanced(arr,i,mid - 1);
		node *rightSub = heightBalanced(arr,mid + 1,j);
		node* ptr = (node*)malloc(sizeof(node));
		ptr->data = arr[mid];
		ptr->left = leftSub;
		ptr->right = rightSub;
		return ptr;
	}
}

node* binary_tree(int* ar, int len) {
	node *root = heightBalanced(ar,0,len - 1);
}

void postorder(node* p, int indent=0) {
    if(p != NULL) {
        if(p->left) postorder(p->left, indent+4);
        if(p->right) postorder(p->right, indent+4);
        if (indent) {
            cout << setw(indent) << ' ';
        }
        cout<< p->data << "\n ";
    }
}

int main(void) {
	int arr[] = {3,5,7,9,11,13,15,17,21,23};
	node* root = binary_tree(arr,9);
	postorder(root);
	//cout<<root->right->right->data;
}
