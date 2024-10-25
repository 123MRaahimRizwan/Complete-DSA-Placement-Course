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

Node *searchIterative(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL; // If key is not found, return NULL
}

int main()
{
    Node *root = new Node(5);
    Node *second = new Node(3);
    Node *third = new Node(6);
    Node *fourth = new Node(1);
    Node *fifth = new Node(4);

    root->left = second;
    root->right = third;

    second->left = fourth;
    second->right = fifth;
    /*
              5
             / \
            3   6
           / \
          1   4
    */
    Node *n = searchIterative(root, 10);
    if (n != NULL)
        cout << n->data << " found" << endl;
    else
        cout << "Element not found" << endl;

    // Clean up memory
    delete fifth;
    delete fourth;
    delete second;
    delete third;
    delete root;
    return 0;
}