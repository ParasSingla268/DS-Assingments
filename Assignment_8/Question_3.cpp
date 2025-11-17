#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert in BST, no duplicates
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicates not allowed: " << val << endl;
    return root;
}

// Find minimum node in BST
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Delete node
Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
        return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Maximum depth (height) of BST
int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Minimum depth of BST (distance to nearest leaf)
int minDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return 1; // leaf node

    if (!root->left)
        return minDepth(root->right) + 1;
    if (!root->right)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// Inorder traversal for display
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int choice, val;

    while (true)
    {
        cout << "\nBST Operations Menu:\n";
        cout << "1. Insert Element\n2. Delete Element\n3. Maximum Depth\n4. Minimum Depth\n5. Display Inorder\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;
        case 3:
            cout << "Maximum depth of BST: " << maxDepth(root) << endl;
            break;
        case 4:
            cout << "Minimum depth of BST: " << minDepth(root) << endl;
            break;
        case 5:
            cout << "In-order traversal of BST: ";
            inorder(root);
            cout << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}