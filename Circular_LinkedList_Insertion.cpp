#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node() {};
    Node(int data) : data(data), next(NULL) {}
};

void CircularLinkedListTraversal(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *InsertionAtBeginning(Node *head, int data)
{
    Node *p = head->next;
    Node *ptr = new Node(data);

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

Node *InsertionAtIndex(Node *head, int data, int index)
{
    Node *p = head;
    Node *q = head->next;
    Node *ptr = new Node(data);

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = ptr;
    ptr->next = q;
    return head;
}

Node *InsertionAtEnd(Node *head, int data)
{
    Node *p = head;
    Node *ptr = new Node(data);

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

Node *InsertionAfterANode(Node *head, Node *prevNode, int data)
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
    Node *fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    cout << "Linked List before insertion" << endl;
    CircularLinkedListTraversal(head);
    cout << "Linked List after insertion" << endl;
    // head = InsertionAtBeginning(head, 50);
    // head = InsertionAtIndex(head, 60, 2);
    // head = InsertionAtEnd(head, 60);
    head = InsertionAfterANode(head, third, 60);
    CircularLinkedListTraversal(head);
    return 0;
}