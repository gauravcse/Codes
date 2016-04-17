/***
		IMPLEMENTATION OF THE PRIMS MINUMUM COST SPANNING TREE ALGORITHM ON A GRAPH			***/

#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>

/***		EACH NODE OF A ADJACENCY LIST		***/

typedef struct node {
	int vertex;
	int value;
	struct node* next;
}node;

/***	PRIORITY QUEUE STRUCTURE		***/

struct queue {
	int u;
	int v;
	int priority;
	struct queue* link;				
};

/***		LINKED LIST IMPLEMENTATION FOR THE ADJACENCY LIST		***/

typedef struct linked_list {
	struct node* first;
}linked_list;

/***		A CLASS REPRESENTING THE GRAPH		***/
class Graph {
	private :
		/***	HOLDS THE HEAD OF EACH LINKED LIST		***/
		linked_list *vertices;
		int v;
		int edges;
		int minKey(int[],bool[]);
	
	public :
		Graph(int);
		Graph(Graph&);
		void display();
		void addEdge(int,int,int);
		void computePrim();
	
};

/***		GRAPH INITIALIZATION WITH A GIVEN NUMBER OF VERTICES GIVEN AS USER INPUT		***/

Graph::Graph(int v) {
	this->v=v;
	vertices=new linked_list[v];
	for(int i=0;i<v;i++) {
		vertices[i].first=new node;
		vertices[i].first->vertex=i+1;
		vertices[i].first->value=INT_MAX;
		vertices[i].first->next=NULL;
	}
}
/***		FUNCTION TO DISPLAY THE ADJACENCY LIST REPRESENTATION OF THE GRAPH		***/

void Graph::display() {
	for(int i=0;i<v;i++) {
		node* ptr=vertices[i].first;
		while(ptr->next!=NULL) {
			std::cout<<ptr->vertex<<"-->";
			ptr=ptr->next;
		}
		std::cout<<ptr->vertex<<std::endl;
		//std::cout<<vertices[i].first->vertex<<"->"<<std::endl;
	}
}

/***	CLASS FUNCTION TO ADD EDGES TO THE ADJACECNY LIST BY ADDING NEW NODES TO THE LINKED LIST	***/

void Graph::addEdge(int source,int dest,int weight) {
	node* temp1=new node;
	node* temp2=new node;
	temp1->value=temp2->value=weight;
	temp1->vertex=dest;
	temp2->vertex=source;
	temp1->next=temp2->next=NULL;
	node* ptr=vertices[source-1].first;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next=temp1;
	node* ptr1=vertices[dest-1].first;
	while(ptr1->next!=NULL) {
		ptr1=ptr1->next;
	}
	ptr1->next=temp2;
}

/***	FUNCTION TO COMPUTE THE MINIMUM COST SPANNING TREE BY PRIMS ALGORITHM		***/
/***	DETAILED DOCUMENTATION INSIDE		***/

void Graph::computePrim() {
	int adjacencyMatrix[this->v][this->v];
	for(int i=0;i<this->v;i++) {
		for(int j=0;j<this->v;j++) {
			adjacencyMatrix[i][j]=-1;
		}
	}
	for(int i=0;i<this->v;i++) {
		node* ptr=vertices[i].first;
		ptr=ptr->next;
		adjacencyMatrix[i][i]=0;
		while(ptr!=NULL) {
			adjacencyMatrix[i][ptr->vertex-1]=ptr->value;
			ptr=ptr->next;
		}
		for(int j=0;j<this->v;j++)	 {
			if(adjacencyMatrix[i][j]==-1)
				adjacencyMatrix[i][j]=0;
		}
	}
	/*for(int i=0;i<this->v;i++) {
		for(int j=0;j<this->v;j++)
			std::cout<<adjacencyMatrix[i][j]<<"\t";
		std::cout<<std::endl;
	}*/
     int parent[this->v]; // Array to store constructed MST
     int key[this->v];   // Key values used to pick minimum weight edge in cut
     bool mstSet[this->v];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < this->v; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < this->v-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int k = 0; k < this->v; k++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (adjacencyMatrix[u][k] && mstSet[k] == false && adjacencyMatrix[u][k] <  key[k])
             parent[k]  = u, key[k] = adjacencyMatrix[u][k];
     }
 
     // print the constructed MST
     //printMST(parent, V, adjacencyMatrix);
     printf("Edge   Weight\n");
   for (int i = 1; i < this->v; i++)
      printf("%d - %d    %d \n", parent[i], i, adjacencyMatrix[i][parent[i]]);

}

/***		PRIVATE HELPER FUNCTION TO COMPUTE THE MINIMUM KEY OR WEIGHT		***/

int Graph::minKey(int *key, bool *mstSet)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int k = 0; k < this->v; k++)
     if (mstSet[k] == false && key[k] < min)
         min = key[k], min_index = k;
 
   return min_index;
}

/***	MAIN FUNCTION OF THE PRIMS ALGORITHM TO TEST ON SAMPLE GRAPHS	***/
int main(void) {

	std::cout<<"ENTER THE NUMBER OF VERTICES AND EDGES : ";
	int edges,vertex;
	std::cin>>vertex>>edges;
	Graph graph(vertex);
	for(int i=0;i<edges;i++) {
		std::cout<<"ENTER THE START AND END VERTEX OF THE EDGE AND THEN ENTER THE WEIGHT: ";
		int start,end,weight;
		std::cin>>start>>end>>weight;
		graph.addEdge(start,end,weight);
	}
	graph.display();
	graph.computePrim();
}
