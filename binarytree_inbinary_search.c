#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node* goback(struct Node* root, int data) {
    
    if (root == NULL) {
        return newNode(data);
    }


   
    if (data < root->data) {
        root->left = goback(root->left, data);
    } else if (val > root->val) {
        root->right = goback(root->right, data);
    }

    
    return root;
}


void explore(struct Node* root) {
    if (root != NULL) {
        explore(root->left);
        printf("%d ", root->data);
        explore(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {8, 3, 10, 1, 6, 14, 4, 7, 13,17,14};
    int len = sizeof(keys)/sizeof(keys[0]);

    for (int i = 0; i < len; i++) {
        root = goback(root, keys[i]);
    }

   // printf("Inorder traversal of the binary search tree: ");
    explore(root);

    return 0;
}
