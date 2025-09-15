#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Queue size must be even to interleave\n";
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Push first half elements into firstHalf queue
    for (int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave elements
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even number): ";
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "Number of elements must be even\n";
        return 0;
    }

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}