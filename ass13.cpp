#include <iostream>

using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = order;
        cout << "Order " << order << " added to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to process.\n";
            return;
        }

        cout << "Order " << arr[front] << " processed.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Current orders: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the parlor can accept: ";
    cin >> maxOrders;

    CircularQueue queue(maxOrders);

    int choice;
    while (true) {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int orderNum;
                cout << "Enter order number: ";
                cin >> orderNum;
                queue.enqueue(orderNum);
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}