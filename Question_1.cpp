#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {12, 22, 25, 34, 64, 90};
    int target;
    cout << "Enter the number to search: ";
    cin >> target;
    int left = 0, right = arr.size() - 1, found = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            found = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (found != -1)
    {
        cout << "Element found at index: " << found << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    return 0;
}
