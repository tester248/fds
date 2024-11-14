#include <iostream>
#include <cstring>
#include <cctype> 
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char c;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    bool empty() {
        return top == nullptr;
    }

    void push(char a) {
        Node* newNode = new Node;
        newNode->c = a;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            return; 
        }
        Node* temp = top; 
        top = top->next; 
        delete temp;
    }

    char Top() {
        if (top == nullptr) {
            return 0; 
        }
        return top->c;
    }
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3; // Highest precedence
    return 0;
}

string postfix(char str[]) {
    Stack s; 
    int j = 0;
    char post[25];
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (isalnum(ch)) {
            post[j++] = ch; 
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.Top() != '(') {
                post[j++] = s.Top(); 
                s.pop();
            }
            s.pop(); // Pop the '('
        } else if (isOperator(ch)) {
            while (!s.empty() && priority(s.Top()) >= priority(ch)) {
                post[j++] = s.Top(); 
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        post[j++] = s.Top(); 
        s.pop(); 
    }
    post[j] = '\0'; 

    return string(post);
}

string prefix(const string& str) {
    Stack stk;
    string result;

    // Reverse the string for prefix conversion
    for (int i = str.length() - 1; i >= 0; i--) {
        char c = str[i];

        if (isalnum(c)) {
            result += c;
        } else if (c == ')') {
            stk.push(c);
        } else if (c == '(') {
            while (!stk.empty() && stk.Top() != ')') {
                result += stk.Top();
                stk.pop();
            }
            stk.pop(); // Pop the ')'
        } else if (isOperator(c)) {
            while (!stk.empty() && priority(stk.Top()) > priority(c)) {
                result += stk.Top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.empty()) {
        result += stk.Top();
        stk.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    char str[25];
    char choice;

    cout << "\n1. Input\n2. Prefix\n3. Postfix\n4. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            cout << "Enter string: ";
            cin >> str;
        } else if (choice == '2') {
            cout << "Converting to prefix...\n";
            string res = prefix(string(str));
            cout << "Prefix expression: " << res << endl;
        } else if (choice == '3') {
            cout << "Converting to postfix...\n";
            string res = postfix(str);
            cout << "Postfix expression: " << res << endl;
        }

    } while (choice != '4');

    return 0;
}
