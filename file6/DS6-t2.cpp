#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int rollNo;
    string name;
    float marks;
    Node* next;
    Node(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        next = NULL;
    }
};
class StudentManagementSystem {
private:
    Node* head;

public:
    StudentManagementSystem() {
        head = NULL;
    }
    void insertRecord(int r, string n, float m) {
        Node* newNode = new Node(r, n, m);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Record added successfully.\n";
    }
    void deleteRecord(int r) {
        if (head == NULL) {
            cout << "Error: The list is empty.\n";
            return;
        }
        if (head->rollNo == r) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Record deleted.\n";
            return;
        }
        Node* curr = head;
        while (curr->next != NULL && curr->next->rollNo != r) {
            curr = curr->next;
        }

        if (curr->next != NULL) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Record deleted.\n";
        } else {
            cout << "Error: Roll number " << r << " not found.\n";
        }
    }
    void searchStudent(int r) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == r) {
                cout << "\n--- Student Found ---" << endl;
                cout << "Roll No: " << temp->rollNo << "\nName: " << temp->name << "\nMarks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student with Roll No " << r << " not found.\n";
    }
    void updateMarks(int r, float newMarks) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == r) {
                temp->marks = newMarks;
                cout << "Marks updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }
    void displayStatistics() {
        if (head == NULL) {
            cout << "No records available for statistics.\n";
            return;
        }
        float high = head->marks, low = head->marks, total = 0;
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->marks > high) high = temp->marks;
            if (temp->marks < low) low = temp->marks;
            total += temp->marks;
            count++;
            temp = temp->next;
        }       
        cout << "\n--- Class Statistics ---" << endl;
        cout << "Highest Marks: " << high << endl;
        cout << "Lowest Marks:  " << low << endl;
        cout << "Average Marks: " << (total / count) << endl;
    }
    void displayAll() {
        if (head == NULL) {
            cout << "No records found.\n";
            return;
        }
        Node* temp = head;
        cout << "\nRoll No\t\tName\t\tMarks" << endl;
        while (temp != NULL) {
            cout << temp->rollNo << "\t\t" << temp->name << "\t\t" << temp->marks << endl;
            temp = temp->next;
        }
    }
};
int main() {
    StudentManagementSystem sms;
    int choice, roll;
    string name;
    float marks;
    while (true) {
        cout << "\n===== Student Record Management System =====" << endl;
        cout << "1. Insert Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Display All Records" << endl;
        cout << "4. Search Student by Roll No" << endl;
        cout << "5. Update Student Marks" << endl;
        cout << "6. Show Class Statistics" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 7) break;
        switch (choice) {
            case 1:
                cout << "Enter Roll No: "; cin >> roll;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Marks: "; cin >> marks;
                sms.insertRecord(roll, name, marks);
                break;
            case 2:
                cout << "Enter Roll No to delete: "; cin >> roll;
                sms.deleteRecord(roll);
                break;
            case 3:
                sms.displayAll();
                break;
            case 4:
                cout << "Enter Roll No to search: "; cin >> roll;
                sms.searchStudent(roll);
                break;
            case 5:
                cout << "Enter Roll No to update: "; cin >> roll;
                cout << "Enter New Marks: "; cin >> marks;
                sms.updateMarks(roll, marks);
                break;
            case 6:
                sms.displayStatistics();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}