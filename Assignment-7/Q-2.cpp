#include <iostream>
using namespace std;

void swapv(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int min = left, max = right;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[min]) min = i;
            if (a[i] > a[max]) max = i;
        }

        swapv(a[left], a[min]);

        if (max == left) max = min;

        swapv(a[right], a[max]);

        left++;
        right--;
    }
}

int main() {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    improvedSelectionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}
