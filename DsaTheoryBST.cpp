#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999 // অসীম দূরত্ব বোঝাতে

// কালার কোড (থিওরি স্লাইড অনুযায়ী)
#define WHITE 0 // নতুন (New/Unvisited)
#define GRAY 1  // প্রসেসিং চলছে (In Queue)
#define BLACK 2 // কাজ শেষ (Finished)

// ১. নোড স্ট্রাকচার (Adjacency List এর জন্য)
typedef struct Node {
    int vertex;       // বন্ধুর আইডি
    struct Node* next; // পরের বন্ধুর ঠিকানা
} Node;

// --- GLOBAL VARIABLES (যাতে সব ফাংশন থেকে অ্যাক্সেস করা যায়) ---
Node* adj[MAX];    // ফ্রেন্ডলিস্ট (Adjacency List)
int color[MAX];    // নোডের কালার (WHITE/GRAY/BLACK)
int d[MAX];        // দূরত্ব (Distance)
int pi[MAX];       // প্যারেন্ট বা বাবা (Parent)
int Q[MAX];        // কিউ (Queue)
int head = 0, tail = 0; // কিউ কন্ট্রোলার

// --- HELPER FUNCTIONS ---

// নতুন নোড তৈরির ফাংশন
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// গ্রাফে এজ যোগ করা (Friendship তৈরি করা)
void addEdge(int src, int dest) {
    // src এর লিস্টে dest কে যোগ করা
    Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
    
    // Undirected Graph হলে উল্টোটাও যোগ হবে (dest -> src)
    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

// কিউ অপারেশন (Queue Operations)
void Enqueue(int x) { Q[tail++] = x; }
int Dequeue() { return Q[head++]; }
int isQueueEmpty() { return head == tail; }

// --- MAIN BFS ALGORITHM (Easy Names) ---
void BFS(int startNode, int totalNodes) {
    
    // ধাপ ১: সব নোডকে রিসেট বা ইনিশিয়ালাইজ করা
    for (int i = 1; i <= totalNodes; i++) {
        if (i == startNode) continue; // সোর্স বাদে বাকিরা
        color[i] = WHITE;
        d[i] = INF;
        pi[i] = -1; // -1 মানে কোনো প্যারেন্ট নেই (NIL)
    }

    // ধাপ ২: সোর্স নোড (Start Node) সেটআপ
    color[startNode] = GRAY;
    d[startNode] = 0;
    pi[startNode] = -1;

    // ধাপ ৩: কিউ রিসেট এবং সোর্সকে ঢোকানো
    head = 0; tail = 0;
    Enqueue(startNode);

    printf("\nBFS Processing Log:\n");

    // ধাপ ৪: মেইন লুপ (যতক্ষণ কিউ খালি না হয়)
    while (!isQueueEmpty()) {
        
        // লাইন থেকে একজনকে বের করলাম। সে এখন 'Current Node'
        int currentNode = Dequeue(); 
        
        // এখন 'Current Node' এর ফ্রেন্ডলিস্ট চেক করব
        Node* temp = adj[currentNode]; 
        
        while (temp != NULL) {
            int neighbor = temp->vertex; // বন্ধুকে পেলাম (Neighbor)
            
            // যদি বন্ধু একদম নতুন হয় (WHITE)
            if (color[neighbor] == WHITE) {
                
                color[neighbor] = GRAY;          // তাকে মার্ক করলাম
                d[neighbor] = d[currentNode] + 1; // দূরত্ব আপডেট (আমার দূরত্ব + ১)
                pi[neighbor] = currentNode;      // প্যারেন্ট সেট (আমিই তার বাবা)
                
                Enqueue(neighbor);               // বন্ধুকে লাইনে (Queue) দাঁড় করালাম
            }
            temp = temp->next; // লিস্টের পরের বন্ধুর কাছে যাও
        }

        // সব বন্ধুর কাজ শেষ, তাই 'Current Node' এখন কালো (BLACK)
        color[currentNode] = BLACK; 
        printf("Node %d processing done. Distance: %d\n", currentNode, d[currentNode]);
    }
}

int main() {
    int totalNodes, totalEdges;
    int src, dest, startNode;

    // লিস্ট রিসেট করা (Garbage value সরাতে)
    for(int i=0; i<MAX; i++) adj[i] = NULL;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &totalNodes, &totalEdges);

    printf("Enter edges (u v) - example: 1 2:\n");
    for (int i = 0; i < totalEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter Source Node: ");
    scanf("%d", &startNode);

    // BFS কল করা
    BFS(startNode, totalNodes);

    // ফাইনাল রেজাল্ট প্রিন্ট (Shortest Path Info)
    printf("\nFinal Shortest Path Info:\n");
    for(int i = 1; i <= totalNodes; i++) {
        if(d[i] != INF)
            printf("Node %d: Distance %d (Parent: %d)\n", i, d[i], pi[i]);
        else
            printf("Node %d is Unreachable\n", i);
    }

    return 0;
}