#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* front = NULL;
ListNode* rear = NULL;


ListNode* createListNode(int value){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

ListNode* addListNode(ListNode* head, int value){
    if(head == NULL) head = createListNode(value);
    else{
        ListNode* temp = createListNode(value);
        temp->next = head;
        head = temp;
    }
    return head;
}

void printNeighbor(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        
        if(temp->next != NULL){
            printf(",");
        }
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int data){
    if(front == NULL){
        front = createListNode(data);
        rear = front;
    }else{
        ListNode* temp = createListNode(data);
        rear->next = temp;
        rear = temp;
    }
}



int dequeue(){
    if(front == NULL){
        return -1;
    }else if(front == rear){
        int data = front->data;
        
        free(front);
        front = rear = NULL;
        return data;
    }else{
        ListNode* temp = front;
        front = front->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

bool IsqueueEmpty(){
    if(front == NULL) return true;
    else{
        return false;
    }
}

void PrintPath(int parent[], int node){
    if(parent[node] == node){
        printf("%d ",node);
        return;
    }
    else{
        PrintPath(parent, parent[node]);
        printf("%d ",node);
    }
}


void bfs(ListNode* graph[], int v, int source, int parent[]){

    int visited[5];
    
    for(int i = 0; i<5; i++){
        visited[i] = 0;

        parent[i] = -1;
    }
    
    
    enqueue(source);
    visited[source] = 1;
    parent[source] = source;

    printf("BFS Traversal: ");
    while(!IsqueueEmpty()){
        int currentNode = dequeue();
        printf("%d ", currentNode);
        ListNode* neighbor = graph[currentNode];

        while(neighbor != NULL){
            int data = neighbor->data;
            if(visited[data] == 0){
                enqueue(data);
                visited[data] = 1;
                parent[data] = currentNode;

            }

            neighbor = neighbor->next;
        }
    }
    printf("\n");

}



int main(){
    int v = 5;
    ListNode* graph[5] = {NULL};

    graph[0] = addListNode(graph[0],3);
    graph[0] = addListNode(graph[0],4);
    graph[3] = addListNode(graph[3],4);
    graph[3] = addListNode(graph[3],1);
    graph[4] = addListNode(graph[4],2);
    graph[1] = addListNode(graph[1],2);

    printf("Printing Neighbor: \n");
    for(int i = 0; i<5; i++){
        printf("%d->",i);
        printNeighbor(graph[i]);
    }

    
    int parent[v];
    int source = 0;

    
    
    bfs(graph, v, source, parent);

    printf("Printing path to go 4: ");
    PrintPath(parent, 4);

    return 0;
}