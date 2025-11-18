#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;
    bool isMaxHeap;

    void heapifyUp(int index)
    {
        if (index && compare(heap[index], heap[(index - 1) / 2]))
        {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int extreme = index;

        if (left < (int)heap.size() && compare(heap[left], heap[extreme]))
        {
            extreme = left;
        }
        if (right < (int)heap.size() && compare(heap[right], heap[extreme]))
        {
            extreme = right;
        }
        if (extreme != index)
        {
            swap(heap[index], heap[extreme]);
            heapifyDown(extreme);
        }
    }

    bool compare(int a, int b)
    {
        return isMaxHeap ? (a > b) : (a < b);
    }

public:
    PriorityQueue(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
        {
            cout << "Priority queue empty\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    int top()
    {
        if (heap.empty())
        {
            cout << "Priority queue empty\n";
            return -1; // or throw exception
        }
        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }

    void display()
    {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    int choice;
    cout << "Priority Queue using Heap\n";
    cout << "1. Max Priority Queue\n2. Min Priority Queue\nChoose type: ";
    cin >> choice;

    PriorityQueue pq(choice == 1);

    while (true)
    {
        cout << "\nOperations Menu:\n1. Insert\n2. Delete Top\n3. Show Top\n4. Display Queue\n5. Exit\nEnter choice: ";
        int op;
        cin >> op;

        if (op == 5)
            break;

        int val;

        switch (op)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            pq.push(val);
            break;
        case 2:
            pq.pop();
            break;
        case 3:
            val = pq.top();
            if (val != -1)
                cout << "Top element: " << val << endl;
            break;
        case 4:
            cout << "Current Priority Queue: ";
            pq.display();
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}