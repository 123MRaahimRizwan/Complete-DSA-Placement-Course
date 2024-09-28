#include <iostream>
using namespace std;

int partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            // Swap ith and jth value
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

    } while (i < j);

    // swap pivot and jth value
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}

void quickSort(int *array, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

void printArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {12, 3, 14, 5, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int low = 0;
    int high = n - 1;
    cout << "======== Array before sorting ========" << endl;
    printArray(A, n);
    cout << "======== Array after sorting ========" << endl;
    quickSort(A, low, high);
    printArray(A, n);

    return 0;
}