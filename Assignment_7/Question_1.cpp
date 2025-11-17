#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (true)
    {
        cout << "\nSorting Techniques Menu:\n";
        cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 6)
            break;
        int *temp = new int[n];
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];
        switch (choice)
        {
        case 1:
            selectionSort(temp, n);
            cout << "Sorted array using Selection Sort: ";
            printArray(temp, n);
            break;
        case 2:
            insertionSort(temp, n);
            cout << "Sorted array using Insertion Sort: ";
            printArray(temp, n);
            break;
        case 3:
            bubbleSort(temp, n);
            cout << "Sorted array using Bubble Sort: ";
            printArray(temp, n);
            break;
        case 4:
            mergeSort(temp, 0, n - 1);
            cout << "Sorted array using Merge Sort: ";
            printArray(temp, n);
            break;
        case 5:
            quickSort(temp, 0, n - 1);
            cout << "Sorted array using Quick Sort: ";
            printArray(temp, n);
            break;
        default:
            cout << "Invalid choice.\n";
        }
        delete[] temp;
    }
    delete[] arr;
    return 0;
}