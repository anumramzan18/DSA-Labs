#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
Node* head = nullptr;
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return;

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtPosition(int pos) {
    if (head == nullptr) return;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}
void search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not Found\n";
}
int countNodes() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main() {
    int choice, value, pos;
    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Count\n5.Display\n0.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(value, pos);
                break;

            case 2:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                search(value);
                break;

            case 4:
                cout << "Total nodes: " << countNodes() << endl;
                break;

            case 5:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}