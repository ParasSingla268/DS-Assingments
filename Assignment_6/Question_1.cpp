#include <iostream>

using namespace std;

// Node structure for Doubly Linked List
struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;
};

// Node structure for Circular Linked List (singly linked, circular)
struct CircularNode
{
    int data;
    CircularNode *next;
};

// Function to create a new Doubly Node
DoublyNode *createDoublyNode(int data)
{
    DoublyNode *newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to create a new Circular Node
CircularNode *createCircularNode(int data)
{
    CircularNode *newNode = new CircularNode();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Doubly Linked List Operations
void insertDoublyFirst(DoublyNode *&head, int data)
{
    DoublyNode *newNode = createDoublyNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertDoublyLast(DoublyNode *&head, int data)
{
    DoublyNode *newNode = createDoublyNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    DoublyNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertDoublyAfter(DoublyNode *&head, int key, int data)
{
    DoublyNode *temp = head;
    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Key not found." << endl;
        return;
    }
    DoublyNode *newNode = createDoublyNode(data);
    newNode->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertDoublyBefore(DoublyNode *&head, int key, int data)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == key)
    {
        insertDoublyFirst(head, data);
        return;
    }
    DoublyNode *temp = head;
    while (temp->next != nullptr && temp->next->data != key)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        cout << "Key not found." << endl;
        return;
    }
    DoublyNode *newNode = createDoublyNode(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteDoublyNode(DoublyNode *&head, int key)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    DoublyNode *temp = head;
    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Key not found." << endl;
        return;
    }
    if (temp == head)
    {
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
    }
    else
    {
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
    }
    delete temp;
}

bool searchDoubly(DoublyNode *head, int key)
{
    DoublyNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void displayDoubly(DoublyNode *head)
{
    DoublyNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Circular Linked List Operations
void insertCircularFirst(CircularNode *&head, int data)
{
    CircularNode *newNode = createCircularNode(data);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        return;
    }
    CircularNode *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertCircularLast(CircularNode *&head, int data)
{
    CircularNode *newNode = createCircularNode(data);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        return;
    }
    CircularNode *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void insertCircularAfter(CircularNode *&head, int key, int data)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    CircularNode *temp = head;
    do
    {
        if (temp->data == key)
        {
            CircularNode *newNode = createCircularNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found." << endl;
}

void insertCircularBefore(CircularNode *&head, int key, int data)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == key)
    {
        insertCircularFirst(head, data);
        return;
    }
    CircularNode *temp = head;
    do
    {
        if (temp->next->data == key)
        {
            CircularNode *newNode = createCircularNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found." << endl;
}

void deleteCircularNode(CircularNode *&head, int key)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    CircularNode *temp = head;
    CircularNode *prev = nullptr;
    do
    {
        if (temp->data == key)
        {
            if (temp == head && temp->next == head)
            {
                head = nullptr;
            }
            else if (temp == head)
            {
                CircularNode *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found." << endl;
}

bool searchCircular(CircularNode *head, int key)
{
    if (head == nullptr)
        return false;
    CircularNode *temp = head;
    do
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

void displayCircular(CircularNode *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    CircularNode *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    DoublyNode *doublyHead = nullptr;
    CircularNode *circularHead = nullptr;
    int choice, listChoice, opChoice, data, key;

    while (true)
    {
        cout << "\nMain Menu:\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> listChoice;

        if (listChoice == 3)
            break;

        while (true)
        {
            cout << "\nOperations Menu:\n";
            cout << "1. Insert First\n";
            cout << "2. Insert Last\n";
            cout << "3. Insert After Specific Node\n";
            cout << "4. Insert Before Specific Node\n";
            cout << "5. Delete Specific Node\n";
            cout << "6. Search for a Node\n";
            cout << "7. Display List\n";
            cout << "8. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> opChoice;

            if (opChoice == 8)
                break;

            switch (opChoice)
            {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                if (listChoice == 1)
                    insertDoublyFirst(doublyHead, data);
                else
                    insertCircularFirst(circularHead, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                if (listChoice == 1)
                    insertDoublyLast(doublyHead, data);
                else
                    insertCircularLast(circularHead, data);
                break;
            case 3:
                cout << "Enter key and data: ";
                cin >> key >> data;
                if (listChoice == 1)
                    insertDoublyAfter(doublyHead, key, data);
                else
                    insertCircularAfter(circularHead, key, data);
                break;
            case 4:
                cout << "Enter key and data: ";
                cin >> key >> data;
                if (listChoice == 1)
                    insertDoublyBefore(doublyHead, key, data);
                else
                    insertCircularBefore(circularHead, key, data);
                break;
            case 5:
                cout << "Enter key to delete: ";
                cin >> key;
                if (listChoice == 1)
                    deleteDoublyNode(doublyHead, key);
                else
                    deleteCircularNode(circularHead, key);
                break;
            case 6:
                cout << "Enter key to search: ";
                cin >> key;
                if (listChoice == 1)
                {
                    if (searchDoubly(doublyHead, key))
                        cout << "Found\n";
                    else
                        cout << "Not Found\n";
                }
                else
                {
                    if (searchCircular(circularHead, key))
                        cout << "Found\n";
                    else
                        cout << "Not Found\n";
                }
                break;
            case 7:
                if (listChoice == 1)
                    displayDoubly(doublyHead);
                else
                    displayCircular(circularHead);
                break;
            default:
                cout << "Invalid choice.\n";
            }
        }
    }
    return 0;
}