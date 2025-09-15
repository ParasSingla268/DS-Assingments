#include <iostream>
using namespace std;

#define MAX 5

class SimpleQueue
{
    int arr[MAX];
    int front, rear;

public:
    SimpleQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = val;
        cout << val << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    SimpleQueue q;
    int choice, val;

    do
    {
        cout << "\nSimple Queue Menu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
            break;
        case 6:
            cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
