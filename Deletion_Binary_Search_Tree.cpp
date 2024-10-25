#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data): data(data), left(NULL), right(NULL) {} 
        Node () {};
};

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

Node *inorderPredecessor(Node *root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int value) {
    Node *iPre;

    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) { // Condition for finding leaf node
        delete root;
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value); // If value is less then search in left subtree
    } 
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);// If value is less then search in right subtree
    } 
    else {
        // If we found the node to be deleted
        iPre = inorderPredecessor(root); // Calculating the inorder predecessor
        root->data = iPre->data; 
        root->left = deleteNode(root->left, iPre->data); // Deleting the inorder predecessor's value
    }
    return root;
}

int main() {
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    Node *second = new Node(30);
    Node *third = new Node(70);
    Node *fourth = new Node(20);
    Node *fifth = new Node(40);
    Node *sixth = new Node(60);
    Node *seventh = new Node(80);

    root->left = second;
    root->right = third;

    second->left = fourth;
    second->right = fifth;

    third->left = sixth;
    third->right = seventh;

    cout << "=========== Before Deletion ===========" << endl;
    inorderTraversal(root);

    root = deleteNode(root, 50);
    cout << endl;

    cout << "=========== After Deletion ===========" << endl;
    inorderTraversal(root);

    return 0;
}