#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev; // only new line addition.
    int data;

    Node() {}
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

void DoublyLinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = NULL;
    fourth->prev = third;

    DoublyLinkedListTraversal(head);
    return 0;
}