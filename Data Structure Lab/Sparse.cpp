#include<stdio.h>
#include<stdlib.h>

typedef struct { int num, row, col; } data;
typedef struct node { data val; struct node *next; } node;

data make(int n,int r,int c) {  // n is the value and r is the row and c is the column
	//This makes each and every entry of the matrix
	data val;
	val.num=n;
	val.row=r;
	val.col=c;
	return val;
}

node *create(data val) {
	// Creates the node of the list
	node *newnode=(node *)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=0;
	return newnode;
}

node *insertafter(node *oldnode, node *newnode) {
	//Simply inserts after the given node
	newnode->next=oldnode->next;
	oldnode->next=newnode;
	return newnode;
}

int find(node *list,data val) {
	//Finds the next node which is non-empty
	if((list->val.row==val.row)&&(list->val.col==val.col))
		return list->val.num;
	if(((list->val.row>=val.row)&&(list->val.col>val.col))||(list->next==0))
		return 0;
	return find(list->next,val);
}

node *insertunchecked(node *list,data val) {
	if((list->val.row==val.row)&&(list->val.col==val.col)) {
		list->val.num=val.num;
		return list;
	}
	if((list->next==0)||((list->next->val.row>=val.row)&&(list->next->val.col>val.col)))
		return insertafter(list,create(val));
	return insertunchecked(list->next,val);
}

node *insert(node *list,data val) {
	if(val.num==0)
		return list;
	return insertunchecked(list,val);
}

node *inputmatrix() {
	int i,j,r,c,n;
	printf("Enter the Rows and Colums of the Matrix : ");
	scanf("%d%d",&r,&c);
	node *list=create(make(r,-1,c));
	printf("Enter the elements sequentially in Row Major Form : ");
	for(i=0;i<r;++i)
		for(j=0;j<c;++j) {
			scanf("%d",&n);
			insert(list,make(n,i,j));
		}
	return list;
}

void outputmatrix(node *list) {
	int i,j,r=list->val.num,c=list->val.col;
	for(i=0;i<r;++i) {
		for(j=0;j<c;++j)
			printf("%d\t",find(list,make(0,i,j)));
		printf("\n");
	}
}

node *addmatrix(node *m1,node *m2) {
	int i,j,r=m1->val.num,c=m2->val.col,n;
	node *list=create(make(r,-1,c));
	for(i=0;i<r;++i)
		for(j=0;j<c;++j) {
			n=find(m1,make(0,i,j))+find(m2,make(0,i,j));
			insert(list,make(n,i,j));
		}
	return list;
}

node *multiplymatrix(node *m1,node *m2) {
	int i,j,k,r=m1->val.num,c=m2->val.col,t=m1->val.col,n;
	node *list=create(make(r,-1,c));
	for(i=0;i<r;++i)
		for(j=0;j<c;++j) {
			for(n=k=0;k<t;++k)
				n+=find(m1,make(0,i,k))*find(m2,make(0,k,j));
			insert(list,make(n,i,j));
		}
	return list;
}

int main(void) {
	//Declaration of two sparse matrices
	node *list;
	list=(node*)malloc(sizeof(node));
	list=inputmatrix();
	outputmatrix(list);
	node *list2;
	list2=(node*)malloc(sizeof(node));
	list2=inputmatrix();
	outputmatrix(list2);
	//Matrix after addition
	node *list_add;
	list_add=(node*)malloc(sizeof(node));
	list_add=addmatrix(list,list2);
	printf("Added Matrix is : \n");
	outputmatrix(list_add);
	//Matrix where the final output is to be stored after multipliavrion
	node *list_mul;
	list_mul=(node*)malloc(sizeof(node));
	list_mul=multiplymatrix(list,list2);
	printf("Multiplied Matrix is : \n");
	outputmatrix(list_mul);
}
