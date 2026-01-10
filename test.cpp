#include <stdio.h>
#include <string.h>

// typedef ব্যবহার করে স্ট্রাকচার ডিফাইন করা
typedef struct {
    char name[50];
    char phone[20];
    int id;
    int points;
} Customer; // এখন টাইপটির নাম হলো শুধু 'Customer'

int main() {
    int N;
    printf("Enter number of customers (N): ");
    scanf("%d", &N);

    // আগে লিখতাম: struct Customer customers[N];
    // এখন লিখব শুধু:
    Customer customers[N];

    // বাকি সব কোড (ইনপুট, লুপ, সর্টিং) হুবহু আগের মতোই থাকবে...
    for (int i = 0; i < N; i++) {
        printf("Name: ");
        scanf("%s", customers[i].name);
        // ...
    }

    return 0;
}