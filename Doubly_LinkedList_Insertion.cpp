#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;

    Node() {};
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

Node *InsertionAtFront(Node *head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    head->prev = new_node;
    new_node->prev = NULL;
    return new_node;
}

Node *InsertionAtIndex(Node *head, int data, int index)
{
    Node *new_node = new Node(data);
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = new_node;
    q->prev = new_node;
    new_node->prev = p;
    new_node->next = q;
    return head;
}

Node *InsertionAtEnd(Node *head, int data)
{
    Node *new_node = new Node(data);
    Node *p = head;

    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    p->next = new_node;
    new_node->prev = p;
    new_node->next = NULL;
    return head;
}

Node *InsertionAfterANode(Node *head, Node *prevNode, int data)
{
    Node *new_node = new Node(data);

    Node *nextNode = prevNode->next;
    prevNode->next = new_node;
    new_node->prev = prevNode;
    new_node->next = nextNode;
    return head;
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

    cout << "Doubly Linked List before insertion" << endl;
    DoublyLinkedListTraversal(head);
    cout << "Doubly LinkedIn Linked List after insertion" << endl;
    // head = InsertionAtFront(head, 50);
    // head = InsertionAtIndex(head, 50, 2);
    // head = InsertionAtEnd(head, 50);
    head = InsertionAfterANode(head, second, 50);
    DoublyLinkedListTraversal(head);

    return 0;
}