#include <iostream>
#include <stdlib.h>
using namespace std;

void traversal(int array[], int size, int capacity)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int insertionAtIndex(int array[], int size, int element, int index, int capacity)
{
    if (size >= capacity)
    {
        cout << "Size cannot be greater than capacity" << endl;
        exit(1);
    }
    for (int i = size - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;
    return 1;
}

int main()
{
    int array[100] = {1, 2, 3, 4, 5};
    int size = 5, element = 45, index = 3, capacity = 100;
    traversal(array, size, capacity);
    insertionAtIndex(array, size, element, index, capacity);
    size += 1;
    traversal(array, size, capacity);
    return 0;
}