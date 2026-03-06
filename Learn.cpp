#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    char name;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

typedef struct TreeNode TreeNode;


TreeNode* createTreeNode(char name){
    TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    newTreeNode->name = name;
    newTreeNode->left = newTreeNode->right = newTreeNode->parent = NULL;
    return newTreeNode;
}

int countTree(TreeNode* root){

    if(root == NULL) return 0;
    else{
        return 1 + countTree(root->left) + countTree(root->right);
    }
}

void preOrder(TreeNode* root){
    if(root == NULL) return ;
    else{
        printf("%c ",root->name);
        preOrder(root->left);
        preOrder(root->right);
    }

}



void InOrder(TreeNode* root){
    if(root == NULL){
        return;
    }else{
        InOrder(root->left);
        printf("%c ",root->name);
        InOrder(root->right);

    }
}

void PostOrder(TreeNode* root){
    if(root == NULL){
        return;
    }else{
        PostOrder(root->left);
        PostOrder(root->right);

        printf("%c ",root->name);

    }
}

int main(){
    
    TreeNode* a = createTreeNode('A');
    TreeNode* b = createTreeNode('B');
    TreeNode* c = createTreeNode('C');
    TreeNode* d = createTreeNode('D');
    TreeNode* e = createTreeNode('E');

    a->left = b;
    b->parent = a;

    a->right = c;
    c->parent = a;

    c->left = d;
    d->parent = c;

    c->right = e;
    e->parent = c;
    

    printf("\nPre Order: "); preOrder(a);

    printf("\nIn Order: "); InOrder(a);
    printf("\nPost Order: "); PostOrder(a);



    printf("\nTotal Tree Nodes: %d",countTree(a));

    return 0;
}