#include <iostream>
using namespace std;
class Node {
public:
    string name;
    int priority;
    Node* next;

    Node(string n, int p) {
        name = n;
        priority = p;
        next = nullptr;
    }
};
class BookQueue {
    Node* head;

public:
    BookQueue() {
        head = nullptr;
    }
    void addStudent(string name, int priority) {
        Node* newNode = new Node(name, priority);

        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority <= priority)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void removeStudent(string name) {
        if (head == nullptr) return;
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->name != name)
            temp = temp->next;
            if (temp->next != nullptr) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << "(" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int count() {
        int c = 0;
        Node* temp = head;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        return c;
    }
    void serve() {
        if (head == nullptr) return;

        Node* temp = head;
        cout << "Serving: " << temp->name << endl;

        head = head->next;
        delete temp;
    }
};
int main() {
    BookQueue book1, book2;
    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 1);
    book1.addStudent("Ahmed", 3);
    cout << "Book 1 Queue:\n";
    book1.display();
    book1.serve();
    cout << "After Serving:\n";
    book1.display();
    return 0;
}