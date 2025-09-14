#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Make a copy of original values so we can shift from it
    int original[n];
    for (int i = 0; i < n; i++) {
        original[i] = arr[i];
    }

    int writeIndex = 0;

    for (int i = 0; i < n && writeIndex < n; i++) {
        arr[writeIndex] = original[i];
        writeIndex++;
        if (original[i] == 2 && writeIndex < n) {
            arr[writeIndex] = 2; // duplicate 2
            writeIndex++;
        }
    }

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
