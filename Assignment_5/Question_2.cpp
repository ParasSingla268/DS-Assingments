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

    void countAndDeleteAll(int key)
    {
        int count = 0;
        Node *curr = head;
        // Count occurrences
        while (curr)
        {
            if (curr->data == key)
                count++;
            curr = curr->next;
        }
        cout << "Count: " << count << "\n";

        // Delete all occurrences
        while (head && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        if (!head)
        {
            cout << "Updated Linked List: List is empty.\n";
            return;
        }
        curr = head;
        while (curr->next)
        {
            if (curr->next->data == key)
            {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
        cout << "Updated Linked List: ";
        display();
    }
};

int main()
{
    SinglyLinkedList list;
    // Example input: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        list.insertAtEnd(arr[i]);

    cout << "Original List: ";
    list.display();

    int key = 1;
    cout << "Key to count and delete: " << key << "\n";
    list.countAndDeleteAll(key);

    return 0;
}