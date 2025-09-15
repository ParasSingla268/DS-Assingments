#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed\n";
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

class StackOneQueue
{
    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();
        q.push(x);

        // Rotate the queue to put the new element at front
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed\n";
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    StackTwoQueues s2q;
    StackOneQueue s1q;
    int mainChoice, choice, val;

    do
    {
        cout << "\nChoose Stack Implementation:\n";
        cout << "1. Stack using Two Queues\n";
        cout << "2. Stack using One Queue\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1)
        {
            do
            {
                cout << "\nStack using Two Queues Menu:\n";
                cout << "1. Push\n2. Pop\n3. Top\n4. Back to Implementation Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> val;
                    s2q.push(val);
                    break;
                case 2:
                    s2q.pop();
                    break;
                case 3:
                    val = s2q.top();
                    if (val != -1)
                        cout << "Top element: " << val << "\n";
                    break;
                case 4:
                    cout << "Returning to Implementation Menu...\n";
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice != 4);
        }
        else if (mainChoice == 2)
        {
            do
            {
                cout << "\nStack using One Queue Menu:\n";
                cout << "1. Push\n2. Pop\n3. Top\n4. Back to Implementation Menu\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> val;
                    s1q.push(val);
                    break;
                case 2:
                    s1q.pop();
                    break;
                case 3:
                    val = s1q.top();
                    if (val != -1)
                        cout << "Top element: " << val << "\n";
                    break;
                case 4:
                    cout << "Returning to Implementation Menu...\n";
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice != 4);
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }
    } while (mainChoice != 3);

    return 0;
}