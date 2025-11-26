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

class CircularList {
public:
    Node* head;
    CircularList() {
        head = nullptr;
    }

    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void displayRepeatHead() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << head->data << "\n";
    }
};

int main() {
    CircularList cl;
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        cl.insertEnd(x);
    }
    cl.displayRepeatHead();
    return 0;
}
