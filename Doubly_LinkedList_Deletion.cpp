#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
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

Node *DeletionOfFirstNode(Node *head)
{
    Node *nodeToDelete = head;
    Node *newHead = head->next;

    if (newHead != NULL)
    {
        newHead->prev = NULL;
    }
    delete nodeToDelete;
    return newHead;
}

Node *DeletionOfNodeAtAGivenIndex(Node *head, int index)
{
    Node *p = head;
    Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
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
        q->next->prev = p;
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
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = NULL;
    fourth->prev = third;

    cout << "Doubly Linked List before deletion" << endl;
    DoublyLinkedListTraversal(head);
    cout << "Doubly Linked List after deletion" << endl;
    // head = DeletionOfFirstNode(head);
    // head = DeletionOfNodeAtAGivenIndex(head, 2);
    // head = DeletionOfLastNode(head);
    head = DeletionOfNodeAtAGivenValue(head, 20);
    DoublyLinkedListTraversal(head);
    return 0;
}