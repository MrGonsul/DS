#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // ================= INSERT =================

    // Insert End (Enqueue - FIFO main)
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    // Insert Head
    void insertHead(int val) {
        insertEnd(val);
        front = rear->next;
    }

    // Insert Index
    void insertIndex(int val, int idx) {
        if (idx == 0) {
            insertHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = front;

        for (int i = 0; i < idx - 1 && temp->next != front; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == rear)
            rear = newNode;
    }

    // ================= DELETE =================

    // Delete Head
    void deleteHead() {
        if (isEmpty()) return;

        if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    // Delete End
    void deleteEnd() {
        if (isEmpty()) return;

        if (front == rear) {
            delete front;
            front = rear = NULL;
            return;
        }

        Node* temp = front;

        while (temp->next != rear) {
            temp = temp->next;
        }

        delete rear;
        rear = temp;
        rear->next = front;
    }

    // Delete Index
    void deleteIndex(int idx) {
        if (isEmpty()) return;

        if (idx == 0) {
            deleteHead();
            return;
        }

        Node* temp = front;

        for (int i = 0; i < idx - 1 && temp->next != front; i++) {
            temp = temp->next;
        }

        Node* del = temp->next;

        if (del == front) return;

        temp->next = del->next;

        if (del == rear)
            rear = temp;

        delete del;
    }

    // ================= REPLACE =================

    void replace(int oldVal, int newVal) {
        if (isEmpty()) return;

        Node* temp = front;

        do {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        } while (temp != front);
    }

    // ================= SEARCH =================

    bool search(int val) {
        if (isEmpty()) return false;

        Node* temp = front;

        do {
            if (temp->data == val)
                return true;

            temp = temp->next;
        } while (temp != front);

        return false;
    }

    // ================= DISPLAY =================

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    // INSERT
    q.insertEnd(10);
    q.insertEnd(20);
    q.insertEnd(30);

    q.insertHead(5);
    q.insertIndex(15, 2);

    q.display();

    // DELETE
    q.deleteHead();
    q.display();

    q.deleteEnd();
    q.display();

    q.deleteIndex(1);
    q.display();

    // REPLACE
    q.replace(20, 99);
    q.display();

    // SEARCH
    cout << "Search 99: " << q.search(99) << endl;
    cout << "Search 100: " << q.search(100) << endl;

    return 0;
}
