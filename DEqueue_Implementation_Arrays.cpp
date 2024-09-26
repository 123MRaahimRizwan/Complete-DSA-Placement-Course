#include <iostream>
using namespace std;

class Dequeue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    Dequeue(int k)
    {
        size = k;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    ~Dequeue()
    {
        delete[] arr;
    }
};

bool isEmpty(Dequeue *dequeue)
{
    if (dequeue->front == -1)
    {
        return true;
    }
    return false;
}

bool isFull(Dequeue *dequeue)
{
    if (dequeue->rear == dequeue->size - 1)
    {
        return true;
    }
    return false;
}

bool insertFront(Dequeue *dequeue, int val)
{
    if (dequeue->front == 0)
    {
        cout << "Queue is full at front!" << endl;
        return false;
    }
    if (isEmpty(dequeue))
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else
    {
        dequeue->front--;
    }
    dequeue->arr[dequeue->front] = val;
    cout << "Enqueued element from front: " << val << endl;
    return true;
}

bool insertLast(Dequeue *dequeue, int val)
{
    if (isFull(dequeue))
    {
        cout << "Queue is full at rear!" << endl;
        return false;
    }
    if (isEmpty(dequeue))
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else
    {
        dequeue->rear++;
    }
    dequeue->arr[dequeue->rear] = val;
    cout << "Enqueued element from rear: " << val << endl;
    return true;
}

bool deleteFront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "Queue is empty!" << endl;
        return false;
    }
    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = dequeue->rear = -1; // Queue becomes empty
    }
    else
    {
        dequeue->front++;
    }
    return true;
}

bool deleteLast(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "Queue is empty!" << endl;
        return false;
    }
    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = dequeue->rear = -1; // Queue becomes empty
    }
    else
    {
        dequeue->rear--;
    }
    return true;
}

int getFront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return -1;
    }
    return dequeue->arr[dequeue->front];
}

int getRear(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return -1;
    }
    return dequeue->arr[dequeue->rear];
}

int main()
{
    Dequeue *dequeue = new Dequeue(10);
    insertLast(dequeue, 1);
    insertLast(dequeue, 2);
    insertFront(dequeue, 3);
    insertFront(dequeue, 4);

    deleteFront(dequeue);
    deleteLast(dequeue);
}
