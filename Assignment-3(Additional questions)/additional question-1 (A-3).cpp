#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[100];

    for (int i = 0; i < n; i++) {
        int nearest = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                nearest = arr[j];
                break;
            }
        }
        result[i] = nearest;
    }

    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
