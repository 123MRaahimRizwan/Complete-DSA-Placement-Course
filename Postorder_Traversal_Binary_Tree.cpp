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

void postOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);  // Recursively calling the left subtree as Left - Right - Root
        postOrderTraversal(root->right); // Recursively calling the left subtree as Left - Right - Root
        cout << root->data << " ";       // Printing the root node's data
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

    // Calling the traversal function
    postOrderTraversal(root);
    return 0;
}