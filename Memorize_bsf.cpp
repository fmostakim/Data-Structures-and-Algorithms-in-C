#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct ListNode{
    int data;
    ListNode* next;
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


ListNode* addAdjacent(ListNode* head, int data){
    if(head == NULL){
        head =  createListNode(data);
        return head;
    }else{
        ListNode* temp = createListNode(data);
        temp->next = head;
        head = temp;
        return head;
    }

}

void printNeighbor(ListNode* head){
    ListNode* temp = head;
    while(temp!= NULL){
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
        printPath(parent, parent[node]);
        printf("%d ",node);
    }
}

int main(){
    int v = 5;
    ListNode* graph[v] = {NULL};

    graph[0] = addAdjacent(graph[0],3);
    graph[0] = addAdjacent(graph[0],4);
    graph[3] = addAdjacent(graph[3],4);
    graph[3] = addAdjacent(graph[3],1);
    graph[4] = addAdjacent(graph[4],2);
    graph[1] = addAdjacent(graph[1],2);


    for(int i = 0; i<v; i++){
        printf("%d-> ", i);
        printNeighbor(graph[i]);
    }

    int visited[v] = {0};
    int parent[v];
    for(int i = 0; i<v; i++){
        parent[i] = - 1;
    }

    int source = 0;

    enqueue(source);
    visited[source] =1; 
    parent[source] = source;

    while(!isQueueEmpty()){
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

    printf("\nVisited Array: ");
    for(int i = 0; i<v; i++){
        printf("%d ",visited[i]);
    }

    printf("\nParent Array: ");
    for(int i = 0; i<v; i++){
        printf("%d ",parent[i]);
    }

    printf("\n");

    printPath(parent, 1);

}








///////////////////
void bfs(ListNode* graph[], int v, int startNode, int parent[]) {
    // Visited অ্যারে তৈরি এবং ইনিশিয়ালাইজ করা
    int visited[v];
    for(int i = 0; i < v; i++) {
        visited[i] = 0;
        // Parent অ্যারেও এখানে রিসেট করে নেওয়া ভালো, অথবা main থেকেও পাঠানো যেতে পারে
        parent[i] = -1; 
    }

    // সোর্স নোড সেটআপ
    enqueue(startNode);
    visited[startNode] = 1;
    parent[startNode] = startNode;

    printf("BFS Traversal: ");

    while(!isQueueEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        // বর্তমান নোডের নেইবরদের চেক করা
        ListNode* neighbor = graph[currentNode];

        while(neighbor != NULL) {
            int data = neighbor->data;

            if(visited[data] == 0) {
                enqueue(data);
                visited[data] = 1;
                parent[data] = currentNode;
            }
            neighbor = neighbor->next;
        }
    }
    printf("\n");
}