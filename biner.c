#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
};
struct Node* newNode(int data)
{
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = data;
node->left = node->right = NULL;
return node;
}
void preorder(struct Node* root)
{
if (root != NULL)
{
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
void inorder(struct Node* root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void postorder(struct Node* root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

void main()
{
struct Node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);
root->right->right = newNode(7);
clrscr();
printf("Preorder Traversal: ");
preorder(root);
printf("\n");
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
printf("Postorder Traversal: ");
postorder(root);
printf("\n");
getch();
}
