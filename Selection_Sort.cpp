#include <iostream>
using namespace std;

void selectionSort(int *array, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = array[i];
        array[i] = array[indexOfMin];
        array[indexOfMin] = temp;
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

    selectionSort(arr, n);

    cout << " ============ Array after sorting ============" << endl;
    printArray(arr, n);
    return 0;
}