#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node *create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node *root, int data){
    if(root == NULL) root = create_node(data);
    else if(data <= root->data) root->left = insert_node(root->left, data);
    else root->right = insert_node(root->right, data);
    return root;
}

node* delete_node(node *root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = delete_node(root->left, data);
    else if(data > root->data) root->right = delete_node(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        } 
        else if(root->left == NULL){
            node* temp = root;
            root = root->right;
            free(temp);
        } 
        else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            free(temp);
        } 
        else{
            node* temp = root->right;
            while(temp->left != NULL) temp = temp->left;
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

void inorder_traversal(node* root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void main(){
    node* root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 17);
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\nDeleting node with data = 15\n");
    root = delete_node(root, 15);
    printf("Inorder traversal after deleting node with data = 15: ");
    inorder_traversal(root);
}