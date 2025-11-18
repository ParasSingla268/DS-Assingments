#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing = true)
{
    int extreme = i; // index of max or min element depending on increasing
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing)
    {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    else
    {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i)
    {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing = true)
{
    // build max heap for increasing sort or min heap for decreasing
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Heap Sort Menu:\n1. Increasing order\n2. Decreasing order\nEnter choice: ";
    int ch;
    cin >> ch;

    if (ch == 1)
        heapSort(arr, n, true);
    else
        heapSort(arr, n, false);

    cout << "Sorted array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}