#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int data;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* createListNode(int data){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

ListNode* front = NULL;
ListNode* rear = NULL;

ListNode* addAdjacent(ListNode* head , int data){
    if(head == NULL){
        head = createListNode(data);
        return head;
    }else{
        ListNode* temp = createListNode(data);
        temp->next = head;
        head = temp;
        return head;
    }
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

bool isQueueEmpty(){
    if(front == NULL){
        return true;
    }else{
        return false;
    }
}

void printNeighbor(ListNode* head){
    
    ListNode* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printPath(int parent[], int node){
    if(parent[node] == node){
        printf("%d ",node);
        return;
    }else{
        printPath(parent,parent[node]);
        printf("%d ",node);
    }
}

int main(){
    int v = 6;
    ListNode* graph[v] = {NULL};

    graph[1] = addAdjacent(graph[1], 2 );
    graph[1] = addAdjacent(graph[1], 5 );
    graph[2] = addAdjacent(graph[2], 4 );
    graph[3] = addAdjacent(graph[3], 4 );
    graph[5] = addAdjacent(graph[5], 3 );
    
    //Printing neighbor

    for(int i = 0; i<v; i++){
        printf("%d->", i);
        printNeighbor(graph[i]);
    }












    return 0;
}