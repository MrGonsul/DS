#include <iostream>
using namespace std;
// Mastered By Mr.Gonsul

class Node {

public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;

    }
};

class QueueLinkedListSingleCirqular {
private:
    Node* front;
    Node* rear;
public:

    QueueLinkedListSingleCirqular() {

        front = nullptr;
        rear = nullptr;

    }

    // Method 
    
    // Insert At Head
    void InsertAtHead(int val) {

        Node* newNode = new Node(val);

        if (front == nullptr) {
            front = rear = newNode;
            front->next = front; 
            return;
        }

        newNode->next = front;
        front = newNode;

        rear->next = front; 
    }


    // Insert At Tail
    void InsertAttail(int val) {
        if (front == nullptr) {
            InsertAtHead(val);
            return;
        }
        else {
            Node* newNode = new Node(val);

            rear->next = newNode;
            newNode->next = front;
            rear = newNode;


        }
    }


    // Display
    void Display() {

        if (front == nullptr)
            return;

        Node* temp = front;
        do {
            cout << temp->data;
            if (temp->next != front)
                cout << " -> ";
            temp = temp->next;
        } while (temp != front);

    }


    // Reverse Linked List
    void Reverse(QueueLinkedListSingleCirqular& l1) {

        Node* pre = nullptr;
        Node* temp = l1.front;
        Node* next = nullptr;

        Node* Stop = l1.front;
        do {

            next = temp->next;
            temp->next = pre;
            pre = temp;
            temp = next;


        } while (temp != Stop);

        l1.rear = l1.front;
        l1.front = pre;


        l1.rear->next = l1.front;
    }



};







int main()
{

    QueueLinkedListSingleCirqular llsc;

    llsc.InsertAtHead(31);
    llsc.InsertAtHead(32);
    llsc.InsertAtHead(50);

    llsc.Reverse(llsc);
    llsc.Display();

    return 0;
}
