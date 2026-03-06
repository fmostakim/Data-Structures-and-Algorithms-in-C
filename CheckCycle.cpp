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

ListNode* addListNode(ListNode* head, int value){
    if(head == NULL){
        head = createListNode(value);
    }else{
        ListNode* temp = createListNode(value);
        temp->next = head;
        head = temp;

    }
    return head;
}

ListNode* top = NULL;
void push(int data){
    if(top == NULL){
        top = createListNode(data);
    }else{
        ListNode* temp = createListNode(data);
        temp->next = top;
        top = temp;
    }
}

int pop(){
    if(top == NULL){
        return -1;
    }else{
        ListNode* temp = top;
        top = top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

bool IsStackEmpty(){
    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

bool hasCycleIterative(ListNode* graph[],int source, int visited[], int parent[]){
    push(source);
    visited[source] = 1;
    parent[source] = source;

    while(!IsStackEmpty()){
        int currentNode = pop();
        ListNode* neighbor = graph[currentNode];

        while(neighbor != NULL){
            int data = neighbor->data;

            if(visited[data] == 0){
                visited[data] = 1;
                push(data);
                parent[data] = currentNode;
            }else{
                if(parent[currentNode] != data){
                    return true;
                }
            }
            neighbor = neighbor->next;
        }
    }
    return false;
}

int main(){
    int v = 5;
    ListNode* graph[v];
    int visited[v];
    int parent[5];

    for(int i = 0; i<v; i++){
        graph[i] = NULL;
        visited[i] = 0;
        parent[i] = -1;
    }

    graph[0] = addListNode(graph[0], 1);
    graph[1] = addListNode(graph[1], 0);

    graph[1] = addListNode(graph[1], 2);
    graph[2]= addListNode(graph[2], 1);

    graph[2]= addListNode(graph[2], 0);
    graph[0]= addListNode(graph[0], 2);

    graph[3]= addListNode(graph[3], 4);
    graph[4]= addListNode(graph[4], 3);

    bool cycleFound = false;
    
    for(int i = 0; i<v; i++){
        if(visited[i] == 0){
            if(hasCycleIterative(graph, i, visited, parent)){
                cycleFound = true;
                break;
            }
        }
    }

    if(cycleFound) printf("Yes, cycle Detected!\n");
    else printf("No Cycle Found.\n");
    return 0;

}