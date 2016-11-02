#include<iostream>
#include<map>

using namespace std;

typedef struct node {
	int data;
	struct node *left,*right;
}Node;

map<int,int> d;

int setDistance(node *root) {
	cout<<"V ";
	if(root == NULL)
		return 0 ;
	int dis = max(setDistance(root->left) +1,setDistance(root->left) +1);
	cout<<dis<<" ";
	if(d.find(dis) != d.end()) {
		d[dis] = 1;
	}
	else {
		d[dis] = d[dis] + 1;
	}
	return 0;
}

Node* newNode(int key) {
	Node* node = new Node;
	node->data = key;
	node->left = node->right = NULL;
	return (node);
}


int main()
{
	// Let us create binary tree given in the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	cout << "Nodes at distance 2 are: ";
	map<int,int> m;
	setDistance(root);
	for(map<int,int>::iterator it = d.begin(); it != d.end(); it++) {
		cout<<it->first<<"\t"<<it->second<<" "<<endl;
	}
	return 0;
}

