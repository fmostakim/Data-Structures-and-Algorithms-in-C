// #include <stdio.h>

// #define V 8 // আমাদের গ্রাফে ৮টি নোড (r to y)

// // ম্যাট্রিক্স ইনিশিয়লাইজ এবং এজ (Edge) যোগ করার ফাংশন
// void addEdge(int matrix[V][V], int i, int j) {
//     matrix[i][j] = 1;
//     matrix[j][i] = 1; // যেহেতু এটি Undirected Graph (উভয় দিকে কানেকশন)
// }

// void printMatrix(int matrix[V][V]) {
//     printf("Adjacency Matrix:\n");
//     // হেডার প্রিন্ট করছি (বোঝার সুবিধার জন্য)
//     printf("  r s t u v w x y\n");
    
//     char nodes[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
    
//     for (int i = 0; i < V; i++) {
//         printf("%c ", nodes[i]); // বাম পাশের নোড নাম
//         for (int j = 0; j < V; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int matrix[V][V];

//     // ১. প্রথমে সব ঘর ০ করে দিচ্ছি
//     for(int i = 0; i < V; i++) {
//         for(int j = 0; j < V; j++) {
//             matrix[i][j] = 0;
//         }
//     }

//     // ২. গ্রাফ দেখে কানেকশনগুলো বসাচ্ছি (Mapping অনুযায়ী)
//     // r(0) এর সাথে s(1), v(4)
//     addEdge(matrix, 0, 1);
//     addEdge(matrix, 0, 4);

//     // s(1) এর সাথে w(5) (r আগেই হয়ে গেছে)
//     addEdge(matrix, 1, 5);

//     // t(2) এর সাথে w(5), x(6), u(3)
//     addEdge(matrix, 2, 5);
//     addEdge(matrix, 2, 6);
//     addEdge(matrix, 2, 3);

//     // u(3) এর সাথে y(7) (t আগেই হয়ে গেছে)
//     addEdge(matrix, 3, 7);

//     // w(5) এর সাথে x(6) (s, t আগেই হয়ে গেছে)
//     addEdge(matrix, 5, 6);

//     // x(6) এর সাথে y(7) (w, t আগেই হয়ে গেছে)
//     addEdge(matrix, 6, 7);
    
//     // v(4), y(7) এর কানেকশনগুলো উপরের গুলোর মাধ্যমেই কাভার হয়ে গেছে।

//     printMatrix(matrix);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define V 8 // মোট ৮টি নোড

// তোমার কোডের স্ট্রাকচার
struct ListNode {
    int data;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

// তোমার দেওয়া নোড তৈরির ফাংশন
ListNode* createListNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// তোমার দেওয়া লিস্টে অ্যাড করার ফাংশন (Head এ অ্যাড করে)
ListNode* addListNode(ListNode* head, int value) {
    if (head == NULL) head = createListNode(value);
    else {
        ListNode* temp = createListNode(value);
        temp->next = head;
        head = temp;
    }
    return head;
}

// প্রিন্ট করার ফাংশন
void printNeighbor(ListNode* head) {
    ListNode* temp = head;
    char nodes[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}; // ইনডেক্স থেকে নাম প্রিন্ট করার জন্য
    
    while (temp != NULL) {
        // temp->data হলো ইনডেক্স, সেটাকে ক্যারেক্টারে কনভার্ট করে দেখাচ্ছি
        printf("%c(%d) ", nodes[temp->data], temp->data);
        
        if (temp->next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("-> NULL\n");
}

int main() {
    // পয়েন্টার অ্যারে ডিক্লেয়ার (প্রতিটি ইনডেক্স একেকটি নোড নির্দেশ করে)
    ListNode* graph[V]; 

    // সব নাল (NULL) করে দিচ্ছি শুরুতে
    for(int i = 0; i < V; i++) {
        graph[i] = NULL;
    }

    // --- গ্রাফের কানেকশন দিচ্ছি ---
    // মনে রাখবে: addListNode ফাংশনটি ভ্যালুগুলো শুরুতে (Head) অ্যাড করে।
    // তাই প্রিন্ট করার সময় শেষেরটা আগে দেখাবে।

    // r (0) -> connected to s(1), v(4)
    graph[0] = addListNode(graph[0], 1); // r-s
    graph[0] = addListNode(graph[0], 4); // r-v

    // s (1) -> connected to r(0), w(5)
    graph[1] = addListNode(graph[1], 0);
    graph[1] = addListNode(graph[1], 5);

    // t (2) -> connected to w(5), x(6), u(3)
    graph[2] = addListNode(graph[2], 5);
    graph[2] = addListNode(graph[2], 6);
    graph[2] = addListNode(graph[2], 3);

    // u (3) -> connected to t(2), y(7)
    graph[3] = addListNode(graph[3], 2);
    graph[3] = addListNode(graph[3], 7);

    // v (4) -> connected to r(0)
    graph[4] = addListNode(graph[4], 0);

    // w (5) -> connected to s(1), t(2), x(6)
    graph[5] = addListNode(graph[5], 1);
    graph[5] = addListNode(graph[5], 2);
    graph[5] = addListNode(graph[5], 6);

    // x (6) -> connected to w(5), t(2), y(7)
    graph[6] = addListNode(graph[6], 5);
    graph[6] = addListNode(graph[6], 2);
    graph[6] = addListNode(graph[6], 7);

    // y (7) -> connected to u(3), x(6)
    graph[7] = addListNode(graph[7], 3);
    graph[7] = addListNode(graph[7], 6);

    // --- প্রিন্ট করছি ---
    printf("Adjacency List:\n");
    char nodes[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
    
    for (int i = 0; i < V; i++) {
        printf("%c : ", nodes[i]);
        printNeighbor(graph[i]);
    }

    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>

// #define V 8  // আমাদের গ্রাফে ৮টি নোড আছে

// // --- LINKED LIST STRUCTURE ---
// struct ListNode{
//     int data;
//     struct ListNode* next;
// };

// typedef struct ListNode ListNode;

// // --- QUEUE VARIABLES ---
// ListNode* front = NULL;
// ListNode* rear = NULL;

// // --- HELPER FUNCTIONS ---
// ListNode* createListNode(int value){
//     ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//     newNode->data = value;
//     newNode->next = NULL;
//     return newNode;
// }

// // তোমার লজিক: Head-এ নতুন নোড অ্যাড হয় (তাই লিস্টে নোডগুলো রিভার্স অর্ডারে থাকে)
// ListNode* addListNode(ListNode* head, int value){
//     if(head == NULL) head = createListNode(value);
//     else{
//         ListNode* temp = createListNode(value);
//         temp->next = head;
//         head = temp;
//     }
//     return head;
// }

// // --- QUEUE FUNCTIONS ---
// void enqueue(int data){
//     if(front == NULL){
//         front = createListNode(data);
//         rear = front;
//     }else{
//         ListNode* temp = createListNode(data);
//         rear->next = temp;
//         rear = temp;
//     }
// }

// int dequeue(){
//     if(front == NULL){
//         return -1;
//     }else if(front == rear){
//         int data = front->data;
//         free(front);
//         front = rear = NULL;
//         return data;
//     }else{
//         ListNode* temp = front;
//         front = front->next;
//         int data = temp->data;
//         free(temp);
//         return data;
//     }
// }

// bool IsqueueEmpty(){
//     if(front == NULL) return true;
//     else return false;
// }

// // --- BFS FUNCTION ---
// void bfs(ListNode* graph[], int v, int source){
    
//     int visited[V]; // ৮ সাইজের অ্যারে
//     int parent[V];  // পাথ প্রিন্ট না করলেও স্ট্রাকচার ঠিক রাখতে রাখলাম
    
//     // 初始化 (Initialize)
//     for(int i = 0; i < V; i++){
//         visited[i] = 0;
//         parent[i] = -1;
//     }
    
//     // Source কে কিউতে ঢোকানো
//     enqueue(source);
//     visited[source] = 1;
//     parent[source] = source;

//     printf("BFS Traversal starting from %d (r): ", source);
    
//     while(!IsqueueEmpty()){
//         int currentNode = dequeue();
        
//         // এখানে আমি আউটপুট ম্যাপিং করে দেখাচ্ছি যাতে বুঝতে সুবিধা হয়
//         // 0 -> r, 1 -> s ... এভাবে
//         char nodeName[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
//         printf("%c ", nodeName[currentNode]); 

//         ListNode* neighbor = graph[currentNode];

//         while(neighbor != NULL){
//             int data = neighbor->data;
//             if(visited[data] == 0){
//                 enqueue(data);
//                 visited[data] = 1;
//                 parent[data] = currentNode;
//             }
//             neighbor = neighbor->next;
//         }
//     }
//     printf("\n");
// }

// int main(){
//     ListNode* graph[V];

//     // সব নাল করে দিচ্ছি
//     for(int i=0; i<V; i++){
//         graph[i] = NULL;
//     }

//     // --- গ্রাফ কানেকশন ---
//     // নোট: যেহেতু addListNode শুরুতে (Head) অ্যাড করে, 
//     // তাই পরে যেটা অ্যাড করব সেটা লিস্টের শুরুতে থাকবে এবং BFS আগে সেটা পাবে।

//     // r(0) যুক্ত s(1), v(4) এর সাথে
//     graph[0] = addListNode(graph[0], 1); 
//     graph[0] = addListNode(graph[0], 4); 

//     // s(1) যুক্ত r(0), w(5) এর সাথে
//     graph[1] = addListNode(graph[1], 0);
//     graph[1] = addListNode(graph[1], 5);

//     // t(2) যুক্ত w(5), x(6), u(3) এর সাথে
//     graph[2] = addListNode(graph[2], 5);
//     graph[2] = addListNode(graph[2], 6);
//     graph[2] = addListNode(graph[2], 3);

//     // u(3) যুক্ত t(2), y(7) এর সাথে
//     graph[3] = addListNode(graph[3], 2);
//     graph[3] = addListNode(graph[3], 7);

//     // v(4) যুক্ত r(0) এর সাথে
//     graph[4] = addListNode(graph[4], 0);

//     // w(5) যুক্ত s(1), t(2), x(6) এর সাথে
//     graph[5] = addListNode(graph[5], 1);
//     graph[5] = addListNode(graph[5], 2);
//     graph[5] = addListNode(graph[5], 6);

//     // x(6) যুক্ত w(5), t(2), y(7) এর সাথে
//     graph[6] = addListNode(graph[6], 5);
//     graph[6] = addListNode(graph[6], 2);
//     graph[6] = addListNode(graph[6], 7);

//     // y(7) যুক্ত u(3), x(6) এর সাথে
//     graph[7] = addListNode(graph[7], 3);
//     graph[7] = addListNode(graph[7], 6);

//     // BFS কল করা হচ্ছে (Source 0 মানে r)
//     bfs(graph, V, 0);

//     return 0;
// }

