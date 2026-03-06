#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node* left, *right;
};

typedef struct Node Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


Node* insert(Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if(value<root->data){
        root->left = insert(root->left, value);
    }else if(value>root->data){
        root->right = insert(root->right, value);
    }

    return root;
}


void search(Node* root, int key){
    if(root == NULL){
        printf("%d: Not Found\n", key);
        return;
    }

    if(root->data == key){
        printf("%d: Found\n", key);
    }else if(key < root->data){
        search(root->left, key);
    }else{
        search(root->right, key);
    }
}
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key> root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp; 
        }else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int i = 0; i<7; i++){
        root = insert(root, values[i]);
    }

    printf("Original Tree (Inorder): ");
    inorder(root);
    printf("\n");

    printf("\nDeleting 70...\n");
    root = deleteNode(root, 70);

    printf("Inorder Traversal after Deletion: ");
    inorder(root);
    printf("\n");

    search(root, 90);

    return 0;
}