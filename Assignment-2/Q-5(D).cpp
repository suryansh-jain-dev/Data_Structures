#include <iostream>
using namespace std;

class UpperTriangular {
    int *arr, n;
public:
    UpperTriangular(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        return (i*n - (i*(i-1))/2) + (j - i);
    }
    void set(int i, int j, int val) {
        if (i <= j) arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        if (i <= j) return arr[index(i,j)];
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
    UpperTriangular ut(4);
    ut.set(0,0,1); ut.set(0,1,2); ut.set(0,2,3); ut.set(0,3,4);
    ut.set(1,1,5); ut.set(1,2,6); ut.set(1,3,7);
    ut.set(2,2,8); ut.set(2,3,9);
    ut.set(3,3,10);
    ut.display();
}

