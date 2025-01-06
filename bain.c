#include <stdio.h>
#include <stdlib.h>

// Structure definition for tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function for Postorder traversal
void printPostorder(struct node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

// Function for Inorder traversal
void printInorder(struct node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Function for Preorder traversal
void printPreorder(struct node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// Main function
int main() {
    struct node* root = newNode(1); // Root node
    root->left = newNode(2);         // Left child of root
    root->right = newNode(3);        // Right child of root
    root->left->left = newNode(4);   // Left child of node 2
    root->left->right = newNode(5);  // Right child of node 2

    printf("\nPreorder traversal of binary tree is:\n");
    printPreorder(root);

    printf("\nInorder traversal of binary tree is:\n");
    printInorder(root);

    printf("\nPostorder traversal of binary tree is:\n");
    printPostorder(root);

    return 0;
}
