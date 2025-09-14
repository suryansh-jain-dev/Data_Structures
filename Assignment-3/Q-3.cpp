#include <iostream>
using namespace std;

int main() {
    char exp[200];
    cout << "Enter the expression: ";
    cin >> exp;

    char st[200];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top++;
            st[top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                cout << "Not Balanced" << endl;
                return 0;
            }
            char c = st[top];
            top--;
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == '}' && c != '{') ||
                (exp[i] == ']' && c != '[')) {
                cout << "Not Balanced" << endl;
                return 0;
            }
        }
    }

    if (top == -1) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;

    return 0;
}
