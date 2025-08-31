#include <iostream>
using namespace std;

class DiagonalMatrix {
    int *arr, n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if (i == j) arr[i] = val;
    }
    int get(int i, int j) {
        if (i == j) return arr[i];
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
    DiagonalMatrix d(4);
    d.set(0,0,5);
    d.set(1,1,8);
    d.set(2,2,9);
    d.set(3,3,6);
    d.display();
}

