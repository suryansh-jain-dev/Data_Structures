#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;

    // check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                count++;
                cout << "Inversion: (" << a[i] << ", " << a[j] << ")\n";
            }
        }
    }

    cout << "Total number of inversions = " << count << endl;

    return 0;
}

