#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertNode(Node* root, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;

    if(root == NULL){
        root = temp;
        return root;
    }

    Node* pointer = root;
    while (pointer != NULL)
    {
        if(data > pointer->data)
            pointer = pointer->right;
        else
            pointer = pointer->left;
    }

    pointer = temp;
    return root;
}

void depthFirstPrint(Node* root)
{
    if(root == NULL) return;

    printf("\t -> %d", root->data);
    depthFirstPrint(root->left);
    depthFirstPrint(root->right);
    return;
}

typedef struct {
    Node* root;
} BST;

BST* insert(BST* tree, int data)
{
    tree->root = insertNode(tree->root, data);
    return tree;
}

void print(BST* tree)
{
    depthFirstPrint(tree->root);
}

int main()
{
    BST tree;
    tree.root = NULL;

    tree = *insert(&tree, 10);
    tree = *insert(&tree, 20);
    tree = *insert(&tree, 30);
    tree = *insert(&tree, 40);
    print(&tree);

    return 0;
}