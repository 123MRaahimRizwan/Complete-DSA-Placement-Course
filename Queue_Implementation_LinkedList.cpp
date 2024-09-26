#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(NULL) {}
};

Node *f = NULL;
Node *r = NULL;

void LinkedListTraversal(Node *ptr)
{
    cout << "Printing the elements of the linked list:" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    Node *n = new Node(val);
    if (n == NULL)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
        cout << "Enqueued element: " << val << endl;
    }
}

int dequeue()
{
    int val = -1;
    Node *ptr = f;
    if (ptr == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        delete ptr;
    }
    return val;
}

int main()
{
    LinkedListTraversal(f);
    cout << "Dequeuing element: " << dequeue() << endl;

    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);

    cout << "Dequeuing element: " << dequeue() << endl;
    cout << "Dequeuing element: " << dequeue() << endl;
    cout << "Dequeuing element: " << dequeue() << endl;
    cout << "Dequeuing element: " << dequeue() << endl;

    LinkedListTraversal(f);
    return 0;
}
