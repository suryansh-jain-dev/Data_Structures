#include <iostream>
using namespace std;

int main() {
    char input[100];
    cout << "Enter the string: ";
    cin >> input;

    int length = 0;
    for (int k = 0; input[k] != '\0'; k++) {
        length++;
    }

    char st[100];
    int pos = -1;

    for (int k = 0; k < length; k++) {
        pos++;
        st[pos] = input[k];
    }

    cout << "Reversed string: ";
    for (int k = pos; k >= 0; k--) {
        cout << st[k];
    }
    cout << endl;

    return 0;
}
