#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int size;
    int f;
    int r;
    int *arr;

    CircularQueue()
    {
        size = 4;
        f = 0;
        r = 0;
        arr = new int[size];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

bool isEmpty(CircularQueue *queue)
{
    if (queue->f == queue->r)
    {
        return true;
    }
    return false;
}

bool isFull(CircularQueue *queue)
{
    if ((queue->r + 1) % queue->size == queue->f)
    {
        return true;
    }
    return false;
}

void enqueue(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        cout << "Queue is full!" << endl;
        return;
    }
    queue->arr[queue->r] = value;
    queue->r = (queue->r + 1) % queue->size;
    cout << "Enqueued element: " << value << endl;
}

int dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int temp = queue->arr[queue->f];
    queue->f = (queue->f + 1) % queue->size;
    return temp;
}

int main()
{
    CircularQueue *queue = new CircularQueue();

    cout << "========= Enqueuing the Queue =========" << endl;
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    cout << "========= Dequeuing the Queue =========" << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;

    delete queue;
    return 0;
}
