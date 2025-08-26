#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    unordered_set<int> distinct(arr.begin(), arr.end());
    cout << "Total distinct elements: " << distinct.size() << endl;
    return 0;
}
