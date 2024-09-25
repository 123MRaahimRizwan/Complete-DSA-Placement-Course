#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int data) : data(data), next(NULL) {}
};

void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

int isFull(Node *top)
{
    Node *ptr = new Node();
    if (ptr == NULL)
    {
        return true;
    }
    return false;
}

Node *push(Node *top, int value)
{
    if (isFull(top))
    {
        cout << "Stack is full" << endl;
    }
    Node *n = new Node(value);
    n->next = top;
    top = n;
    return top;
}

int pop(Node *&top) // Here passing by reference is necessary to change the original value of top
{
    if (isEmpty(top))
    {
        cout << "Stack is empty" << endl;
    }
    Node *n = top;
    top = top->next;
    int x = n->data;
    delete n;
    return x;
}

int peek(Node *top, int pos)
{
    Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty" << endl;
    }
    return top->data;
}

int stackBottom(Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty" << endl;
    }
    Node *p = top;
    // Node *q = top->next;
    while (p->next != NULL)
    {
        p = p->next;
        // q = q->next;
    }
    // delete q;
    return p->data;
}

int main()
{
    Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);

    cout << "============== Stack before popping ==============" << endl;
    LinkedListTraversal(top);

    cout << "============== Popped element ==============" << endl;
    cout << pop(top) << endl;

    cout << "============== Stack after popping ==============" << endl;
    LinkedListTraversal(top);

    cout << "============== Peek Method ==============" << endl;
    cout << peek(top, 1) << endl;

    cout << "============== Stack Top Method ==============" << endl;
    cout << stackTop(top) << endl;

    cout << "============== Stack Bottom Method ==============" << endl;
    cout << stackBottom(top) << endl;

    return 0;
}