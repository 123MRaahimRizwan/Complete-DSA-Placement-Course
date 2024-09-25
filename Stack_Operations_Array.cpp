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
    else
    {
        return false;
    }
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        cout << "Stack is full" << endl;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int val = ptr->arr[ptr->top]; // topmost value ko val main dal rahe hain
    ptr->top--;
    return val;
}

int main()
{
    Stack *sp = new Stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int[sp->size];
    cout << "Stack created successfully" << endl;

    // isEmpty(sp) ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
    // isFull(sp) ? cout << "Stack is full" << endl : cout << "Stack is not full" << endl;

    cout << "Before pushing" << endl;
    cout << "Full: " << isFull(sp) << endl;
    cout << "Empty: " << isEmpty(sp) << endl;

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5); // topmost element hai ye
    // push(sp, 10); Stack overflow, ha ha nice joke na!

    cout << "After pushing" << endl;
    cout << "Full: " << isFull(sp) << endl;
    cout << "Empty: " << isEmpty(sp) << endl;

    cout << "popped " << pop(sp) << " from the stack" << endl;
    return 0;
}