#include <iostream>

using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int *queue;

public:
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = item;
        cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        int item = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    Queue q(10); // Create a queue of capacity 10

    int ch;
    do {
        cout << "\n\t------M E N U------";
        cout << "\n\t1.Add Job";
        cout << "\n\t2.Delete Job";
        cout << "\n\t3.Display Queue";
        cout << "\n\t4.Exit";
        cout << "\n\tEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            }
            case 2: {
                cout << "Dequeued value: " << q.dequeue() << endl;
                break;
            }
            case 3:
                q.display();
                break;
            case 4:
                cout << "\n\tThank you";
                break;
            default:
                cout << "\n\tInvalid choice";
                break;
        }
    } while (ch != 4);

    return 0;
}