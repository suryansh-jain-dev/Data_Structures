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
    void push(int value) {
        if (rear == size - 1) return;
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
    }
    int pull() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else front++;
        return val;
    }
};

class Stack {
    Queue q1, q2;
public:
    Stack(int n) : q1(n), q2(n) {}
    void push(int x) {
        q2.push(x);
        while (!q1.isEmpty()) q2.push(q1.pull());
        while (!q2.isEmpty()) q1.push(q2.pull());
    }
    int pop() {
        return q1.pull();
    }
    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.pop() << "\n";
    cout << st.pop() << "\n";
    st.push(4);
    cout << st.pop() << "\n";
    return 0;
}
