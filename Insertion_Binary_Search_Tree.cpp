#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) : data(data), left(NULL), right(NULL) {};
        Node () {};
};

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

Node * insert(Node *root, int key) {
    if (root == NULL) return new Node(key);

    if (key == root->data) {
        return root;
    } else if (key < root->data) {
        // If key is lesser than the node, then insert in left
        root->left = insert(root->left, key);
    } else {
        // If key is greater than the node, then insert in right
        root->right = insert(root->right, key);
    }
}

int main() {
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print inorder traversal of the BST
    inorderTraversal(root);
    return 0;
}