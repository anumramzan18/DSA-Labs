#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
 Node(int value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
int maxValue(int a, int b) {
    return (a > b) ? a : b;
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxValue(getHeight(y->left),
        getHeight(y->right)) + 1;

    x->height = maxValue(getHeight(x->left),
        getHeight(x->right)) + 1;

    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxValue(getHeight(x->left),
        getHeight(x->right)) + 1;
    y->height = maxValue(getHeight(y->left),
        getHeight(y->right)) + 1;
    return y;
}
Node* insert(Node* node, int key) {
 if (node == NULL)
        return new Node(key);
if (key < node->data)
        node->left = insert(node->left, key);
 else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + maxValue(getHeight(node->left),
        getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
  Node* root = NULL;
    int values[] = { 30, 20, 40, 10, 25, 35, 50, 5 };
    for (int i = 0; i < 8; i++)
        root = insert(root, values[i]);
    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}