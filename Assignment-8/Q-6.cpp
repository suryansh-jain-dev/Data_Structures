#include <iostream>
using namespace std;

void swapv(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i) {
        swapv(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] < a[smallest]) smallest = l;
    if(r < n && a[r] < a[smallest]) smallest = r;
    if(smallest != i) {
        swapv(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}

void heapSortInc(int a[], int n) {
    for(int i=n/2-1; i>=0; i--) heapifyMax(a, n, i);
    for(int i=n-1;i>=0;i--) {
        swapv(a[0], a[i]);
        heapifyMax(a, i, 0);
    }
}

void heapSortDec(int a[], int n) {
    for(int i=n/2-1; i>=0; i--) heapifyMin(a, n, i);
    for(int i=n-1;i>=0;i--) {
        swapv(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}

void display(int a[], int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main() {
    int a[100], n, ch;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << "1 Increasing Order\n2 Decreasing Order\nEnter choice: ";
    cin >> ch;
    if(ch == 1) heapSortInc(a, n);
    else if(ch == 2) heapSortDec(a, n);
    display(a, n);
    return 0;
}
