#include <iostream>
using namespace std;

#define SIZE 5   // Maximum number of elements in the queue

class CircularQueue {
    int items[SIZE];
    int front, rear;

public:
    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert (enqueue) an element
    void enqueue(int element) {
        if (isFull()) {
            cout << " Queue Overflow! Cannot insert " << element << endl;
            return;
        }

        // First element insertion
        if (front == -1)
            front = 0;

        // Circular increment of rear
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << " Inserted: " << element << endl;
    }

    // Delete (dequeue) an element
    void dequeue() {
        if (isEmpty()) {
            cout << " Queue Underflow! No elements to delete.\n";
            return;
        }
        else{




        cout << " Deleted: " << items[front] << endl;

        // Queue becomes empty after deletion
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Circular increment of front
        }
        }
        }


    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << " Queue is empty.\n";
            return;
        }

        cout << " Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    // Show front and rear positions and values
    void showFrontRear() {
        if (isEmpty()) {
            cout << " Queue is empty | Front: None | Rear: None\n";
        } else {
            display();
            cout << " Front index: " << front << " Rear index: " << rear << "\n";
        }
    }
};

// Main function with menu
int main() {
    CircularQueue q;
    int choice, value;

    cout << "==============================\n";
    cout << "     CIRCULAR QUEUE PROGRAM\n";
    cout << "==============================\n";

    while (true) {

        cout << "\n-------------------------------\n";
        q.showFrontRear();  // Show front & rear before menu
        cout << "-------------------------------\n";

        cout << "Menu:\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << " Exiting program... Goodbye!\n";
                return 0;

            default:
                cout << " Invalid choice! Please try again.\n";
        }
        system("pause");
    system("CLS");
    }

    return 0;
}
