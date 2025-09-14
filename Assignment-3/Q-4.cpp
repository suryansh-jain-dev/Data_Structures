#include <iostream>
using namespace std;

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char in[200];
    cout << "Enter the infix expression: ";
    cin >> in;

    char st[200];
    int top = -1;
    char out[200];
    int idx = 0;

    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            out[idx++] = c;
        } else if (c == '(') {
            st[++top] = c;
        } else if (c == ')') {
            while (top != -1 && st[top] != '(') {
                out[idx++] = st[top--];
            }
            if (top != -1 && st[top] == '(') top--;
        } else {
            while (top != -1 && prec(st[top]) >= prec(c)) {
                out[idx++] = st[top--];
            }
            st[++top] = c;
        }
    }

    while (top != -1) {
        out[idx++] = st[top--];
    }

    out[idx] = '\0';
    cout << "Postfix expression: " << out << endl;

    return 0;
}
