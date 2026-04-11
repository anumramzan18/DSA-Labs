#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
    int top;
    const int capacity = 100; 
    char arr[100];
public:
    Stack() {
           top = -1;
           }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; 
           
    }
    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};
int getPrecedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
int main() {
    cout << "--STACK APPLICATIONS--" << endl;
    string inputStr = "Hello";
    Stack s1;
    for (int i = 0; i < inputStr.length(); i++) {
        s1.push(inputStr[i]);
    }
    cout << "\n1. Reverse a String" << endl;
    cout << "Input: " << inputStr << " -> Output: ";
    while (!s1.isEmpty()) {
        cout << s1.pop();
    }
    cout << endl;
    string expr = "((a+b)*c)";
    Stack s2;
    bool balanced = true;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s2.push('(');
        } else if (expr[i] == ')') {
            if (s2.isEmpty()) {
                balanced = false;
                break;
            }
            s2.pop();
        }
    }
    if (!s2.isEmpty()) balanced = false;
    cout << "\n2. Check Balanced Parentheses" << endl;
    cout << "Input: " << expr << " -> " << (balanced ? "Balanced" : "Not Balanced") << endl;
    string infix = "(a+b)*c";
    string postfix = "";
    Stack s3;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        } 
        else if (c == '(') {
            s3.push(c);
        } 
        else if (c == ')') {
            while (!s3.isEmpty() && s3.peek() != '(') {
                postfix += s3.pop();
            }
            s3.pop();
        } 
        else {
            while (!s3.isEmpty() && getPrecedence(c) <= getPrecedence(s3.peek())) {
                postfix += s3.pop();
            }
            s3.push(c);
        }
    }
    while (!s3.isEmpty()) {
        postfix += s3.pop();
    }
    cout << "\n3. Convert Infix to Postfix" << endl;
    cout << "Input: " << infix << " -> Output: " << postfix << endl;
    return 0;
}