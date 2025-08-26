#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int choice;
    cout << "String Related Programs:\n";
    cout << "1. Concatenate Strings\n";
    cout << "2. Reverse String\n";
    cout << "3. Delete Vowels from String\n";
    cout << "4. Sort Strings Alphabetically\n";
    cout << "5. Convert Uppercase to Lowercase\n";
    cout << "Enter your choice: ";
    cin >> choice;

    string str1, str2;
    vector<string> strings;
    string result;

    switch (choice)
    {
    case 1:
        cout << "Enter first string: ";
        cin >> str1;
        cout << "Enter second string: ";
        cin >> str2;
        cout << "Concatenated string: " << str1 + str2 << endl;
        break;
    case 2:
        cout << "Enter string to reverse: ";
        cin >> str1;
        reverse(str1.begin(), str1.end());
        cout << "Reversed string: " << str1 << endl;
        break;
    case 3:
        cout << "Enter string: ";
        cin >> str1;

        for (char c : str1)
        {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            {
                result += c;
            }
        }
        cout << "String after deleting vowels: " << result << endl;
        break;
    case 4:
        cout << "Enter number of strings: ";
        int count;
        cin >> count;
        strings.resize(count);
        cout << "Enter strings:\n";
        for (int i = 0; i < count; i++)
        {
            cin >> strings[i];
        }
        sort(strings.begin(), strings.end());
        cout << "Sorted strings: ";
        for (const string &s : strings)
        {
            cout << s << " ";
        }
        cout << endl;
        break;
    case 5:
        cout << "Enter character to convert: ";
        char ch;
        cin >> ch;
        cout << "Lowercase: " << (char)tolower(ch) << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
    }
    return 0;
}
