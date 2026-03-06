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

bool IsQueueEmpty(){
    if(front == NULL){
        return true;
    }else{
        return false;
    }
}

// FIX 1: নাম পরিবর্তন করে 'addListNode' করা হলো (main এর সাথে মিল রাখার জন্য)
ListNode* addListNode(ListNode* head, int value){
    if(head== NULL){
        head = createListNode(value);
    }else{
        ListNode* temp = createListNode(value);
        temp->next = head;
        head = temp;
    }
    return head;
}

void printNeighbor(ListNode* head){
    ListNode* temp = head;
    char nodeName[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};

    while(temp != NULL){

        printf("%c",nodeName[temp->data]);
        if(temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}


void PrintPath(int parent[], int node){
    if(parent[node] == node){
        printf("%d ", node);
        return;
    }else{
        PrintPath(parent, parent[node]);
        printf("%d", node);
    }
}

bool bfs(int visited[],int parent[], int v, int source, ListNode* graph[]){
    for(int i = 0; i<v; i++){
        visited[i] = 0;
        parent[i] = -1;
    }

    enqueue(source);
    visited[source] = 1;
    parent[source] = source; // Standard: Root parent is -1
    bool cycleDetected = false;

    printf("BFS Output: ");

    while(!IsQueueEmpty()){
        int currentNode = dequeue();
        
        // char প্রিন্ট করার লজিক ঠিক আছে
        char nodeName[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
        printf("%c ", nodeName[currentNode]); 

        ListNode* neighbor = graph[currentNode];
        // এখানে অতিরিক্ত সেমিকোলন ছিল, সরিয়ে দিয়েছি।

        while(neighbor != NULL){
            int data = neighbor->data;
            if(visited[data] == 0){
                visited[data] = 1;
                parent[data] = currentNode;
                enqueue(data);
            }
            else if(visited[data] == 1 && data != parent[currentNode]){
                cycleDetected = true;
            }
            neighbor = neighbor->next;
        }
    }
    printf("\n");
    return cycleDetected;
}

int main(){
    int v = 8;
    ListNode* graph[v];
    for(int i = 0;i<v; i++){
        graph[i] = NULL;
    }

    // Graph Connections (Corrected Function Calls)
    graph[0] = addListNode(graph[0], 1); 
    graph[0] = addListNode(graph[0], 4); 

    graph[1] = addListNode(graph[1], 0);
    graph[1] = addListNode(graph[1], 5);

    graph[2] = addListNode(graph[2], 5);
    graph[2] = addListNode(graph[2], 6);
    graph[2] = addListNode(graph[2], 3);

    graph[3] = addListNode(graph[3], 2);
    graph[3] = addListNode(graph[3], 7);

    graph[4] = addListNode(graph[4], 0);

    graph[5] = addListNode(graph[5], 1);
    graph[5] = addListNode(graph[5], 2);
    graph[5] = addListNode(graph[5], 6);

    graph[6] = addListNode(graph[6], 5);
    graph[6] = addListNode(graph[6], 2);
    graph[6] = addListNode(graph[6], 7);

    graph[7] = addListNode(graph[7], 3);
    graph[7] = addListNode(graph[7], 6);


    

    char nodes[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};

    printf("Printing Neighbor: \n");

    for(int i = 0; i<v; i++){
        printf("%c :",nodes[i]);

        printNeighbor(graph[i]);
    }
    
    int source = 0;
    int visited[v];
    int parent[v];

    bool cycleDetected = bfs(visited, parent, v, source, graph);

    // FIX 2: রেজাল্ট প্রিন্ট করা হলো
    printf("---------------------------\n");
    if(cycleDetected){
        printf("Final Result: Cycle Detected in the Graph!\n");
    } else {
        printf("Final Result: No Cycle Found.\n");
    }

    return 0;
}