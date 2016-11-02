#include<iostream>
#include<queue>
#include<cstdlib>
#include<vector>
#include<map>

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

int width(bst *root ) {
	queue<pair<bst*,int> > part;
	part.push(make_pair(root,1));
	map<int,int> count;
	map<int,int>::iterator it;
	while(!part.empty()) {
		bst *leaf = part.front().first;
		int lev = part.front().second;
		if(leaf->right != NULL)
			part.push(make_pair(leaf->right,lev + 1));
		if(leaf->left != NULL)
			part.push(make_pair(leaf->left,lev + 1));
		it = count.find(lev);
		if(it != count.end()) {
			count[lev] = count[lev] + 1;
		}
		else {
			count[lev] = 1;
		}
		part.pop();
	}
	int mx = 0;
	for(it = count.begin(); it != count.end(); it++) {
		if(it->second > mx)
			mx = it->second;
	}
	return mx;
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
	insert(&branch,1);
	//preorder(branch,1);
	//inorder(branch);
	cout<<"Max Width : "<<width(branch)<<endl;
}
