#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear + 1) % size == front);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
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
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Enter size of circular queue: ";
    cin >> n;
    CircularQueue q(n);

    int choice, val;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push (Insert)\n";
        cout << "2. Pull (Delete)\n";
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
            q.push(val);
            break;
        case 2:
            q.pull();
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
