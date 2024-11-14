#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class BinaryNumber {
private:
    Node* head;
    Node* tail;
    int length;

public:
    BinaryNumber() : head(nullptr), tail(nullptr), length(0) {}

    // Function to append a binary digit to the list
    void append(int bit) {
        Node* newNode = new Node{bit, nullptr, tail};
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        length++;
    }

    // Function to display the binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* temp = head;
        while (temp) {
            temp->data = temp->data == 0 ? 1 : 0;
            temp = temp->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement() {
        onesComplement(); // First, get the 1's complement

        Node* temp = tail;
        int carry = 1;

        // Add 1 to the 1's complement to get 2's complement
        while (temp) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        // If there's a carry out, add a new node at the front
        if (carry) {
            Node* newNode = new Node{1, head, nullptr};
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to add two binary numbers
    BinaryNumber addBinary(BinaryNumber &other) {
        BinaryNumber result;
        Node* p = tail;
        Node* q = other.tail;
        int carry = 0;

        while (p || q || carry) {
            int sum = carry;
            if (p) {
                sum += p->data;
                p = p->prev;
            }
            if (q) {
                sum += q->data;
                q = q->prev;
            }
            result.append(sum % 2);
            carry = sum / 2;
        }

        // Reverse the result to correct order
        result.reverse();
        return result;
    }

    // Function to reverse the binary number list
    void reverse() {
        Node *temp = nullptr;
        Node *current = head;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }
};

int main() {
    BinaryNumber bin1, bin2, result;
    int choice, bit;

    cout << "Binary Number Operations using Doubly Linked List\n";
    cout << "Enter binary number (bit by bit):\n";
    cout << "Enter -1 to stop\n";

    // Input for the first binary number
    while (true) {
        cin >> bit;
        if (bit == -1) break;
        bin1.append(bit);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Binary Number\n";
        cout << "2. Compute 1's Complement\n";
        cout << "3. Compute 2's Complement\n";
        cout << "4. Add Another Binary Number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Binary Number: ";
                bin1.display();
                break;
            case 2:
                bin1.onesComplement();
                cout << "1's Complement: ";
                bin1.display();
                break;
            case 3:
                bin1.twosComplement();
                cout << "2's Complement: ";
                bin1.display();
                break;
            case 4:
                cout << "Enter the second binary number (bit by bit):\n";
                cout << "Enter -1 to stop\n";
                while (true) {
                    cin >> bit;
                    if (bit == -1) break;
                    bin2.append(bit);
                }
                result = bin1.addBinary(bin2);
                cout << "Sum: ";
                result.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
