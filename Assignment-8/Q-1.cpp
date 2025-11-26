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

void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    return 0;
}
