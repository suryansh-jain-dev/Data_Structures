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

    Node* insertNode(Node* r, int v) {
        if (!r) {
            Node* n = new Node(v);
            return n;
        }
        if (v < r->data) r->left = insertNode(r->left, v);
        else if (v > r->data) r->right = insertNode(r->right, v);
        return r;
    }

    void insert(int v) {
        root = insertNode(root, v);
    }

    Node* minNode(Node* r) {
        if (!r) return nullptr;
        while (r->left) r = r->left;
        return r;
    }

    Node* deleteNode(Node* r, int key) {
        if (!r) return nullptr;
        if (key < r->data) r->left = deleteNode(r->left, key);
        else if (key > r->data) r->right = deleteNode(r->right, key);
        else {
            if (!r->left && !r->right) {
                delete r;
                return nullptr;
            } else if (!r->left) {
                Node* t = r->right;
                delete r;
                return t;
            } else if (!r->right) {
                Node* t = r->left;
                delete r;
                return t;
            } else {
                Node* t = minNode(r->right);
                r->data = t->data;
                r->right = deleteNode(r->right, t->data);
            }
        }
        return r;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    int maxDepth(Node* r) {
        if (!r) return 0;
        int l = maxDepth(r->left);
        int rr = maxDepth(r->right);
        if (l > rr) return l + 1;
        else return rr + 1;
    }

    int minDepth(Node* r) {
        if (!r) return 0;
        if (!r->left && !r->right) return 1;
        if (!r->left) return 1 + minDepth(r->right);
        if (!r->right) return 1 + minDepth(r->left);
        int l = minDepth(r->left);
        int rr = minDepth(r->right);
        if (l < rr) return l + 1;
        else return rr + 1;
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
        cout << "\n1 Insert\n2 Delete\n3 Maximum depth\n4 Minimum depth\n5 Inorder display\n6 Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value: ";
            cin >> x;
            t.insert(x);
        } else if (ch == 2) {
            cout << "Enter value to delete: ";
            cin >> key;
            t.deleteKey(key);
        } else if (ch == 3) {
            cout << "Maximum depth: " << t.maxDepth(t.root) << "\n";
        } else if (ch == 4) {
            cout << "Minimum depth: " << t.minDepth(t.root) << "\n";
        } else if (ch == 5) {
            t.inorder(t.root);
            cout << "\n";
        } else if (ch == 6) {
            break;
        } else {
            cout << "Invalid\n";
        }
    }
    return 0;
}
