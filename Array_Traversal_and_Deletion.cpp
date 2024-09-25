#include <iostream>
using namespace std;

void traversal(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int deletionAtIndex(int array[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    return 1;
}

int main()
{
    int array[100] = {1, 2, 3, 4, 5};
    int size = 5, index = 3;
    traversal(array, size); // Before deletion
    deletionAtIndex(array, size, index);
    size -= 1;
    traversal(array, size); // After deletion
    return 0;
}