#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Node
{
    int vertex;
    Node* next;
};

typedef struct Node Node;

Node* adj[MAX];
int visited[MAX];
int distance[MAX];
int queue[MAX];
int front = -1, rear = -1;

Node* createNode(int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;

}

void addEdge(int src, int dest){
    Node* newNode = createNode(dest);
    newNode->next = adj[src];

    adj[src] = newNode;
}



