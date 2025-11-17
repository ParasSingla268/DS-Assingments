#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        int minIndex = start, maxIndex = start;
        for (int i = start + 1; i <= end; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum element with start
        swap(arr[start], arr[minIndex]);

        // If max element was at start, it is now at minIndex after swap
        if (maxIndex == start)
            maxIndex = minIndex;

        // Swap maximum element with end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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

    improvedSelectionSort(arr, n);

    cout << "Array after improved selection sort:\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}