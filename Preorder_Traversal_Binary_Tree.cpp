#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL) {};
    Node() {};
};

void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";      // Printing the node's data
        preorderTraversal(root->left);  // recursively calling the left subtree as Root - Left - Right
        preorderTraversal(root->right); // recursively calling the right subtree as Root - Left - Right
    }
}

int main()
{
    // Creating the nodes
    Node *root = new Node(7);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(1);
    Node *fifth = new Node(4);

    // Linking the nodes together to form a binary tree
    root->left = second;
    root->right = third;

    second->left = fourth;
    second->right = NULL;

    third->left = NULL;
    third->right = fifth;

    preorderTraversal(root);
    return 0;
}