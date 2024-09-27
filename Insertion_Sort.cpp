#include <iostream>
using namespace std;

void insertionSort(int *array, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " ============ Array before sorting ============" << endl;
    printArray(arr, n);

    insertionSort(arr, n);

    cout << " ============ Array after sorting ============" << endl;
    printArray(arr, n);
    return 0;
}