#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) {
        data = v;
        prev = nullptr;
        next = nullptr;
    }
};

struct CNode {
    int data;
    CNode* next;
    CNode(int v) {
        data = v;
        next = nullptr;
    }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() {
        head = nullptr;
    }
    void insertEnd(int v) {
        DNode* n = new DNode(v);
        if (!head) {
            head = n;
            return;
        }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
    int size() {
        int c = 0;
        DNode* t = head;
        while (t) {
            c++;
            t = t->next;
        }
        return c;
    }
};

class CircularList {
public:
    CNode* head;
    CircularList() {
        head = nullptr;
    }
    void insertEnd(int v) {
        CNode* n = new CNode(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
    int size() {
        if (!head) return 0;
        int c = 0;
        CNode* t = head;
        do {
            c++;
            t = t->next;
        } while (t != head);
        return c;
    }
};

int main() {
    DoublyList dl;
    CircularList cl;
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        dl.insertEnd(x);
        cl.insertEnd(x);
    }
    cout << "Size of Doubly Linked List: " << dl.size() << "\n";
    cout << "Size of Circular Linked List: " << cl.size() << "\n";
    return 0;
}
