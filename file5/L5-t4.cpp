#include <iostream>
using namespace std;
class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};
class PatientQueue {
    Node* head;
public:
    PatientQueue() {
        head = nullptr;
    }
    void addPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }
    void removePatient(string name) {
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
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
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
};
int main() {
    PatientQueue q;
    q.addPatient("Ali");
    q.addPatient("Sara");
    q.addPatient("Ahmed");
    q.display();
    q.removePatient("Sara");
    q.display();
    cout << "Total Patients: " << q.count();
    return 0;
}