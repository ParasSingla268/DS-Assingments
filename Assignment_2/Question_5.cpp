#include <iostream>
#include <vector>
using namespace std;

// Classes for special matrices (same as before)

class DiagonalMatrix
{
    int n;
    vector<int> arr;

public:
    DiagonalMatrix(int size) : n(size), arr(size, 0) {}
    void set(int i, int j, int val)
    {
        if (i == j)
            arr[i] = val;
        else if (val != 0)
            cout << "Only diagonal elements can be non-zero\n";
    }
    int get(int i, int j)
    {
        return (i == j) ? arr[i] : 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << "\n";
        }
    }
};

class TriDiagonalMatrix
{
    int n;
    vector<int> arr;

public:
    TriDiagonalMatrix(int size) : n(size), arr(3 * n - 2, 0) {}
    void set(int i, int j, int val)
    {
        if (i - j == 1)
            arr[i - 1] = val;
        else if (i == j)
            arr[n - 1 + i] = val;
        else if (j - i == 1)
            arr[2 * n - 1 + i] = val;
        else if (val != 0)
            cout << "Only tri-diagonal elements can be non-zero\n";
    }
    int get(int i, int j)
    {
        if (i - j == 1)
            return arr[i - 1];
        else if (i == j)
            return arr[n - 1 + i];
        else if (j - i == 1)
            return arr[2 * n - 1 + i];
        else
            return 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << "\n";
        }
    }
};

class LowerTriangularMatrix
{
    int n;
    vector<int> arr;

public:
    LowerTriangularMatrix(int size) : n(size), arr(n * (n + 1) / 2, 0) {}
    int index(int i, int j) { return (i * (i + 1)) / 2 + j; }
    void set(int i, int j, int val)
    {
        if (i >= j)
            arr[index(i, j)] = val;
        else if (val != 0)
            cout << "Only lower triangular elements can be non-zero\n";
    }
    int get(int i, int j)
    {
        return (i >= j) ? arr[index(i, j)] : 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << "\n";
        }
    }
};

class UpperTriangularMatrix
{
    int n;
    vector<int> arr;

public:
    UpperTriangularMatrix(int size) : n(size), arr(n * (n + 1) / 2, 0) {}
    int index(int i, int j) { return (j * (j + 1)) / 2 + i; }
    void set(int i, int j, int val)
    {
        if (i <= j)
            arr[index(i, j)] = val;
        else if (val != 0)
            cout << "Only upper triangular elements can be non-zero\n";
    }
    int get(int i, int j)
    {
        return (i <= j) ? arr[index(i, j)] : 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << "\n";
        }
    }
};

class SymmetricMatrix
{
    int n;
    vector<int> arr;

public:
    SymmetricMatrix(int size) : n(size), arr(n * (n + 1) / 2, 0) {}
    int index(int i, int j)
    {
        if (i >= j)
            return (i * (i + 1)) / 2 + j;
        else
            return (j * (j + 1)) / 2 + i;
    }
    void set(int i, int j, int val)
    {
        arr[index(i, j)] = val;
    }
    int get(int i, int j)
    {
        return arr[index(i, j)];
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << "\n";
        }
    }
};

int main()
{
    int choice;
    do
    {
        cout << "\nSpecial Matrices Storage Menu:\n";
        cout << "1. Diagonal Matrix\n2. Tri-diagonal Matrix\n3. Lower Triangular Matrix\n4. Upper Triangular Matrix\n5. Symmetric Matrix\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        int n;
        cout << "Enter size of square matrix: ";
        cin >> n;

        switch (choice)
        {
        case 1:
        {
            DiagonalMatrix dm(n);
            cout << "Enter elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                dm.set(r, c, v);
            }
            cout << "Diagonal Matrix:\n";
            dm.display();
            break;
        }
        case 2:
        {
            TriDiagonalMatrix tm(n);
            cout << "Enter elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                tm.set(r, c, v);
            }
            cout << "Tri-diagonal Matrix:\n";
            tm.display();
            break;
        }
        case 3:
        {
            LowerTriangularMatrix lm(n);
            cout << "Enter elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                lm.set(r, c, v);
            }
            cout << "Lower Triangular Matrix:\n";
            lm.display();
            break;
        }
        case 4:
        {
            UpperTriangularMatrix um(n);
            cout << "Enter elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                um.set(r, c, v);
            }
            cout << "Upper Triangular Matrix:\n";
            um.display();
            break;
        }
        case 5:
        {
            SymmetricMatrix sm(n);
            cout << "Enter elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                sm.set(r, c, v);
            }
            cout << "Symmetric Matrix:\n";
            sm.display();
            break;
        }
        default:
            cout << "Invalid choice\n";
        }
    } while (true);

    cout << "Program ended.\n";
    return 0;
}