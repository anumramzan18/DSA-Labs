#include <iostream>
#include "textEditor.h"
using namespace std;
int main() {
    TextEditor editor;
    int choice;
    char ch;
    do {
        cout << "\n===== TEXT EDITOR =====" << endl;
        cout << "1. Type a character" << endl;
        cout << "2. Delete last character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Show text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter character to type: ";
            cin >> ch;
            editor.typeChar(ch);
            break;
            case 2:
            editor.deleteChar();
            break;
            case 3:
            editor.undo();
            break;
            case 4:
            editor.redo();
            break;
            case 5:
            editor.displayText();
            break;
            case 6:
            cout << "Exiting..." << endl;
            break;
            default:
            cout << "Invalid choice!" << endl;
        }

    } 
    while (choice != 6);
    return 0;
}