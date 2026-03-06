#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    TreeNode* left ;
    TreeNode* right;
    TreeNode* parent;

};

typedef struct TreeNode TreeNode;

TreeNode* createTreeNode(int data){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;

    return temp;
}





TreeNode* insertion(TreeNode* root, int data, TreeNode* parent = NULL){

    if(root == NULL){
        root = createTreeNode(data);
        root->parent = parent;
        return root;
    }

    else if(data > root->data){
        root->right = insertion(root->right, data, root);
    }
    else{
        root->left = insertion(root->left , data, root);
    }

    return root;
}