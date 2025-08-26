#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 8, 6, 1};
    int inversions = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inversions++;
            }
        }
    }
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
