#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode{
    int data;
    struct ListNode* next;
};
typedef struct ListNode ListNode;

ListNode* createListNode(int value){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

ListNode* addAdjacent(ListNode* head,int value){
    if(head == NULL){
        head = createListNode(value);
    }else{
        ListNode* temp = createListNode(value);
        temp->next = head;
        head = temp;
    }
    return head;
}

void PrintPath(int parent[], int node){
    if(parent[node] == node){
        printf("%d ",node);
        return;
    }else{
        PrintPath(parent, parent[node]);
        printf("%d ",node);
    }
    
}

void PrintNeighbor(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

ListNode* top = NULL;

void push(int data)
{
    if(top==NULL)
    {
        top = createListNode(data);
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = top;
        top = temp;
    }

}

int pop()
{
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        ListNode* temp = top;
        top = top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

bool isStackEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

void dfs(ListNode* graph[],int v, int source, int parent[]){
    int visited[v];
    for(int i = 0; i<v; i++){
        visited[i] = 0;
        parent[i] = -1;
    }

    push(source);
    visited[source] = 1;
    parent[source] = source;

    while(!isStackEmpty()){
        int currentNode = pop();

        printf("%d ", currentNode);
        ListNode* neighbor = graph[currentNode];

        while(neighbor != NULL){
            int data = neighbor->data;

            if(visited[data] == 0){
                push(data);
                visited[data] = 1;
                parent[data] = currentNode;
            }

            neighbor = neighbor->next;

        }
    }
    printf("\n");
}

int main(){
     int V = 5;
    ListNode* graph[V] = {NULL};

    graph[0] = addAdjacent(graph[0], 2);
    graph[0] = addAdjacent(graph[0], 1);


    graph[1] = addAdjacent(graph[1], 3);
    graph[1] = addAdjacent(graph[1], 2);

    graph[2] = addAdjacent(graph[2], 3);

    graph[3] = addAdjacent(graph[3], 0);

    graph[4] = addAdjacent(graph[4], 3);

    printf("Printing Neighbors: \n");
    for(int i=0; i<V; i++)
    {
        printf("%d -> ", i);
        PrintNeighbor(graph[i]);
    }
    int source = 0;
    int parent[V];


    printf("Printing DFS Traversal: ");
    dfs(graph, V, source, parent);

    return 0;
}
