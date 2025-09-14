#include <iostream>
using namespace std;

int main() {
    char exp[200];
    cout << "Enter the postfix expression: ";
    cin >> exp;

    int st[200];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            st[++top] = c - '0';
        } else {
            int b = st[top--];
            int a = st[top--];
            int r = 0;
            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else if (c == '/') r = a / b;
            st[++top] = r;
        }
    }

    cout << "Result: " << st[top] << endl;
    return 0;
}
