#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Action {
    char type; // 'T' for type, 'D' for delete
    char ch;   // character involved
};
class TextEditor {
private:
    string text;
    stack<Action> undoStack;
    stack<Action> redoStack;
public:
    TextEditor() {
        text = "";
    }
    void typeChar(char ch) {
        text += ch;
        undoStack.push({'T', ch});
        while (!redoStack.empty()) redoStack.pop(); 
    }
    void deleteChar() {
        if (text.empty()) {
            cout << "Nothing to delete!" << endl;
            return;
        }
        char ch = text.back();
        text.pop_back();
        undoStack.push({'D', ch});
        while (!redoStack.empty()) redoStack.pop(); 
    }
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }
        Action last = undoStack.top();
        undoStack.pop();

        if (last.type == 'T') {
            text.pop_back();      
            redoStack.push(last); 
        } else if (last.type == 'D') {
            text += last.ch;      
            redoStack.push(last);
        }
    }
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }
        Action last = redoStack.top();
        redoStack.pop();

        if (last.type == 'T') {
            text += last.ch;      
            undoStack.push(last);
        } else if (last.type == 'D') {
            text.pop_back();      
            undoStack.push(last);
        }
    }
    void displayText() {
        cout << "Current Text: \"" << text << "\"" << endl;
    }
};