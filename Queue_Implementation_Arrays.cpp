#include <iostream>
using namespace std;

// This is a single Linear Queue
class Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;

    Queue()
    {
        size = 100;
        f = -1;
        r = -1;
        arr = new int[size];
    }

    ~Queue()
    {
        delete[] arr;
    }
};

bool isFull(Queue *queue)
{
    if (queue->r == queue->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(Queue *queue)
{
    if (queue->f == queue->r)
    {
        return true;
    }
    return false;
}

void enqueue(Queue *queue, int val)
{
    if (isFull(queue))
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        queue->r++;
        queue->arr[queue->r] = val;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else
    {
        int temp = queue->arr[queue->f];
        queue->f++;
        return temp;
    }
}

int main()
{
    Queue *queue = new Queue;

    cout << "========= Enqueuing the Queue =========" << endl;
    enqueue(queue, 12);
    enqueue(queue, 34);

    cout << "========= Dequeuing the Queue =========" << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;

    delete queue;
    return 0;
}
