#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList(): head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    bool insertBefore(int target, int val) {
        if (!head) return false;
        if (head->data == target) {
            insertAtBeginning(val);
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur) {
            if (cur->data == target) {
                Node* n = new Node(val);
                prev->next = n;
                n->next = cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    bool insertAfter(int target, int val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == target) {
                Node* n = new Node(val);
                n->next = cur->next;
                cur->next = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool deleteFromBeginning() {
        if (!head) return false;
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }

    bool deleteFromEnd() {
        if (!head) return false;
        if (!head->next) {
            delete head;
            head = nullptr;
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur->next) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        delete cur;
        return true;
    }

    bool deleteValue(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* t = head;
            head = head->next;
            delete t;
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur) {
            if (cur->data == val) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    int search(int val) {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == val) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice = 0;
    while (true) {
        cout << "\n1 Insert at beginning\n2 Insert at end\n3 Insert before/after a node\n4 Delete from beginning\n5 Delete from end\n6 Delete a specific node\n7 Search for a node\n8 Display all nodes\n9 Exit\nChoose an option: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input\n";
            continue;
        }
        if (choice == 1) {
            int v; cout << "Enter value to insert at beginning: "; cin >> v;
            list.insertAtBeginning(v);
            cout << "Inserted\n";
        } else if (choice == 2) {
            int v; cout << "Enter value to insert at end: "; cin >> v;
            list.insertAtEnd(v);
            cout << "Inserted\n";
        } else if (choice == 3) {
            int target, v, mode;
            cout << "Enter target node value: "; cin >> target;
            cout << "Enter new node value: "; cin >> v;
            cout << "1 Insert before\n2 Insert after\nChoose: "; cin >> mode;
            bool ok = false;
            if (mode == 1) ok = list.insertBefore(target, v);
            else if (mode == 2) ok = list.insertAfter(target, v);
            else cout << "Invalid choice\n";
            if (mode == 1 || mode == 2) {
                if (ok) cout << "Inserted\n"; else cout << "Target not found\n";
            }
        } else if (choice == 4) {
            if (list.deleteFromBeginning()) cout << "Deleted from beginning\n"; else cout << "List empty\n";
        } else if (choice == 5) {
            if (list.deleteFromEnd()) cout << "Deleted from end\n"; else cout << "List empty\n";
        } else if (choice == 6) {
            int v; cout << "Enter value to delete: "; cin >> v;
            if (list.deleteValue(v)) cout << "Deleted\n"; else cout << "Value not found\n";
        } else if (choice == 7) {
            int v; cout << "Enter value to search: "; cin >> v;
            int pos = list.search(v);
            if (pos == -1) cout << "Not found\n"; else cout << "Found at position " << pos << " from head\n";
        } else if (choice == 8) {
            list.display();
        } else if (choice == 9) {
            cout << "Exiting\n";
            break;
        } else {
            cout << "Invalid option\n";
        }
    }
    return 0;
}
