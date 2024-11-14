#include <iostream>
#include <cstring>

using namespace std;

struct Stack {
    char data[100];
    int top;
};

void initialize(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == 99;
}

void push(Stack &s, char x) {
    if (isFull(s)) {
        cout << "Stack Overflow" << endl;
        return;
    }
    s.top++;
    s.data[s.top] = x;
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    char x = s.data[s.top];
    s.top--;
    return x;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initialize(s);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(s, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(s) && s.data[s.top] != '(') {
                postfix[j++] = pop(s);
            }
            pop(s); // Pop the '('
            i++;
        } else { // Operator
            while (!isEmpty(s) && precedence(infix[i]) <= precedence(s.data[s.top])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i++]);
        }
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    initialize(s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            push(s, postfix[i] - '0'); // Convert char to int
        } else {
            int op2 = pop(s);
            int op1 = pop(s);

            switch (postfix[i]) {
                case '+':
                    push(s, op1 + op2);
                    break;
                case '-':
                    push(s, op1 - op2);
                    break;
                case '*':
                    push(s, op1 * op2);
                    break;
                case '/':
                    push(s, op1 / op2);
                    break;
            }
        }
    }

    return pop(s);
}

int main() {
    char infix[100], postfix[100];
    int choice;

    do {
        cout << "Menu:\n";
        cout<<"1. Enter infix expression\n";
        cout<<"2. Postfix expression\n";
        cout<<"3. Postfix evaluation\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                infixToPostfix(infix, postfix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            case 3:
                int result = evaluatePostfix(postfix);
                cout << "Result: " << result << endl;
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }

    }

    return 0;
}