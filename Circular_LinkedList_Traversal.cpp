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

    CircularLinkedListTraversal(head);

    return 0;
}