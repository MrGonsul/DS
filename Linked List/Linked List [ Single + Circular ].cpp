#include <iostream>
using namespace std;
// Mastered By Mr.Gonsul

class Node {

public :
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;

    }
};

class LinkedListSingleCirqular{
private:
    Node* head;
    Node* tail;
public:

    LinkedListSingleCirqular() {
        
        head = nullptr;
        tail = nullptr;

    }
    
        // Method 

    // Insert At Head 
    void InsertAtHead(int val) {

        Node* newNode = new Node(val);
        if (head == nullptr) {
           
            head = tail = newNode;
            head->next = head;

            return;
        }
        else {

            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

    }


    // Insert At Tail
    void InsertAttail(int val) {
        if (head == nullptr) {
            InsertAtHead(val);
            return;
        }
        else {
            Node* newNode = new Node(val);

            tail->next = newNode;
            newNode->next = head;
            tail = newNode;


        }
    }


    // Display
    void Display() {

        if (head == nullptr)
            return;

        Node* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head)
                cout << " -> ";
            temp = temp->next;
        } while (temp != head);

    }


    // Reverse Linked List
    void Reverse(LinkedListSingleCirqular &l1) {

        Node* pre = nullptr;
        Node* temp = l1.head;
        Node* next = nullptr;

        Node* Stop = l1.head;
        do {
        
            next = temp->next;
            temp->next = pre;
            pre = temp;
            temp = next;
        
           
        } while (temp != Stop);
       
        l1.tail = l1.head;  
        l1.head = pre;

       
        l1.tail->next = l1.head;
    }



};







int main()
{

    LinkedListSingleCirqular llsc;
    
    llsc.InsertAtHead(31);
    llsc.InsertAtHead(32);
    llsc.InsertAtHead(50);
    
    //llsc.Reverse(llsc);
    llsc.Display();

    return 0;
}
