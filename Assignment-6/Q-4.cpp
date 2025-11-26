#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
    DNode(char v) {
        data = v;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() {
        head = nullptr;
    }

    void insertEnd(char v) {
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

    bool isPalindrome() {
        if (!head || !head->next) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next) right = right->next;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dl;
    int n;
    cin >> n;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dl.insertEnd(ch);
    }
    if (dl.isPalindrome()) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";
    return 0;
}
