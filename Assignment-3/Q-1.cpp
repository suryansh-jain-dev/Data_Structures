#include <iostream>
using namespace std;

const int SIZE = 5;  
int stackArr[SIZE];
int topIndex = -1;

void push(int value) {
    if (topIndex == SIZE - 1) {
        cout << "Stack is full" << endl;
    } else {
        topIndex++;
        stackArr[topIndex] = value;
        cout << "Pushed " << value << endl;
    }
}

void pop() {
    if (topIndex == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Popped " << stackArr[topIndex] << endl;
        topIndex--;
    }
}

void isEmpty() {
    if (topIndex == -1) cout << "Stack is empty" << endl;
    else cout << "Stack is not empty" << endl;
}

void isFull() {
    if (topIndex == SIZE - 1) cout << "Stack is full" << endl;
    else cout << "Stack is not full" << endl;
}

void peek() {
    if (topIndex == -1) cout << "Stack is empty" << endl;
    else cout << "Top element is " << stackArr[topIndex] << endl;
}

void display() {
    if (topIndex == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = topIndex; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
