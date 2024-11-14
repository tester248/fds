#include <iostream>

using namespace std;

struct Stack {
    char data;
    Stack *next;
};

Stack *top = NULL;

// Function to push an element onto the stack
void push(char ch) {
    Stack *newNode = new Stack;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
char pop() {
    if (top == NULL) {
        return '\0'; // Empty stack
    }

    char popped = top->data;
    Stack *temp = top;
    top = top->next;
    delete temp;
    return popped;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == NULL;
}

bool isBalanced(const string& expression) {
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')') {
            if (isEmpty() || pop() != '(') {
                return false;
            }
        } else if (ch == '}') {
            if (isEmpty() || pop() != '{') {
                return false;
            }
        } else if (ch == ']') {
            if (isEmpty() || pop() != '[') {
                return false;
            }
        }
    }

    return isEmpty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}