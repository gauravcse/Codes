#include<iostream>
#include<cstdlib>
#include<cstring>
#define ALPHABET 26

using namespace std;

typedef struct node {
	struct node *list[ALPHABET];
	int visits ;
	bool isLeaf;
}node;

bool presentChar(int pos,node *root);
node* addChar(int pos,node *root,bool leaf = false)  ;
void addWord(char *str,node *root);

void addWord(char *str,node *root) {
	int len = strlen(str);
	for(int i = 0 ; i < len ; i++) {
		char ch = str[i];
		int pos = ch - 65;
		if( (i+1) != len )
			root = addChar(pos,root,false);
		else
			root = addChar(pos,root,true);
	}
}

node* addChar(int pos,node *root,bool leaf) {
	if (root->list[pos] == NULL ) {
		root->list[pos] = (node*) malloc(sizeof(node));
		root = root->list[pos];
		root->visits = 0;
		root->isLeaf = leaf;
		return root;
	}
	else {
		root = root->list[pos];
		root->visits++;
		root->isLeaf = leaf;
	}
	return root;
}

bool search(char *str,node *root) {
	int len = strlen(str);
	for(int i = 0 ; i < len ; i++) {
		char ch = str[i];
		int pos = ch - 65;
		if (presentChar(pos,root) == true) {
			root = root->list[pos];
			cout<<"P"<<"\t";
			continue;
		}
		else {
			return false;
		}
	}
	return true;	
}

bool presentChar(int pos,node *root) {
	if(root->list[pos] != NULL) {
		return true;
	}
	else {
		return true;
	}
}


int main(void) {
	node* root = (node*) malloc(sizeof(node));
	/*for(int i = 0; i < ALPHABET ; i++) {
		root->list[i] = (node*) malloc(sizeof(node));
	}*/
	
	addWord("APPLE",root);
	if(search("APPLE",root) == true) {
		cout<<"PRESENT"<<endl;
	}
}
