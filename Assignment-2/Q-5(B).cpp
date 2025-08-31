#include <iostream>
using namespace std;

class TriDiagonal {
    int *arr, n;
public:
    TriDiagonal(int size) {
        n = size;
        arr = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if (i - j == 1) arr[i-1] = val;           // lower diagonal
        else if (i - j == 0) arr[n - 1 + i] = val; // main diagonal
        else if (i - j == -1) arr[2*n - 1 + i] = val; // upper diagonal
    }
    int get(int i, int j) {
        if (i - j == 1) return arr[i-1];
        else if (i - j == 0) return arr[n - 1 + i];
        else if (i - j == -1) return arr[2*n - 1 + i];
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal td(4);
    td.set(0,0,1);
    td.set(0,1,2);
    td.set(1,0,3);
    td.set(1,1,4);
    td.set(1,2,5);
    td.set(2,1,6);
    td.set(2,2,7);
    td.set(2,3,8);
    td.set(3,2,9);
    td.set(3,3,10);
    td.display();
}

