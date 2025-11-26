//Circular list

#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int v) {
        data = v;
        next = nullptr;
    }
};

class CircularList {
public:
    CNode* head;
    CircularList() {
        head = nullptr;
    }

    void insertFirst(int v) {
        CNode* n = new CNode(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }

    void insertLast(int v) {
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

    bool insertAfter(int key, int v) {
        if (!head) return false;
        CNode* t = head;
        do {
            if (t->data == key) {
                CNode* n = new CNode(v);
                n->next = t->next;
                t->next = n;
                return true;
            }
            t = t->next;
        } while (t != head);
        return false;
    }

    bool insertBefore(int key, int v) {
        if (!head) return false;
        if (head->data == key) {
            insertFirst(v);
            return true;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                CNode* n = new CNode(v);
                prev->next = n;
                n->next = cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    bool deleteValue(int key) {
        if (!head) return false;
        if (head->next == head && head->data == key) {
            delete head;
            head = nullptr;
            return true;
        }
        if (head->data == key) {
            CNode* last = head;
            while (last->next != head) last = last->next;
            CNode* t = head;
            head = head->next;
            last->next = head;
            delete t;
            return true;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    int search(int key) {
        if (!head) return -1;
        CNode* t = head;
        int pos = 1;
        do {
            if (t->data == key) return pos;
            t = t->next;
            pos++;
        } while (t != head);
        return -1;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        CNode* t = head;
        do {
            cout << t->data;
            t = t->next;
            if (t != head) cout << " -> ";
        } while (t != head);
        cout << "\n";
    }
};

int main() {
    CircularList cl;
    int choice;
    while (true) {
        cout << "\nCircular Linked List Menu\n";
        cout << "1 Insert at beginning\n";
        cout << "2 Insert at end\n";
        cout << "3 Insert after a node\n";
        cout << "4 Insert before a node\n";
        cout << "5 Delete a specific node\n";
        cout << "6 Search for a node\n";
        cout << "7 Display list\n";
        cout << "8 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (!cin) return 0;
        if (choice == 1) {
            int v;
            cout << "Enter value: ";
            cin >> v;
            cl.insertFirst(v);
        } else if (choice == 2) {
            int v;
            cout << "Enter value: ";
            cin >> v;
            cl.insertLast(v);
        } else if (choice == 3) {
            int key, v;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> v;
            if (cl.insertAfter(key, v)) cout << "Inserted\n"; else cout << "Key not found\n";
        } else if (choice == 4) {
            int key, v;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> v;
            if (cl.insertBefore(key, v)) cout << "Inserted\n"; else cout << "Key not found\n";
        } else if (choice == 5) {
            int key;
            cout << "Enter value to delete: ";
            cin >> key;
            if (cl.deleteValue(key)) cout << "Deleted\n"; else cout << "Value not found\n";
        } else if (choice == 6) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int p = cl.search(key);
            if (p == -1) cout << "Not found\n"; else cout << "Found at position " << p << "\n";
        } else if (choice == 7) {
            cl.display();
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
