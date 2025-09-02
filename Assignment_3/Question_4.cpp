#include <iostream>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    char stack[1000];
    int top = -1;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix += stack[top--];
            }
            if (top != -1)
                top--; // pop '('
        }
        else
        { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix += stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1)
    {
        postfix += stack[top--];
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression (single letter operands): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << "\n";

    return 0;
}