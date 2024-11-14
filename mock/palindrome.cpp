#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to clean and prepare the string for palindrome check
string preprocessString(const string &str) {
    string cleanedStr;
    for (char ch : str) {
        if (isalnum(ch)) {  // Ignore non-alphanumeric characters
            cleanedStr += tolower(ch);  // Convert to lowercase for case insensitivity
        }
    }
    return cleanedStr;
}

// Function to reverse the string manually without using <stack>
string reverseString(const string &str) {
    string reversedStr;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

// Function to check if the string is a palindrome
bool isPalindrome(const string &str) {
    string cleanedStr = preprocessString(str);
    int n = cleanedStr.length();

    // Check for palindrome by comparing characters from start and end
    for (int i = 0; i < n / 2; i++) {
        if (cleanedStr[i] != cleanedStr[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    int choice;

    cout << "Enter a string: ";
    getline(cin, input);

    do {
        cout << "\nMenu:\n";
        cout << "1. Print Original and Reversed String\n";
        cout << "2. Check if Palindrome\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore newline character from input buffer

        switch (choice) {
            case 1:
                cout << "Original String: " << input << endl;
                cout << "Reversed String: " << reverseString(input) << endl;
                break;
            case 2:
                if (isPalindrome(input)) {
                    cout << "The string is a palindrome." << endl;
                } else {
                    cout << "The string is not a palindrome." << endl;
                }
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
