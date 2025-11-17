#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *prev;
};

Node *createNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

bool isPalindrome(Node *head)
{
    if (head == nullptr)
        return true;
    Node *left = head;
    Node *right = head;
    while (right->next != nullptr)
    {
        right = right->next;
    }
    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    // Sample: r -> a -> d -> a -> r
    Node *head = createNode('r');
    head->next = createNode('a');
    head->next->prev = head;
    head->next->next = createNode('d');
    head->next->next->prev = head->next;
    head->next->next->next = createNode('a');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode('r');
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}