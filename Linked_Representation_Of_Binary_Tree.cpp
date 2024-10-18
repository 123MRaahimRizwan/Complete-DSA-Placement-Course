#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data) {};
    Node() {};
};

Node *createNode(int data)
{
    Node *newNode = new Node(data); // Creating a new node and initializing the data
    newNode->left = NULL;           // Initializing the left and right nodes to NULL
    newNode->right = NULL;          // Initializing the left and right nodes to NULL
    return newNode;                 // returning the newly created node
}

int main()
{
    // Creating the binary tree
    Node *root = createNode(10);
    Node *second = createNode(20);
    Node *third = createNode(30);

    // Linking the nodes of the tree together
    root->left = second;
    root->right = third;
    return 0;
}