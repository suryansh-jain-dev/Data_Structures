#include <iostream>
using namespace std;

// Read sparse matrix
void readMatrix(int mat[20][3]) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];
    for (int i = 1; i <= mat[0][2]; i++) {
        cout << "Enter row, col, value: ";
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

// Display sparse matrix
void printMatrix(int mat[20][3]) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << "   " << mat[i][1] << "   " << mat[i][2] << endl;
    }
}

// (a) Transpose
void transpose(int a[20][3], int b[20][3]) {
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    int k = 1;
    for (int col = 0; col < a[0][1]; col++) {
        for (int i = 1; i <= a[0][2]; i++) {
            if (a[i][1] == col) {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

// (b) Addition
void add(int a[20][3], int b[20][3], int c[20][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n";
        c[0][2] = 0;
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    int i = 1, j = 1, k = 1;

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }
    c[0][2] = k - 1;
}

// (c) Multiplication
void multiply(int a[20][3], int b[20][3], int c[20][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible\n";
        c[0][2] = 0;
        return;
    }

    int bt[20][3];
    transpose(b, bt);

    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= bt[0][2]; j++) {
            if (a[i][1] == bt[j][1]) {
                int row = a[i][0];
                int col = bt[j][0];
                int val = a[i][2] * bt[j][2];

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (c[x][0] == row && c[x][1] == col) {
                        c[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    c[k][0] = row;
                    c[k][1] = col;
                    c[k][2] = val;
                    k++;
                }
            }
        }
    }

    c[0][2] = k - 1;
}

int main() {
    int a[20][3], b[20][3], t[20][3], sum[20][3], prod[20][3];

    cout << "Enter first sparse matrix:\n";
    readMatrix(a);
    cout << "First Matrix (Triplet Form):\n";
    printMatrix(a);

    transpose(a, t);
    cout << "Transpose:\n";
    printMatrix(t);

    cout << "Enter second sparse matrix:\n";
    readMatrix(b);
    cout << "Second Matrix (Triplet Form):\n";
    printMatrix(b);

    add(a, b, sum);
    cout << "Addition Result:\n";
    printMatrix(sum);

    multiply(a, b, prod);
    cout << "Multiplication Result:\n";
    printMatrix(prod);

    return 0;
}

