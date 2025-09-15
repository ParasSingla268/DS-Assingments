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

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    SinglyLinkedList list;
    // Example input: 1->2->3->4->NULL
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        list.insertAtEnd(arr[i]);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}