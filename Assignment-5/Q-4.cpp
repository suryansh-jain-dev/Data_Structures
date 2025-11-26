#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class List {
public:
    Node* head;
    List(): head(nullptr) {}

    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        Node* next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL";
    }
};

int main() {
    List l;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        l.insertEnd(x);
    }
    l.reverse();
    l.display();
    cout<<"\n";
    return 0;
}
