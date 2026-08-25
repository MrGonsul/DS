#include <iostream>
using namespace std;

#define SIZE 5   // Maximum queue size

class Queue {
    int items[SIZE];
    int front, rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == SIZE - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Insert element
    void enqueue(int element) {
        if (isFull()) {
            cout << " Queue Overflow! Cannot insert more elements.\n";
            return;
        }
        if (front == -1)
            front = 0; // First element inserted

        items[++rear] = element;
        cout << " Inserted: " << element << endl;
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << " Queue Underflow! No elements to delete.\n";
            return;
        }
        cout << " Deleted: " << items[front++] << endl;

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
    // Display queue
    void display() {
        if (isEmpty()) {
            cout << " Queue is empty.\n";
            return;
        }
        cout << " Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
void initial()
{
    front=rear=-1;
}
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
    cout << "==============================\n";
    cout << "     SIMPLE QUEUE PROGRAM\n";
    cout << "==============================\n";


        cout << "\n-------------------------------\n";
        q.showFrontRear();  // Show front & rear before menu
        cout << "-------------------------------\n";
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Initialize queue\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
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
                if (q.isEmpty()){
                    q.initial();
                    cout<<"initialized\n";
                }
                else
                    cout<<"Queue is not empty yet\n";
                break;

            case 4:
                q.display();
                break;

            case 5:
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
