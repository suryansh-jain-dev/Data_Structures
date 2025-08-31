#include <iostream>
using namespace std;

class SymmetricMatrix {
    int *arr, n;
public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        if (i >= j) return (i*(i+1))/2 + j; // lower triangle
        else return (j*(j+1))/2 + i;        // use symmetry
    }
    void set(int i, int j, int val) {
        arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        return arr[index(i,j)];
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
    SymmetricMatrix sm(4);
    sm.set(0,0,1); sm.set(0,1,2); sm.set(0,2,3); sm.set(0,3,4);
    sm.set(1,1,5); sm.set(1,2,6); sm.set(1,3,7);
    sm.set(2,2,8); sm.set(2,3,9);
    sm.set(3,3,10);
    sm.display();
}

