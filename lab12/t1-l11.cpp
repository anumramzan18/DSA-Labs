#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }
    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    bool search(Node* node, int key) {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);

        return search(node->right, key);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder() {
        inorder(root);
    }

    void preorder() {
        preorder(root);
    }

    void postorder() {
        postorder(root);
    }

    bool search(int key) {
        return search(root, key);
    }
};
int main() {
    BST tree;
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    cout << "\nInorder Traversal: ";
    tree.inorder();

    cout << "\nPreorder Traversal: ";
    tree.preorder();
    cout << "\nPostorder Traversal: ";
    tree.postorder();
    int key;
    cout << "\n\nEnter key to search: ";
    cin >> key;
    if (tree.search(key))
        cout << "Key found in BST\n";
    else
        cout << "Key not found in BST\n";

    return 0;
}