#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//                          Linked List Mastered By Mr.Gonsul

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

};

class LinkedList {

private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

//---------------------------------------------------------------------------------------------------------------------------------------

    // Methods

    // Insert At Head  ->  O(1)
    void InsertAtHead(int val) {
    
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        
        }
        else {
        
            newNode->next = head;
            head = newNode;
            tail = newNode;  // باصي لي صاحبك خليه يعرف ينظمها
        }
    }

   
//---------------------------------------------------------------------------------------------------------------------------------------

    void InsertAtTail(int val) {
    
        if (head == nullptr)
            InsertAtHead(val);
        else {
            Node* newNode = new Node(val);
         
            tail->next = newNode;
            tail = newNode;
        
        }
    
    
    }  
//---------------------------------------------------------------------------------------------------------------------------------------

    // Reverse
    // Time complexly is O(n)
    void DisplayReverse() {
       
        Node* prev = nullptr; 
        Node* next = nullptr;

        while (head != nullptr){
        next = head->next;
        head->next = prev;

        prev = head;
        head = next;
        }


        head = prev;

   
    }
//---------------------------------------------------------------------------------------------------------------------------------------

    // Display 
    void Display() {
    
        Node* temp = head;
        while (temp!= nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Nullptr" << endl;
    }


//---------------------------------------------------------------------------------------------------------------------------------------

    // Merge
    // O(N * M + Log n)
    void Merge(LinkedList OtherLinkedList) {
    
        vector <int> num;
        
        Node* temp =head;

        while (temp != nullptr) {
        
            num.push_back(temp->data);
            temp = temp->next;

        }
    
        temp = OtherLinkedList.head;
        
        while (temp != nullptr) {

            num.push_back(temp->data);
            temp = temp->next;

        }

        // بعد ما عبيت توا ندير ترتيب ايزي
        sort(num.begin(), num.end());


        // Free Memory
        while (head != nullptr)
            DeleteHead();
    
        head = new Node(num.at(0));  // Or Just Use - 1 Called dummy Linked List

        Node* curr = head;
        for (int i = 1; i < num.size(); i++) {
        
            curr->next = new Node(num.at(i));
            curr = curr->next;
        
        }

       
    }





//---------------------------------------------------------------------------------------------------------------------------------------

 // Delete At head
    void DeleteHead() {
    
        Node* temp = head;
        head = head->next;
        delete temp;
    
    }








//---------------------------------------------------------------------------------------------------------------------------------------
    // O(m*n) Another Linked List Merge
    void Merge1(LinkedList& OtherLinked)
    {
        Node* curr = head;
        Node* currOther = OtherLinked.head;

        if (curr == nullptr) {
            head = currOther;
            return;
        }

        if (currOther == nullptr)
            return;

        Node* result = nullptr;

        if (curr->data <= currOther->data) {
            result = curr;
            curr = curr->next;
        }
        else {
            result = currOther;
            currOther = currOther->next;
        }

        Node* currResult = result;

        while (curr != nullptr && currOther != nullptr)
        {
            if (curr->data <= currOther->data)
            {
                currResult->next = curr;
                currResult = curr;

                curr = curr->next;
            }
            else
            {
                currResult->next = currOther;
                currResult = currOther;

                currOther = currOther->next;
            }
        }

        if (curr != nullptr)
            currResult->next = curr;

        if (currOther != nullptr)
            currResult->next = currOther;

        head = result;
        OtherLinked.head = nullptr;
    }






//---------------------------------------------------------------------------------------------------------------------------------------






//---------------------------------------------------------------------------------------------------------------------------------------




//---------------------------------------------------------------------------------------------------------------------------------------






//---------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------






//---------------------------------------------------------------------------------------------------------------------------------------






//---------------------------------------------------------------------------------------------------------------------------------------

};





int main()
{

    LinkedList l1;
    l1.InsertAtHead(5);
    l1.InsertAtHead(10);
    l1.InsertAtHead(15);
    l1.DisplayReverse();
 //------------------------
    LinkedList l2;
    l2.InsertAtHead(5);
    l2.InsertAtHead(10);
    l2.InsertAtHead(15);

    l1.Merge1(l2);
    l1.Display();

    return 0;
}
