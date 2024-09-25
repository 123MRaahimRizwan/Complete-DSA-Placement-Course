#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
};

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return true;
    }
    return false;
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return true;
    }
    return false;
}

void push(Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        cout << "Cannot push anymore, because the stack is full." << endl;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Cannot pop anymore, because the stack is empty." << endl;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int peek(Stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        cout << "Not a valid position in the stack." << endl;
        return -1;
    }
    return ptr->arr[arrayInd];
}

int stackTop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Empty stack." << endl;
        return -1;
    }
    return ptr->arr[ptr->top];
}

int stackBottom(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Empty stack." << endl;
        return -1;
    }
    return ptr->arr[0];
}

int main()
{
    Stack *sp;
    sp->top = -1;
    sp->size = 10;
    sp->arr = new int[sp->size];

    cout << "============ Push Method ============" << endl;
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    cout << "Values pushed successfully." << endl;

    cout << "============ Pop Method ============" << endl;
    cout << "The upper most value is " << pop(sp) << endl;

    cout << "============ Peek Method ============" << endl;
    for (int i = 1; i <= sp->top + 1; i++)
    {
        cout << " " << peek(sp, i) << endl;
    }

    cout << "============ Stack Top Method ============" << endl;
    cout << "The uppermost value is " << stackTop(sp) << endl;

    cout << "============ Stack Bottom Method ============" << endl;
    cout << "The bottommost value is " << stackBottom(sp) << endl;

    return 0;
}