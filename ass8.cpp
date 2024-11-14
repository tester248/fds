#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

// Function to create a new node
Node *newNode(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *new_node = newNode(data);
    new_node->next = *head;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

// Function to print the list
void printList(Node *head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

// Function to compute 1's complement
Node *onesComplement(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        temp->data = 1 - temp->data;
        temp = temp->next;
    }
    return head;
}

// Function to compute 2's complement
Node *twosComplement(Node *head) {
    head = onesComplement(head);
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->data = 1;
    while (temp->prev != NULL && temp->data == 1) {
        temp->data = 0;
        temp = temp->prev;
        temp->data = 1;
    }
    return head;
}

// Function to add two binary numbers
Node *addBinaryNumbers(Node *head1, Node *head2) {
    Node *result = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = sum / 2;
        insertAtBeginning(&result, sum % 2);
        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }

    return result;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;

    // Insert binary numbers into linked lists
    insertAtBeginning(&head1, 1);
    insertAtBeginning(&head1, 0);
    insertAtBeginning(&head1, 1);
    insertAtBeginning(&head2, 1);
    insertAtBeginning(&head2, 1);

    cout << "First binary number: ";
    printList(head1);
    cout << "Second binary number: ";
    printList(head2);

    // Compute 1's complement
    cout << "1's complement of first number: ";
    printList(onesComplement(head1));

    // Compute 2's complement
    cout << "2's complement of first number: ";
    printList(twosComplement(head1));

    // Add binary numbers
    cout << "Sum of binary numbers: ";
    printList(addBinaryNumbers(head1, head2));

    return 0;
}