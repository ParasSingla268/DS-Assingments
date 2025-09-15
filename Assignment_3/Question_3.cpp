#include <iostream>
using namespace std;

bool isBalanced(string expr)
{
    char stack[1000];
    int top = -1;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return false;
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
                return false;
        }
    }
    return top == -1;
}

int main()
{
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}