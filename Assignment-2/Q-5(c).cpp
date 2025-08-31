#include <iostream>
using namespace std;

class LowerTriangular {
    int *arr, n;
public:
    LowerTriangular(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        return (i*(i+1))/2 + j;
    }
    void set(int i, int j, int val) {
        if (i >= j) arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        if (i >= j) return arr[index(i,j)];
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
    LowerTriangular lt(4);
    lt.set(0,0,1);
    lt.set(1,0,2); lt.set(1,1,3);
    lt.set(2,0,4); lt.set(2,1,5); lt.set(2,2,6);
    lt.set(3,0,7); lt.set(3,1,8); lt.set(3,2,9); lt.set(3,3,10);
    lt.display();
}

