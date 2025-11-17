#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node *node, int minVal, int maxVal)
{
    if (node == nullptr)
        return true;
    if (node->data < minVal || node->data > maxVal)
        return false;
    return isBSTUtil(node->left, minVal, node->data - 1) && isBSTUtil(node->right, node->data + 1, maxVal);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    /*
        Example tree:
                10
               /  \
              5   15
             / \    \
            2   7   20
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    if (isBST(root))
        cout << "The tree is a BST.\n";
    else
        cout << "The tree is NOT a BST.\n";

    return 0;
}