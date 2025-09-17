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
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
    }

    int pull() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int count() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// function to interleave queue
void interleave(Queue &original, int n) {
    int half = n / 2;

    // First half queue
    Queue firstHalf(half);
    // Second half queue
    Queue secondHalf(half);

    // fill firstHalf and secondHalf
    for (int i = 0; i < half; i++) {
        firstHalf.push(original.pull());
    }
    for (int i = 0; i < half; i++) {
        secondHalf.push(original.pull());
    }

    // now interleave and push back to original
    for (int i = 0; i < half; i++) {
        original.push(firstHalf.pull());
        original.push(secondHalf.pull());
    }
}

int main() {
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    Queue q(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "Original queue: ";
    q.display();

    interleave(q, n);

    cout << "Interleaved queue: ";
    q.display();

    return 0;
}
