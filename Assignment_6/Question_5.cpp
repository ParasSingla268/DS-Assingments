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

bool isCircular(Node *head)
{
    if (head == nullptr)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Sample: 2 -> 4 -> 6 -> 7 -> 5 -> back to 2
    Node *head = createNode(2);
    head->next = createNode(4);
    head->next->next = createNode(6);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head; // Cycle back to head

    if (isCircular(head))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}