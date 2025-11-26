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

class DoublyList {
public:
    DNode* head;
    DoublyList() {
        head = nullptr;
    }

    void insertFirst(int v) {
        DNode* n = new DNode(v);
        if (!head) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertLast(int v) {
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

    bool insertAfter(int key, int v) {
        if (!head) return false;
        DNode* t = head;
        while (t) {
            if (t->data == key) {
                DNode* n = new DNode(v);
                n->next = t->next;
                n->prev = t;
                if (t->next) t->next->prev = n;
                t->next = n;
                return true;
            }
            t = t->next;
        }
        return false;
    }

    bool insertBefore(int key, int v) {
        if (!head) return false;
        if (head->data == key) {
            insertFirst(v);
            return true;
        }
        DNode* t = head->next;
        while (t) {
            if (t->data == key) {
                DNode* n = new DNode(v);
                n->next = t;
                n->prev = t->prev;
                t->prev->next = n;
                t->prev = n;
                return true;
            }
            t = t->next;
        }
        return false;
    }

    bool deleteValue(int key) {
        if (!head) return false;
        if (head->data == key) {
            DNode* t = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete t;
            return true;
        }
        DNode* t = head->next;
        while (t) {
            if (t->data == key) {
                if (t->prev) t->prev->next = t->next;
                if (t->next) t->next->prev = t->prev;
                delete t;
                return true;
            }
            t = t->next;
        }
        return false;
    }

    int search(int key) {
        DNode* t = head;
        int pos = 1;
        while (t) {
            if (t->data == key) return pos;
            t = t->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        DNode* t = head;
        while (t) {
            cout << t->data;
            if (t->next) cout << " <-> ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyList dl;
    int choice;
    while (true) {
        cout << "\nDoubly Linked List Menu\n";
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
            dl.insertFirst(v);
        } else if (choice == 2) {
            int v;
            cout << "Enter value: ";
            cin >> v;
            dl.insertLast(v);
        } else if (choice == 3) {
            int key, v;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> v;
            if (dl.insertAfter(key, v)) cout << "Inserted\n"; else cout << "Key not found\n";
        } else if (choice == 4) {
            int key, v;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> v;
            if (dl.insertBefore(key, v)) cout << "Inserted\n"; else cout << "Key not found\n";
        } else if (choice == 5) {
            int key;
            cout << "Enter value to delete: ";
            cin >> key;
            if (dl.deleteValue(key)) cout << "Deleted\n"; else cout << "Value not found\n";
        } else if (choice == 6) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int p = dl.search(key);
            if (p == -1) cout << "Not found\n"; else cout << "Found at position " << p << "\n";
        } else if (choice == 7) {
            dl.display();
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
