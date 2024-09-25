#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;
};

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

void push(Stack *ptr, char value)
{
    if (isFull(ptr))
    {
        cout << "Stack is full!" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty!" << endl;
        return '\0'; // Return null char in case of empty stack
    }
    char value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

int parenthesisMatching(char *exp)
{
    // Create and initialize the stack
    Stack *sp = new Stack; // Allocate memory for Stack object
    sp->size = 20;
    sp->top = -1;
    sp->arr = new char[sp->size];

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    int result = isEmpty(sp); // If stack is empty, the parentheses are balanced

    delete[] sp->arr; // Free memory allocated for array
    delete sp;        // Free memory allocated for stack

    return result;
}

int main()
{
    char *exp = "{8}+[3]*(2+1)";
    if (parenthesisMatching(exp))
    {
        cout << "String is balanced" << endl;
    }
    else
    {
        cout << "String is not balanced" << endl;
    }
    return 0;
}
