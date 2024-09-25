#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node() {}
    Node(int data) : data(data), next(NULL) {}
};

void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *DeletionOfFirstNode(Node *head)
{
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

Node *DeletionOfNodeAtAGivenIndex(Node *head, int index)
{
    Node *p = head;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = q->next;
    delete q;
    return head;
}

Node *DeletionOfLastNode(Node *head)
{
    Node *p = head;
    Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
    return head;
}

Node *DeletionOfNodeAtAGivenValue(Node *head, int value)
{
    Node *p = head;
    Node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }
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
    fourth->next = NULL;

    cout << "Linked List before Deletion" << endl;
    LinkedListTraversal(head);
    cout << "Linked List after Deletion" << endl;
    // head = DeletionOfFirstNode(head);
    // head = DeletionOfNodeAtAGivenIndex(head, 2);
    // head = DeletionOfLastNode(head);
    head = DeletionOfNodeAtAGivenValue(head, 100);
    LinkedListTraversal(head);
    return 0;
}