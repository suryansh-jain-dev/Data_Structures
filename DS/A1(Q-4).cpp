//4) Implement the logic to
//a. Reverse the elements of an array:
//ans:
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i, temp;
    
    for (i = 0; i < 5 / 2; i++) {
        temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    return 0;
}

//b. Find the matrix multiplication
ans:
#include <stdio.h>

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {0};
    int i, j, k;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}

//c. Find the Transpose of a Matrix
Ans:
#include <stdio.h>

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int t[3][2], i, j;


    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            t[j][i] = a[i][j];


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}
