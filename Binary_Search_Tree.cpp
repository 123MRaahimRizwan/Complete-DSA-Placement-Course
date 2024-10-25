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

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

bool isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;
        return isBST(root->right);
    }
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

    cout << "========== Traversing the Tree ==========" << endl;
    inorderTraversal(root);
    cout << "========== Is the Tree BST or Not ==========" << endl;

    if (isBST(root))
        cout << "This tree is a Binary Search Tree" << endl;
    else
        cout << "This tree is not a Binary Search Tree" << endl;

    return 0;
}
