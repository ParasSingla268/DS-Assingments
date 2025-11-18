#include <iostream>

using namespace std;

struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;
};

struct CircularNode
{
    int data;
    CircularNode *next;
};

DoublyNode *createDoublyNode(int data)
{
    DoublyNode *newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

CircularNode *createCircularNode(int data)
{
    CircularNode *newNode = new CircularNode();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int getDoublySize(DoublyNode *head)
{
    int size = 0;
    DoublyNode *temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

int getCircularSize(CircularNode *head)
{
    if (head == nullptr)
        return 0;
    int size = 0;
    CircularNode *temp = head;
    do
    {
        size++;
        temp = temp->next;
    } while (temp != head);
    return size;
}

int main()
{
    // Sample Doubly List: 1 <-> 2 <-> 3
    DoublyNode *doublyHead = createDoublyNode(1);
    doublyHead->next = createDoublyNode(2);
    doublyHead->next->prev = doublyHead;
    doublyHead->next->next = createDoublyNode(3);
    doublyHead->next->next->prev = doublyHead->next;

    // Sample Circular List: 1 -> 2 -> 3 -> back to 1
    CircularNode *circularHead = createCircularNode(1);
    circularHead->next = createCircularNode(2);
    circularHead->next->next = createCircularNode(3);
    circularHead->next->next->next = circularHead;

    int choice;
    cout << "Menu:\n";
    cout << "1. Size of Doubly Linked List\n";
    cout << "2. Size of Circular Linked List\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Size of Doubly Linked List: " << getDoublySize(doublyHead) << endl;
    }
    else if (choice == 2)
    {
        cout << "Size of Circular Linked List: " << getCircularSize(circularHead) << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
    return 0;
}