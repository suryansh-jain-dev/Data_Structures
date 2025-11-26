#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    List() {
        head = nullptr;
    }

    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void makeCircular() {
        if (!head) return;
        Node* t = head;
        while (t->next) t = t->next;
        t->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* t = head->next;
        while (t && t != head) t = t->next;
        return t == head;
    }
};

int main() {
    List l;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        l.insertEnd(x);
    }
    int c;
    cin >> c;
    if(c == 1) l.makeCircular();
    if(l.isCircular()) cout << "Circular\n";
    else cout << "Not Circular\n";
    return 0;
}
