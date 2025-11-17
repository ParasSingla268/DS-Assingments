#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void displayCircularWithRepeat(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // Repeat head at end
}

int main()
{
    Node *head = createNode(20);
    head->next = createNode(100);
    head->next->next = createNode(40);
    head->next->next->next = createNode(80);
    head->next->next->next->next = createNode(60);
    head->next->next->next->next->next = head; // Make it circular

    displayCircularWithRepeat(head);
    return 0;
}