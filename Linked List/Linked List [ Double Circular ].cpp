#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Mastered By Mr.Gonsul


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedListDoubleCircular {

private:
    vector<int> Listnum;
    vector<Node*> linkedList;
    Node* head;
    Node* tail;

public:

    LinkedListDoubleCircular() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert Head
    void InsertAthead(int val) {

        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }

    // Insert Tail
    void InsertAtTail(int val) {

        if (head == nullptr) {
            InsertAthead(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;
    }

    // Display Forward
    void DisplayForWord() {

        if (head == nullptr) return;

        Node* temp = head;

        do {
            cout << temp->data;
            if (temp->next != head)
                cout << " <-> ";
            temp = temp->next;

        } while (temp != head);

        cout << "\n";
    }

    // Fill Vectors
    void Vectory(vector<int>& jester, vector<Node*>& yuna) {

        if (head == nullptr) return;

        Node* temp = head;

        do {
            jester.push_back(temp->data);
            yuna.push_back(temp);
            temp = temp->next;

        } while (temp != head);

        cout << "Vector filled: " << jester.size() << "\n";
    }

    void vectory() {
        Listnum.clear();
        linkedList.clear();
        Vectory(Listnum, linkedList);
    }

    // Merge vector into list
    void merge(vector<Node*> SS) {

        head = tail = nullptr;

        for (Node* out : SS) {
            InsertAtTail(out->data);
        }
    }

    void s1() {
        merge(linkedList);
    }

    // Sort (IMPORTANT FIX)
    void Sort() {

        if (Listnum.empty()) return;

        // reverse(Listnum.begin(), Listnum.end());


        sort(Listnum.begin(), Listnum.end());
    }

    // Split
    void Spilt() {

        if (head == nullptr) return;

        vector<int> odd;
        vector<int> even;

        Node* h1 = head;

        do {
            if (h1->data % 2 == 0)
                even.push_back(h1->data);
            else
                odd.push_back(h1->data);

            h1 = h1->next;

        } while (h1 != head);

        head = tail = nullptr;

        for (int x : even) InsertAtTail(x);
        for (int x : odd) InsertAtTail(x);
    }

    // Rebuild from sorted vector
    void ha() {

        head = tail = nullptr;

        for (int val : Listnum) {
            InsertAtTail(val);
        }
    }

    // Delete Head (FIXED)
    Node* deletehead(Node*& l1) {

        if (head == nullptr) return nullptr;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return l1;
        }

        Node* t = head;

        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete t;

        return l1;
    }


       // Reverse
    void Reverse(LinkedListDoubleCircular& l1) {

        Node* temp = nullptr;
        Node* current = l1.head;
       

        Node* Stop = head; // Taking De Refrence To Stop Into it

        do {
           
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            current = temp;

        } while (current != Stop);

        
        temp = l1.head;
        l1.head = l1.tail;
        l1.tail = temp;
    

    }

};


int main()
{
	LinkedListDoubleCircular lldc;

	lldc.InsertAthead(1);
	lldc.InsertAthead(2);
	lldc.InsertAtTail(3);
	lldc.InsertAtTail(4);
	lldc.InsertAtTail(8);
	lldc.InsertAtTail(5);
	lldc.vectory();   
	lldc.Sort();
	lldc.ha();

    lldc.Reverse(lldc);

	lldc.DisplayForWord();
	// lldc.Spilt(lldc);
	
	
	return 0;
}
