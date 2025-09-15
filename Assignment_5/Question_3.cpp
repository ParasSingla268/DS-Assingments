#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void findMiddle()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }
};

int main()
{
    SinglyLinkedList list;
    // Example input: 1->2->3->4->5
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        list.insertAtEnd(arr[i]);

    cout << "List: ";
    list.display();

    list.findMiddle();

    return 0;
}