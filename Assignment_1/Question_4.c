#include <stdio.h>

void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    printf("Reversed array: ");
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
int main()
{
    //Reverse of an array
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter array: ");
    int arr[size];
    for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
    reverse(arr, size);
    
    //Matrix Multiplication
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2;
    printf("\nEnter size of matrix A (rows, cols): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter size of matrix B (rows, cols): ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible\n");
        return 0;
    }
    printf("Enter matrix A:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter matrix B:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    printf("Resultant Matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    //Transpose of the matrix
    int a1[10][10], trans[10][10], r, c;
    printf("Enter number of rows and cols of matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a1[i][j]);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = a1[i][j];
    printf("Transpose:\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }
    return 0;
}