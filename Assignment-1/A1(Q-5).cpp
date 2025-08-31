//5) Write a program to find sum of every row and every column in a two-dimensional array.
//ans:
#include <stdio.h>
using namespace std;
int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[50][50];
    int i, j;

    // Input elements
    printf("Enter elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Sum (row)
    printf("\nSum of each row:\n");
    for (i = 0; i < rows; i++) {
        int rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }

    // Sum (column)
    printf("\nSum of each column:\n");
    for (j = 0; j < cols; j++) {
        int colSum = 0;
        for (i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
