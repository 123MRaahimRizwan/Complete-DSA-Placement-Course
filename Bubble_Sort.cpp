#include <iostream>
using namespace std;

void bubbleSort(int *array, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *array, int n)
{
    int temp;
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isSorted = false;
            }
        }
    }
    if (isSorted)
    {
        return;
    }
}

void printArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}

int main()
{
    int n = 5;
    int A[] = {10, 2, 30, 45, 59};
    cout << "Array before sorting" << endl;
    printArray(A, n);

    bubbleSort(A, n);
    cout << "Array after sorting" << endl;
    printArray(A, n);
}