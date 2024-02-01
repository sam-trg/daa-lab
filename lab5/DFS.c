#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Add a global opcount  
int opcount = 0;

struct AdjListNode {
  int dest;
  struct AdjListNode* next; 
};

struct Graph {
  int V;
  struct AdjListNode** adj;
  int* visited; /* visited array */  
};

// Stack for depth first traversal
struct Stack {
  int top;
  int capacity;
  int* array;
};

// Utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
  opcount++; // for malloc
  struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

// Utility function to create a graph with V vertices
struct Graph* createGraph(int V) {
  opcount++; // for malloc graph
  opcount += V; // for malloc adj
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
  graph->V = V;
  
  graph->adj = (struct AdjListNode**) malloc(V * sizeof(struct AdjListNode*));
  graph->visited = (int*) malloc(V * sizeof(int));

  for(int i=0; i<V; i++) {
    graph->visited[i] = 0;
    graph->adj[i] = NULL;
  }

  return graph;
}

// Utility function to add a directed edge to graph 
void addEdge(struct Graph* graph, int src, int dest) {

  // Add edge from src to dest
  struct AdjListNode* newNode = newAdjListNode(dest);
  newNode->next = graph->adj[src];
  graph->adj[src]  = newNode;

}

// Utility function to create a stack of given capacity
struct Stack* createStack(int capacity) {
  opcount++; // for malloc stack
  opcount++; // for malloc array
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*) malloc(stack->capacity * sizeof(int));
  return stack;
}

// Utility function to check if stack is empty  
int isEmpty(struct Stack* stack) {
  return stack->top == -1 ;
}

// Utility function to push an item to stack
void push(struct Stack* stack, int item) {
  if (stack->top == stack->capacity - 1)
    return;
  stack->array[++stack->top] = item; 
}

// Utility function to remove an item from stack
int pop(struct Stack* stack) {
  if (isEmpty(stack)) 
    return INT_MIN; // return min value
  return stack->array[stack->top--];
}

// Utility function to get front of queue
int front(struct Stack* stack) {
  if (isEmpty(stack))
      return INT_MIN;
  return stack->array[stack->top];
}

// Recursive function to perform DFS traversal and find topological sort
void topologicalSortUtil(struct Graph* graph, int v, struct Stack* stack) {

  graph->visited[v] = 1;

  struct AdjListNode* temp = graph->adj[v];
  while(temp) {
    int adjacent = temp->dest;
    if(graph->visited[adjacent] == 0) {
      topologicalSortUtil(graph, adjacent, stack);
    }
    temp = temp->next;
  }
  
  // Push current vertex to stack  
  push(stack, v);
}

// Main function to find topological ordering of a DAG 
void topologicalSort(struct Graph* graph) {

  struct Stack* stack = createStack(graph->V);

  // Mark all vertices as not visited
  for (int i = 0; i < graph->V; i++) {
    graph->visited[i] = 0;
  }

  printf("Op Count: %d, V: %d\n", opcount, graph->V);
  
  // Call recursive helper function
  for (int i = 0; i < graph->V; i++) {
    if(graph->visited[i] == 0) {
      topologicalSortUtil(graph, i, stack);
    }
  }
  
  // Print contents of stack 
  while (!isEmpty(stack)) {
    printf("%d ", pop(stack));
  }
}

int main() {
  
  // Create a graph
  int V = 5;
  struct Graph* graph = createGraph(V);
  
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3); 
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);

  // Find topological sort
  topologicalSort(graph);

  return 0;
}
