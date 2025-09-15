#include <iostream>
using namespace std;

int stack[100];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == 99;
}

void push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
    cout << x << " pushed\n";
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return -1;
    }
    return stack[top];
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int choice, val;
    do
    {
        cout << "\n1.Push \n2.Pop \n3.isEmpty \n4.isFull \n5.Display \n6.Peek \n0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                cout << "Popped: " << val << "\n";
            break;
        case 3:
            cout << (isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 4:
            cout << (isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;
        case 5:
            display();
            break;
        case 6:
            val = peek();
            if (val != -1)
                cout << "Top element: " << val << "\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}