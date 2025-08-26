#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6}; // Missing 5
    int n = arr.size();
    
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i+1] != arr[i] + 1){
            cout<<"Missing number is: "<<arr[i]+1;
            break;
        }
    }
    
    return 0;
}
