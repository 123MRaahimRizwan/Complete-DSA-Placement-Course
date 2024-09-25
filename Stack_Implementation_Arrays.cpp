#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(Stack *ptr)
{
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

int main()
{
    // Allocate memory for the Stack object
    Stack *s = new Stack;
    s->top = -1;
    s->size = 6;
    s->arr = new int[s->size]; // Allocate memory based on stack size

    s->arr[0] = 7;
    s->top++;

    // Check if the stack is empty
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    // Check if the stack is full

    if (isFull(s))
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }

    // Clean up memory
    delete[] s->arr;
    delete s;

    return 0;
}
