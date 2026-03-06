#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct DBTNode
{
    int data;
    struct DBTNode* left;
    struct DBTNode* right;

};

typedef struct DBTNode DBTNode;

DBTNode* createNode(int value){
    DBTNode* newNode = (DBTNode*)malloc(sizeof(DBTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
    

}

DBTNode* insertDBT(DBTNode* root, int value){
    if(root == NULL){
        root = createNode(value);
    }else if(value % root->data == 0){
        root->left = insertDBT(root->left, value);
    }else{
        root->right = insertDBT(root->right, value);
    }
    return root;
}

int countDivisible(DBTNode* root, int divisor){
    if(root == NULL){
        return 0;
    }

    int count = 0;

    if(root->data % divisor == 0){
        count = 1;
    }
    return count + countDivisible(root->left, divisor) + countDivisible(root->right, divisor);
}

int findPath(DBTNode* root, int terget, int path[], int level){
    if(root == NULL){
        return 0;
    }

    path[level] = root->data;

    if(root->data == terget){
        return level + 1;
    }

    if(terget % root->data == 0){
       return findPath(root->left, terget, path, level+1);
    }else{
        return findPath(root->right, terget, path, level+1);
    }
}


void PrintPathToNode(DBTNode* root, int terget){
    int path[100];
    int length = findPath(root, terget, path, 0);

    if(length>0){

        for(int i = 0; i<length; i++){
            printf("%d",path[i]);
            if(i<length -1) printf("->");
        
        }  
        printf("\n");
    }
    else{
        printf("Node not found!\n");
    }
}


void findMaxHelper(DBTNode* root, int* maxVal){
    if(root == NULL){
        return;
    }

    if(root->data > *maxVal){
        *maxVal = root->data;
    }
    findMaxHelper(root->left, maxVal);
    findMaxHelper(root->right, maxVal);

}


void findMinHelper(DBTNode* root, int* minVal){
    if(root == NULL){
        return;
    }

    if(root->data < *minVal){
        *minVal = root->data;
    }
    findMinHelper(root->left, minVal);
    findMinHelper(root->right, minVal);

}

int findDBTExtreme(DBTNode* root, int findMax){
    if(root == NULL){
        return -1;
    }
    int result = root->data;

    

    if(findMax == 1){
        findMaxHelper(root, &result);
    }else{
         findMinHelper(root, &result);
    }

    return result;
}

int main(){
    DBTNode* root = NULL;
    int values[] = {6, 3, 8, 12, 7, 24};
    int n = sizeof(values)/sizeof(values[0]);

    for(int i = 0; i<n; i++){
        root = insertDBT(root, values[i]);
    }

    printf("printPathToNode(root, 24) => ");
    PrintPathToNode(root, 24);

    printf("printPathToNode(root, 7) => ");
    PrintPathToNode(root, 7);

    printf("printPathToNode(root, 5) => ");
    PrintPathToNode(root, 5);

    printf("CountDivisible(root, 3) => %d\n",countDivisible(root, 3));

    printf("findDBTExtreme(root, true) => %d\n",findDBTExtreme(root, 1));
    printf("findExtreme(root, false) => %d\n", findDBTExtreme(root, 0));

    return 0;
}
