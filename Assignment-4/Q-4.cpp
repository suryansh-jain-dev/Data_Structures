#include <iostream>
using namespace std;


class Queue {
    int front, rear, size;
    char *arr;

public:
    Queue(int n) {
        size = n;
        arr = new char[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void push(char value) {
        if (isFull()) {
            return; 
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
    }

    char pull() {
        if (isEmpty()) {
            return '\0';
        }
        char val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return val;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

int main() {
    string s;
    cout << "Enter characters separated by space: ";
    
    getline(cin, s);

    
    int freq[256];
    for (int i = 0; i < 256; i++) freq[i] = 0;

    Queue q(s.length());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') continue; 
        char ch = s[i];
        freq[(int)ch]++;     
        q.push(ch);           
        
        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.pull();
        }

        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.getFront() << " ";
        }
    }

    cout << "\n";
    return 0;
}
