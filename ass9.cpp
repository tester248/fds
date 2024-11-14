#include <iostream>
#include <stack>
#include <cctype> // For std::tolower
#include <string> // For std::string
using namespace std;

void printReversedString(const string& str) {
    stack<char> charStack;

    for (char ch : str) {
        if (isalnum(ch)) { // Only consider alphanumeric characters
            charStack.push(tolower(ch)); // Convert to lowercase for uniformity
        }
    }
    cout << "Original String: " << str << endl;
    cout << "Reversed String: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
}

bool isPalindrome(const string& str) {
    stack<char> charStack;
    string cleanedStr;

    for (char ch : str) {
        if (isalnum(ch)) { // Only consider alphanumeric characters
            cleanedStr += tolower(ch); // Convert to lowercase
            charStack.push(tolower(ch)); // Push onto stack for comparison
        }
    }

    for (char ch : cleanedStr) {
        if (ch != charStack.top()) {
            return false; // Not a palindrome
        }
        charStack.pop();
    }

    return true; // Is a palindrome
}

int main() {
    string input;
    int choice;

    do 
    {
        cout<<"Menu:"<<endl;
        cout<<"1. Enter a string"<<endl;
        cout<<"2. Print reversed string"<<endl;
        cout<<"3. Check if palindrome"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout << "Enter a string: ";
                cin.ignore();
                getline(cin, input);
                break;
            case 2:
                printReversedString(input);
                break;
            case 3:
                if (isPalindrome(input)) {
                    cout << "The string is a palindrome." << endl;
                } else {
                    cout << "The string is not a palindrome." << endl;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    } while (choice != 4);

    return 0;
}
