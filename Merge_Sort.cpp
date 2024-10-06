#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int i, j, k, B[high + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void printArray(int array[], int n)
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
    mergeSort(A, low, high);
    printArray(A, n);
    return 0;
}