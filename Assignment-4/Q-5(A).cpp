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
    int count() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

class Stack {
    Queue q;
public:
    Stack(int n) : q(n) {}
    void push(int x) {
        q.push(x);
        int c = q.count();
        for (int i = 0; i < c - 1; i++) q.push(q.pull());
    }
    int pop() {
        return q.pull();
    }
    bool isEmpty() {
        return q.isEmpty();
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
