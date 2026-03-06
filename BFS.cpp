#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct TreeNode
{
    int vertex;
    TreeNode* next;
};

typedef struct TreeNode TreeNode;

TreeNode* adj[MAX];
int visited[MAX];
int distance[MAX];
int queue[MAX];
int front = -1, rear = -1;

TreeNode* createNode(int v){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest){
    TreeNode* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;

}

void enqueue(int value){
    if(rear == MAX-1) return;
    if(front == -1) front = 0;
    queue[++rear] = value;

}

int dequeue(){
    if(front == -1 || front>rear) return -1;
    return queue[front++];
}

int isQueueEmpty(){
    return(front == -1 || front>rear);
}

void bfs(int startNode ,int numNodes){
    for(int i = 0; i<=numNodes; i++){
        visited[i] = 0;
        distance[i] = -1;
    }

    enqueue(startNode);
    visited[startNode] = 1;
    distance[startNode] = 0;
    

    printf("\nBFS Shortest Path Result:\n");

    while(!isQueueEmpty()){
        int current = dequeue();

        TreeNode* temp = adj[current];

        while(temp != NULL){
            int neighbor = temp->vertex;
            if(visited[neighbor] == 0){
                visited[neighbor] = 1;
                distance[neighbor] = distance[current] + 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }

    for(int i = 0; i<=numNodes; i++){
        if(distance[i] != -1){
            printf("Source to Node %d distance: %d\n",i, distance[i]);

        }else{
            printf("Node %D is Unreachable\n",i);
        }
    }

}


int main(){
    int numNodes, numEdges;
    int src, dest, startNode; 

    for(int i = 0; i<MAX; i++) adj[i] = NULL;

    printf("Enter number of nodes and edges: ");
    scanf("%D %d", &numNodes, &numEdges);

    printf("Enter edges (u v): \n");
    for(int i = 0; i<numEdges; i++){
        scanf("%d %d",&src, &dest);
        addEdge(src, dest);
    }

    printf("Enter Source Node: ");
    scanf("%d", &startNode);

    bfs(startNode, numNodes);

    return 0;

}