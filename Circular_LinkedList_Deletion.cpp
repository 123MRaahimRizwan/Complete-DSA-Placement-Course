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

void CircularLinkedListTraversal(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *DeletionOfFirstNode(Node *head)
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    Node *newHead = head->next;
    delete head;
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
    delete q;
    return head;
}

Node *DeletionOfLastNode(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    delete q;
    return head;
}

Node *DeletionOfNodeAtAGivenValue(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;

    while (q->data != value && q->next != head)
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
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    cout << "Linked List before deletion" << endl;
    CircularLinkedListTraversal(head);
    cout << "Linked List after deletion" << endl;
    // head = DeletionOfFirstNode(head);
    // head = DeletionOfNodeAtAGivenIndex(head, 2);
    // head = DeletionOfLastNode(head);
    head = DeletionOfNodeAtAGivenValue(head, 20);
    CircularLinkedListTraversal(head);
    return 0;
}