#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    return temp;
}

struct node* addNode(struct node* root, int data)
{
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    
    if(data >= root->data){
        root->right = addNode(root->right, data);
    } else {
        root->left = addNode(root->left, data);
    }
    return root;
}

struct node* preorderTraversal(struct node* root)
{
    if(root == NULL) return;
    
    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

struct node* inorderTraversal(struct node* root)
{
    if(root == NULL) return;
    
    preorderTraversal(root->left);
    printf("%d\n", root->data);
    preorderTraversal(root->right);
}

struct node* postorderTraversal(struct node* root)
{
    if(root == NULL) return;
    
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    printf("%d\n", root->data);
}

int main(){
    struct node* BST;
    BST = addNode(BST, 10);
    BST = addNode(BST, 11);
    BST = addNode(BST, 5);
    BST = addNode(BST, 7);
    BST = addNode(BST, 2);
    BST = addNode(BST, 1);
    BST = addNode(BST, 9);
    
    // printf("%d", BST->right->data);
    
    postorderTraversal(BST);
    
    return 0;
}