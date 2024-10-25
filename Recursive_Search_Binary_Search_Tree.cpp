#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
    Node() {}
};

Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;

    else if (key < root->data)
        return search(root->left, key); // Searching in left subtree
    else
        return search(root->right, key); // Searching in right subtree
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

    Node *n = search(root, 1);
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
