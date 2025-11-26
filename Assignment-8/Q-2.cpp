#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int v) {
        Node* n = new Node(v);
        if (!root) {
            root = n;
            return;
        }
        Node* cur = root;
        Node* parent = nullptr;
        while (cur) {
            parent = cur;
            if (v < cur->data) cur = cur->left;
            else if (v > cur->data) cur = cur->right;
            else return;
        }
        if (v < parent->data) parent->left = n;
        else parent->right = n;
    }

    Node* searchRec(Node* r, int key) {
        if (!r) return nullptr;
        if (key == r->data) return r;
        if (key < r->data) return searchRec(r->left, key);
        else return searchRec(r->right, key);
    }

    Node* searchNonRec(int key) {
        Node* cur = root;
        while (cur) {
            if (key == cur->data) return cur;
            if (key < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return nullptr;
    }

    Node* minNode() {
        if (!root) return nullptr;
        Node* cur = root;
        while (cur->left) cur = cur->left;
        return cur;
    }

    Node* maxNode() {
        if (!root) return nullptr;
        Node* cur = root;
        while (cur->right) cur = cur->right;
        return cur;
    }

    Node* successor(int key) {
        Node* cur = root;
        Node* succ = nullptr;
        while (cur) {
            if (key < cur->data) {
                succ = cur;
                cur = cur->left;
            } else if (key > cur->data) {
                cur = cur->right;
            } else break;
        }
        if (!cur) return nullptr;
        if (cur->right) {
            Node* t = cur->right;
            while (t->left) t = t->left;
            return t;
        }
        return succ;
    }

    Node* predecessor(int key) {
        Node* cur = root;
        Node* pred = nullptr;
        while (cur) {
            if (key > cur->data) {
                pred = cur;
                cur = cur->right;
            } else if (key < cur->data) {
                cur = cur->left;
            } else break;
        }
        if (!cur) return nullptr;
        if (cur->left) {
            Node* t = cur->left;
            while (t->right) t = t->right;
            return t;
        }
        return pred;
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
};

int main() {
    BST t;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.insert(x);
    }
    int ch, key;
    while (true) {
        cout << "\n1 Search (Recursive)\n2 Search (Non-Recursive)\n3 Minimum\n4 Maximum\n5 Inorder Successor\n6 Inorder Predecessor\n7 Inorder Display\n8 Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter key: ";
            cin >> key;
            Node* p = t.searchRec(t.root, key);
            if (p) cout << "Found\n"; else cout << "Not Found\n";
        } else if (ch == 2) {
            cout << "Enter key: ";
            cin >> key;
            Node* p = t.searchNonRec(key);
            if (p) cout << "Found\n"; else cout << "Not Found\n";
        } else if (ch == 3) {
            Node* p = t.minNode();
            if (p) cout << "Minimum: " << p->data << "\n"; else cout << "Tree is empty\n";
        } else if (ch == 4) {
            Node* p = t.maxNode();
            if (p) cout << "Maximum: " << p->data << "\n"; else cout << "Tree is empty\n";
        } else if (ch == 5) {
            cout << "Enter key: ";
            cin >> key;
            Node* p = t.successor(key);
            if (p) cout << "Successor: " << p->data << "\n"; else cout << "No Successor\n";
        } else if (ch == 6) {
            cout << "Enter key: ";
            cin >> key;
            Node* p = t.predecessor(key);
            if (p) cout << "Predecessor: " << p->data << "\n"; else cout << "No Predecessor\n";
        } else if (ch == 7) {
            t.inorder(t.root);
            cout << "\n";
        } else if (ch == 8) {
            break;
        } else {
            cout << "Invalid\n";
        }
    }
    return 0;
}
