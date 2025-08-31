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

    int distinct = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            distinct++;
        }
    }

    cout << "Total distinct elements = " << distinct << endl;

    return 0;
}

