#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int arr[MAX];
    int front, rear;

public:
    CircularQueue()
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
        return (front == (rear + 1) % MAX);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Circular Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = val;
        cout << val << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty\n";
            return;
        }
        cout << "Circular Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main()
{
    CircularQueue q;
    int choice, val;

    do
    {
        cout << "\nCircular Queue Menu:\n";
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
            cout << (q.isEmpty() ? "Circular Queue is empty\n" : "Circular Queue is not empty\n");
            break;
        case 6:
            cout << (q.isFull() ? "Circular Queue is full\n" : "Circular Queue is not full\n");
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