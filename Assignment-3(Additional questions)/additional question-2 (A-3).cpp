#include <iostream>
using namespace std;

const int SIZE = 100;
int st[SIZE];
int top = -1;
int minVal = 0;

void push(int x) {
    if (top == SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    if (top == -1) {
        st[++top] = x;
        minVal = x;
    } else if (x >= minVal) {
        st[++top] = x;
    } else {
        st[++top] = 2*x - minVal;
        minVal = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    int t = st[top--];
    if (t < minVal) {
        minVal = 2*minVal - t;
    }
}

int peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int t = st[top];
    if (t >= minVal) return t;
    else return minVal;
}

int getMin() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return minVal;
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. GetMin\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Top element: " << peek() << endl;
                break;
            case 4:
                cout << "Minimum element: " << getMin() << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
