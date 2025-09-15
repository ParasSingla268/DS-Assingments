#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    char arr[1000];
    int top = -1;

    for (int i = 0; i < s.length(); i++)
    {
        arr[++top] = s[i];
    }

    string rev = "";

    while (top >= 0)
    {
        rev += arr[top--];
    }

    cout << "Reversed string: " << rev << "\n";
    return 0;

}