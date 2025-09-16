#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element
{
    int row, col, val;
};

class SparseMatrix
{
    int rows, cols;
    vector<Element> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int v)
    {
        if (v != 0)
            elements.push_back({r, c, v});
    }

    void display()
    {
        int k = 0;
        sort(elements.begin(), elements.end(), [](Element a, Element b)
             {
            if (a.row == b.row) return a.col < b.col;
            return a.row < b.row; });
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (k < (int)elements.size() && elements[k].row == i && elements[k].col == j)
                {
                    cout << elements[k].val << " ";
                    k++;
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }

    SparseMatrix transpose()
    {
        SparseMatrix result(cols, rows);
        for (auto &e : elements)
        {
            result.addElement(e.col, e.row, e.val);
        }
        return result;
    }

    SparseMatrix add(SparseMatrix &b)
    {
        if (rows != b.rows || cols != b.cols)
        {
            cout << "Matrix dimensions must be same for addition\n";
            return SparseMatrix(0, 0);
        }
        SparseMatrix result(rows, cols);
        int i = 0, j = 0;
        sort(elements.begin(), elements.end(), [](Element a, Element b)
             {
            if (a.row == b.row) return a.col < b.col;
            return a.row < b.row; });
        sort(b.elements.begin(), b.elements.end(), [](Element a, Element b)
             {
            if (a.row == b.row) return a.col < b.col;
            return a.row < b.row; });
        while (i < (int)elements.size() && j < (int)b.elements.size())
        {
            if (elements[i].row < b.elements[j].row ||
                (elements[i].row == b.elements[j].row && elements[i].col < b.elements[j].col))
            {
                result.addElement(elements[i].row, elements[i].col, elements[i].val);
                i++;
            }
            else if (elements[i].row > b.elements[j].row ||
                     (elements[i].row == b.elements[j].row && elements[i].col > b.elements[j].col))
            {
                result.addElement(b.elements[j].row, b.elements[j].col, b.elements[j].val);
                j++;
            }
            else
            {
                int sum = elements[i].val + b.elements[j].val;
                if (sum != 0)
                    result.addElement(elements[i].row, elements[i].col, sum);
                i++;
                j++;
            }
        }
        while (i < (int)elements.size())
        {
            result.addElement(elements[i].row, elements[i].col, elements[i].val);
            i++;
        }
        while (j < (int)b.elements.size())
        {
            result.addElement(b.elements[j].row, b.elements[j].col, b.elements[j].val);
            j++;
        }
        return result;
    }

    SparseMatrix multiply(SparseMatrix &b)
    {
        if (cols != b.rows)
        {
            cout << "Matrix dimensions incompatible for multiplication\n";
            return SparseMatrix(0, 0);
        }
        SparseMatrix result(rows, b.cols);

        // Create row-wise map for b
        vector<vector<Element>> bRow(b.rows);
        for (auto &e : b.elements)
        {
            bRow[e.row].push_back(e);
        }

        // Create row-wise map for this matrix
        vector<vector<Element>> aRow(rows);
        for (auto &e : elements)
        {
            aRow[e.row].push_back(e);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < b.cols; j++)
            {
                int sum = 0;
                for (auto &aElem : aRow[i])
                {
                    for (auto &bElem : bRow[aElem.col])
                    {
                        if (bElem.col == j)
                        {
                            sum += aElem.val * bElem.val;
                            break;
                        }
                    }
                }
                if (sum != 0)
                    result.addElement(i, j, sum);
            }
        }
        return result;
    }
};

int main()
{
    int choice;
    do
    {
        cout << "\nSparse Matrix Operations Menu:\n";
        cout << "1. Transpose of a matrix\n2. Addition of two matrices\n3. Multiplication of two matrices\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        int r1, c1, r2, c2;
        if (choice == 1)
        {
            cout << "Enter rows and columns of the sparse matrix: ";
            cin >> r1 >> c1;
            SparseMatrix A(r1, c1);
            cout << "Enter non-zero elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                A.addElement(r, c, v);
            }
            cout << "Original matrix:\n";
            A.display();
            cout << "Transpose matrix:\n";
            SparseMatrix T = A.transpose();
            T.display();
        }
        else if (choice == 2)
        {
            cout << "Enter rows and columns of first sparse matrix: ";
            cin >> r1 >> c1;
            SparseMatrix A(r1, c1);
            cout << "Enter non-zero elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                A.addElement(r, c, v);
            }
            cout << "Enter rows and columns of second sparse matrix: ";
            cin >> r2 >> c2;
            SparseMatrix B(r2, c2);
            cout << "Enter non-zero elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                B.addElement(r, c, v);
            }
            cout << "First matrix:\n";
            A.display();
            cout << "Second matrix:\n";
            B.display();
            cout << "Sum matrix:\n";
            SparseMatrix S = A.add(B);
            S.display();
        }
        else if (choice == 3)
        {
            cout << "Enter rows and columns of first sparse matrix: ";
            cin >> r1 >> c1;
            SparseMatrix A(r1, c1);
            cout << "Enter non-zero elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                A.addElement(r, c, v);
            }
            cout << "Enter rows and columns of second sparse matrix: ";
            cin >> r2 >> c2;
            SparseMatrix B(r2, c2);
            cout << "Enter non-zero elements (row col val), 0-based index. Enter -1 to stop:\n";
            while (true)
            {
                int r;
                cin >> r;
                if (r == -1)
                    break;
                int c, v;
                cin >> c >> v;
                B.addElement(r, c, v);
            }
            cout << "First matrix:\n";
            A.display();
            cout << "Second matrix:\n";
            B.display();
            cout << "Product matrix:\n";
            SparseMatrix P = A.multiply(B);
            P.display();
        }
        else
        {
            cout << "Invalid choice\n";
        }
    } while (true);

    cout << "Program ended.\n";
    return 0;
}