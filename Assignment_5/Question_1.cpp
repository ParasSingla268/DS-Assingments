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

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

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

    void insertBefore(int target, int val)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target)
        {
            insertAtBeginning(val);
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr && curr->data != target)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
        {
            cout << "Node with value " << target << " not found.\n";
            return;
        }
        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
    }

    void insertAfter(int target, int val)
    {
        Node *curr = head;
        while (curr && curr->data != target)
            curr = curr->next;
        if (!curr)
        {
            cout << "Node with value " << target << " not found.\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int val)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val)
        {
            deleteFromBeginning();
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
        {
            cout << "Node with value " << val << " not found.\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void searchNode(int val)
    {
        Node *curr = head;
        int pos = 1;
        while (curr)
        {
            if (curr->data == val)
            {
                cout << "Node with value " << val << " found at position " << pos << ".\n";
                return;
            }
            curr = curr->next;
            pos++;
        }
        cout << "Node with value " << val << " not found.\n";
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
};

void menu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert before a node\n";
    cout << "4. Insert after a node\n";
    cout << "5. Delete from beginning\n";
    cout << "6. Delete from end\n";
    cout << "7. Delete a specific node\n";
    cout << "8. Search for a node\n";
    cout << "9. Display list\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    SinglyLinkedList list;
    int choice, val, target;

    while (true)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter target node value to insert before: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertBefore(target, val);
            break;
        case 4:
            cout << "Enter target node value to insert after: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAfter(target, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value of node to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 9:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}