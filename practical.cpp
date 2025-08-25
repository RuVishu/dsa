#include <iostream>
#include <string>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int el) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = el;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string expression) {
    Stack s(100);

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch >= '0' && ch <= '9') {  
            s.push(ch - '0');  
        } else {  
            int b = s.pop();
            int a = s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }

    return s.pop(); 
}
int evaluatePrefix(string expression) {
    Stack s(100);

    for (int i = expression.length() - 1; i >= 0; i--) {
        char ch = expression[i];

        if (ch >= '0' && ch <= '9') {  
            s.push(ch - '0');
        } else {  
            int a = s.pop();
            int b = s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }

    return s.pop(); 
}

int main() {
    string postfix = "53+82-*";
    string prefix = "-+5382";

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Postfix Evaluation Result: " << evaluatePostfix(postfix) << endl;

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Prefix Evaluation Result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
