#pragma once
#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class QueueUsingStacks {
private:
    stack<T> s1, s2;
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    void enqueue(T value) {
        s1.push(value);
    }
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return T();
        }
        if (s2.empty()) {
            transfer();
        }
        T val = s2.top();
        s2.pop();
        return val;
    }
    T front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return T();
        }
        if (s2.empty()) {
            transfer();
        }

        return s2.top();
    }
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty  ";
            return;
        }
        stack<T> temp1 = s1;
        stack<T> temp2 = s2;
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        stack<T> reverseStack;
        while (!temp1.empty()) {
            reverseStack.push(temp1.top());
            temp1.pop();
        }
        while (!reverseStack.empty()) {
            cout << reverseStack.top() << " ";
            reverseStack.pop();
        }

        cout << endl;
    }
};