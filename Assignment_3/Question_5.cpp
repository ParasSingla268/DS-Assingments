#include <iostream>
using namespace std;

int main()
{
    string postfix;
    cout << "Enter postfix expression (single digit operands): ";
    getline(cin, postfix);

    int stack[1000];
    int top = -1;

    for (int i = 0; i < (int)postfix.length(); i++)
    {
        char ch = postfix[i];
        if (ch == ' ')
            continue;

        if (ch >= '0' && ch <= '9')
        {
            stack[++top] = ch - '0';
        }
        else
        {
            if (top < 1)
            {
                cout << "Invalid expression\n";
                return 1;
            }
            int b = stack[top--];
            int a = stack[top--];
            int res = 0;

            if (ch == '+')
                res = a + b;
            else if (ch == '-')
                res = a - b;
            else if (ch == '*')
                res = a * b;
            else if (ch == '/')
            {
                if (b == 0)
                {
                    cout << "Division by zero\n";
                    return 1;
                }
                res = a / b;
            }
            else
            {
                cout << "Unknown operator " << ch << "\n";
                return 1;
            }
            stack[++top] = res;
        }
    }

    if (top != 0)
    {
        cout << "Invalid expression\n";
        return 1;
    }

    cout << "Result: " << stack[top] << "\n";
    return 0;
}