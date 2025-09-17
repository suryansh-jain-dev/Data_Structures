#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int *arr;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1) front = 0; // first element
        rear++;
        arr[rear] = value;
        cout << "Inserted " << value << " into the queue.\n";
    }

    void pull() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from the queue.\n";
        if (front == rear) {
            // queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue q(n);

    int choice, val;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pull\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;
        case 5:
            q.peek();
            break;
        case 6:
            q.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
