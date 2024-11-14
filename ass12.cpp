#include <iostream>

using namespace std;

class Deque {
public:
    int *arr;
    int front, rear, size;

    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        // If it's the first element, then set both front and rear as 0
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        // If it's the first element, then set both front and rear as 0
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        // If there is only one element, then reset front and rear
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        // If there is only one element, then reset front and rear
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }

    void printDeque() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != rear + 1);
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the deque: ";
    cin >> size;
    Deque dq(size);

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            }
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.printDeque();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}