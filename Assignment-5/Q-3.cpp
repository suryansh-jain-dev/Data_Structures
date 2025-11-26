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

    int middle() {
        if (!head) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
    int ans = l.middle();
    if(ans == -1) cout<<"List is empty\n";
    else cout<<ans<<"\n";
    return 0;
}