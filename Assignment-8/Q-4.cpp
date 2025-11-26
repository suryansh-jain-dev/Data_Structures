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

Node* createNode(int v) {
    Node* n = new Node(v);
    return n;
}

bool isBSTUtil(Node* root, Node*& prev) {
    if (!root) return true;
    if (!isBSTUtil(root->left, prev)) return false;
    if (prev && root->data <= prev->data) return false;
    prev = root;
    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    Node* prev = nullptr;
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    if (isBST(root)) cout << "BST\n";
    else cout << "Not BST\n";

    return 0;
}
