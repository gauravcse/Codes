#include<stdio.h>
#include<stdlib.h>

/*typedef enum boolean{true,false}boolean;*/

typedef struct node {
	int vertex;
	struct node *next;
}node;

typedef struct first {
	node* head;
}first;

typedef struct graph {
	int v;
	first *arr;
}graph;

/*node *init(int key) {
	node *ptr=(node*)malloc(sizeof(node));
	ptr->next=NULL;
	ptr->vertex=key;
	return ptr;
}

boolean isEmpty(node *head) {
	return head==NULL;
}
*/
int queue[10000];
int top=-1;
int last=-1;
int max[10000];

bool isEmpty() {
	if(top>last)
		return true;
	else if(top==-1 && last==-1)
		return true;
	else
		return false;
}

void enqueue(int element) {
	if(last==-1 && top==-1) {
		last++;
		top++;
		queue[last]=element;
		return;
	}
	else {
		last++;
		queue[last]=element;
		return;
	}
}

int dequeue() {
	int value=queue[top];
	top++;
	return value;
}


node *initialize(int vert) {
	node *ptr=(node*)malloc(sizeof(node));
	ptr->vertex=vert;
	ptr->next=NULL;
	return ptr;
}

graph *init_graph(int V) {
	graph *g=(graph*)malloc(sizeof(graph));
	g->v=V;
	g->arr=(first*)malloc((V-1)*sizeof(node));
	for(int i=0;i<V;i++) {
		g->arr[i].head=NULL;
	}
	return g;
}

void print_graph(graph *g) {
	for(int V=0;V<g->v;V++) {
		node *temp=g->arr[V].head;
		while(temp!=NULL) {
			printf("-> %d", temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

void addEdge(graph *g,int p,int q) {
	node *ptr=initialize(q);
	ptr->next=g->arr[p].head;
	g->arr[p].head=ptr;
	
	ptr=initialize(p);
	ptr->next=g->arr[q].head;
	g->arr[q].head=ptr;
}

void bfs(int v,graph* g) {
	enqueue(v);
	max[v]=1;
	while(!isEmpty()==true) {
		int vtx=dequeue();
		node *temp=g->arr[vtx].head;
		 while(temp!=NULL){
			if(temp==g->arr[vtx].head) {
			    temp=temp->next;
				continue;
			}
			else {
				if(max[temp->vertex]==0) {
					enqueue(temp->vertex);
					max[temp->vertex]=max[vtx]+1;
				}
				temp=temp->next;	
			}
		}
	}
}

int main(void) {
 	int vertices;
 	scanf("%d",&vertices);
 	graph *g=init_graph(vertices);
 	for(int i=1;i<vertices;i++) {
 		int p,q;
 		scanf("%d %d",&p,&q);
 		addEdge(g,p-1,q-1);
	 }
	 print_graph(g);
	 bfs(0,g);
	 int depth=0;
	 int pos=0;
	 for(int i=0;i<vertices;i++) {
	 	printf("%d    ",max[i]);
	 	if(max[i]>depth) {
	 		depth=max[i];
	 		pos=i;
	 	}
	 }
	 printf("\n");
	 for(int i=0;i<vertices;i++) {
	 	max[i]=0;
	 }
	 bfs(pos,g);
	 depth=0;
	 for(int i=0;i<vertices;i++) {
	 	printf("%d    ",max[i]);
	  	if(max[i]>depth) {
	 		depth=max[i];
	 		pos=i;
	 	}
	 }
	 printf("\n%d\n",depth);
}
