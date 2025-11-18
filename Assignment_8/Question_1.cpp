#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Recursive Preorder Traversal
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive Inorder Traversal
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive Postorder Traversal
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Sample usage / building a demo tree
int main()
{
    /*
        Build this tree for example:
                10
               /  \
              5    15
             / \     \
            3   7     18
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << "\nIn-order traversal: ";
    inorder(root);
    cout << "\nPost-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}