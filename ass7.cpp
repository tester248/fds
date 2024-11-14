#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int PRN;
    char name[100];
    Node *next;
};

Node *head1 = NULL; // For first division
Node *head2 = NULL; // For second division

// Function to add a member
void addMember(Node *&head, int PRN, const char name[]) {
    Node *newNode = new Node;
    newNode->PRN = PRN;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a member
void deleteMember(Node *&head, int PRN) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->PRN == PRN) {
        Node *temp = head;
        head = head->next;
        delete temp;
    } else {
        Node *prev = NULL;
        Node *temp = head;
        while (temp != NULL && temp->PRN != PRN) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Member not found." << endl;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
}

// Function to compute total number of members
int countMembers(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to display members
void displayMembers(Node *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "PRN\tName" << endl;
    while (head != NULL) {
        cout << head->PRN << "\t" << head->name << endl;
        head = head->next;
    }
}

// Function to concatenate two lists
void concatenateLists(Node *&head1, Node *&head2) {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }

    Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    int choice, PRN;
    char name[100];

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add member to first division\n";
        cout << "2. Add member to second division\n";
        cout << "3. Delete member from first division\n";
        cout << "4. Delete member from second division\n";
        cout << "5. Count members in first division\n";
        cout << "6. Count members in second division\n";
        cout << "7. Display members of first division\n";
        cout << "8. Display members of second division\n";
        cout << "9. Concatenate lists\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN and name: ";
                cin >> PRN >> name;
                addMember(head1, PRN, name);
                break;
            case 2:
                cout << "Enter PRN and name: ";
                cin >> PRN >> name;
                addMember(head2, PRN, name);
                break;
            case 3:
                cout << "Enter PRN to delete: ";
                cin >> PRN;
                deleteMember(head1, PRN);
                break;
            case 4:
                cout << "Enter PRN to delete: ";
                cin >> PRN;
                deleteMember(head2, PRN);
                break;
            case 5:
                cout << "Total members in first division: " << countMembers(head1) << endl;
                break;
            case 6:
                cout << "Total members in second division: " << countMembers(head2) << endl;
                break;
            case 7:
                cout << "Members of first division:\n";
                displayMembers(head1);
                break;
            case 8:
                cout << "Members of second division:\n";
                displayMembers(head2);
                break;
            case 9:
                concatenateLists(head1, head2);
                cout << "Lists concatenated successfully." << endl;
                break;
            case 10:
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}