#include <iostream>
#include <string>
using namespace std;
class BSTNode {
public:
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int i, string t) {
        isbn = i;
        title = t;
        left = right = NULL;
    }
};
class ListNode {
public:
    int isbn;
    string title;
    ListNode* next;
    ListNode(int i, string t) {
        isbn = i;
        title = t;
        next = NULL;
    }
};
class LibraryBST {
private:
    BSTNode* root;
    BSTNode* insert(BSTNode* node, int isbn, string title) {
           if (node == NULL)
            return new BSTNode(isbn, title);
            if (isbn < node->isbn)
            node->left = insert(node->left, isbn, title);

        else if (isbn > node->isbn)
            node->right = insert(node->right, isbn, title);

        return node;
    }
    void bstToList(BSTNode* node,
                   ListNode*& head,
                   ListNode*& tail) {
                          if (node == NULL)
            return;
            bstToList(node->left, head, tail);
            ListNode* newNode =
            new ListNode(node->isbn, node->title);
            if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        bstToList(node->right, head, tail);
    }
public:
    LibraryBST() {
        root = NULL;
    }
    void insertBook(int isbn, string title) {
        root = insert(root, isbn, title);
    }

    ListNode* convertToLinkedList() {

        ListNode* head = NULL;
        ListNode* tail = NULL;

        bstToList(root, head, tail);

        return head;
    }
};
void printCatalog(ListNode* head) {
       cout << "\nSorted Library Catalog:\n";
       while (head != NULL) {
        cout << "ISBN: " << head->isbn
             << " | Title: "
             << head->title << endl;
             head = head->next;
    }
}
int main() {
       LibraryBST library;
       int n;
    cout << "Enter number of books: ";
    cin >> n;
    int isbn;
    string title;
    cin.ignore();
    for (int i = 0; i < n; i++) {
           cout << "\nEnter ISBN: ";
        cin >> isbn;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        library.insertBook(isbn, title);
    }
    ListNode* catalog =
        library.convertToLinkedList();
        printCatalog(catalog);
    return 0;
}