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

    int deleteKey(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
            count++;
        }
        Node* prev = head;
        if (!prev) return count;
        Node* cur = head->next;
        while (cur) {
            if (cur->data == key) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                count++;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return count;
    }

    void display() {
        Node* t = head;
        if (!t) {
            cout << "Empty";
            return;
        }
        while (t) {
            cout << t->data;
            if (t->next) cout << "->";
            t = t->next;
        }
    }
};

int main() {
    List l;
    int n,x,key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        l.insertEnd(x);
    }
    cin>>key;
    int c = l.deleteKey(key);
    cout<<"Count: "<<c<<" , Updated Linked List: ";
    l.display();
    cout<<"\n";
    return 0;
}
