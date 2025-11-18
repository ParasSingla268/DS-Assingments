#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Search (Recursive)
Node *searchRecursive(Node *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search (Non-Recursive)
Node *searchNonRecursive(Node *root, int key)
{
    while (root != nullptr && root->data != key)
    {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// (b) Maximum element (rightmost node)
Node *findMax(Node *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Minimum element (leftmost node)
Node *findMin(Node *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// (d) In-order successor of given node
Node *inorderSuccessor(Node *root, Node *node)
{
    if (node->right != nullptr)
        return findMin(node->right);

    Node *successor = nullptr;
    while (root != nullptr)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

// (e) In-order predecessor of given node
Node *inorderPredecessor(Node *root, Node *node)
{
    if (node->left != nullptr)
        return findMax(node->left);

    Node *predecessor = nullptr;
    while (root != nullptr)
    {
        if (node->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

int main()
{
    /*
        BST for demo:
                20
               /  \
             10    30
            /  \     \
           5   15     40
    */
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    int key = 15;

    // Recursive Search
    Node *foundR = searchRecursive(root, key);
    cout << "Recursive search for " << key << ": " << (foundR ? "Found" : "Not Found") << endl;

    // Non-Recursive Search
    Node *foundNR = searchNonRecursive(root, key);
    cout << "Non-Recursive search for " << key << ": " << (foundNR ? "Found" : "Not Found") << endl;

    // Maximum Element
    Node *maxNode = findMax(root);
    if (maxNode)
        cout << "Maximum element: " << maxNode->data << endl;

    // Minimum Element
    Node *minNode = findMin(root);
    if (minNode)
        cout << "Minimum element: " << minNode->data << endl;

    // Inorder successor of 15
    Node *node = searchNonRecursive(root, 15);
    Node *succ = inorderSuccessor(root, node);
    if (succ)
        cout << "Inorder successor of " << node->data << ": " << succ->data << endl;
    else
        cout << "Inorder successor does not exist." << endl;

    // Inorder predecessor of 15
    Node *pred = inorderPredecessor(root, node);
    if (pred)
        cout << "Inorder predecessor of " << node->data << ": " << pred->data << endl;
    else
        cout << "Inorder predecessor does not exist." << endl;

    return 0;
}