#include<stdio.h>
#include<stdlib.h>

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


node *initialize(int vert) {
	node *ptr=(node*)malloc(sizeof(node));
	ptr->vertex=vert;
	ptr->next=NULL;
	return ptr;
}

graph *init_graph(int V) {
	graph *g=(graph*)malloc(sizeof(graph));
	g->v=V;
	g->arr=(first*)malloc(V*sizeof(node));
	for(int i=0;i<=V;i++) {
		g->arr[i].head=NULL;
	}
	return g;
}

/*void print_graph(graph *g) {
	for(int V=0;V<g->v;V++) {
		node *temp=g->arr[V].head;
		while(temp!=NULL) {
			printf("-> %d", temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}*/

void addEdge(graph *g,int p,int q) {
	node *ptr=initialize(q-1);
	ptr->next=g->arr[p-1].head;
	g->arr[p-1].head=ptr;
	
	ptr=initialize(p-1);
	ptr->next=g->arr[q-1].head;
	g->arr[q-1].head=ptr;
}
int main(void) {
 
}
