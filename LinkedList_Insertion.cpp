#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data) : data(data), next(NULL) {}
    Node() {};
};

void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *InsertionAtBeginning(Node *head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    return new_node;
}

Node *InsertionAtIndex(Node *head, int data, int index)
{
    Node *new_node = new Node(data);
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    new_node->next = p->next;
    p->next = new_node;
    return head;
}

Node *InsertionAtEnd(Node *head, int data)
{
    Node *new_node = new Node(data);
    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new_node;
    new_node->next = NULL;
    return head;
}

Node *InsertionAfterNode(Node *head, Node *prevNode, int data)
{
    Node *new_node = new Node(data);

    new_node->next = prevNode->next;
    prevNode->next = new_node;
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    cout << "Linked List before insertion" << endl;
    LinkedListTraversal(head);
    cout << endl;
    cout << "Linked List after insertion" << endl;
    // head = InsertionAtBeginning(head, 50);
    // head = InsertionAtIndex(head, 50, 2);
    // head = InsertionAtEnd(head, 50);
    head = InsertionAfterNode(head, third, 50);
    LinkedListTraversal(head);
    return 0;
}