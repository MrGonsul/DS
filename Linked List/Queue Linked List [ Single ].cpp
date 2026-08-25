#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

class Node {

public:
	Node* next;
	int data;

	Node(int val) {
		data = val;
		next = nullptr;
	}

};



class QueueLinkedList {

private:
	Node* front; // head;
	Node* rear; //  tail;
	Node* evenHead = nullptr;
	Node* eventail = nullptr;
	Node* oddHead = nullptr;
	Node* oddtail = nullptr;



public:

	QueueLinkedList() {
		front = nullptr;
		rear = nullptr;

	}


	// Insert At Tail O(1)
	void Enqueue(int val) {

		Node* newNode = new Node(val);
		if (rear == nullptr) {
			front = rear = newNode;

		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}

	}

	// Delete At head O(1)
	void Dequeue() {
		Node* temp = front;
		if (front == nullptr) {
			cout << "Queue is Empty" << endl;
			return;
		}
		else
			// one Item
			if (front->next == nullptr) {
				front = front->next;
				delete temp;
				rear = front = nullptr;


			} // Multi item
			else {
				front = front->next;
				delete temp;


			}

	}

	// Odd Even
	void EnqueueOddEven(int val) {

		Node* newNode = new Node(val);

		// even queue
		if (val % 2 == 0) {

			if (evenHead == nullptr) {
				evenHead = eventail = newNode;
			}
			else {
				eventail->next = newNode;
				eventail = newNode;
			}
		}
		// odd queue
		else {

			if (oddHead == nullptr) {
				oddHead = oddtail = newNode;
			}
			else {
				oddtail->next = newNode;
				oddtail = newNode;
			}
		}


		// MERGE 


		if (evenHead == nullptr) {
			front = oddHead;
			rear = oddtail;
		}
		else if (oddHead == nullptr) {
			front = evenHead;
			rear = eventail;
		}
		else {
			eventail->next = oddHead;
			front = evenHead;
			rear = oddtail;
		}


		// PRINT


		Node* temp = front;
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}

	// Merge O(n)
	void merge(QueueLinkedList& other)
	{
		if (front == nullptr)
		{
			front = other.front;
			rear = other.rear;
		}
		else
		{
			Node* current = front;
			while (current->next != nullptr)
				current = current->next;

			current->next = other.front; // Link the two lists
		}
		
		other.front = nullptr;
		other.front = nullptr;

	}


	// Sort For Loop (n*n)
	void Sorting(QueueLinkedList q1) {


		if (front->next == nullptr)
				return;

		for (Node* i = q1.front; i != nullptr; i = i->next)
		{
			for (Node* j = i->next; j != nullptr; j = j->next)
			{
				if (i->data > j->data)
				{
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}





	// Print Odd Even OR Upper Lower  O(n)
	void OddEven(Node* root) {

		if (root == nullptr)
			return;

		// Upper
		// OddEven(root->next);

		if (root->data % 2 == 0)
			cout << root->data << " ->";

		// Mid
		OddEven(root->next);

		if (root->data % 2 != 0)
			cout << root->data << " ->";

		// Lower
		// OddEven(root->next);
	}

	void KO() {
		OddEven(front);
	}

	// Sort By using Vector O(log n  + N for Insert)
	void SortVector(QueueLinkedList& l1) {
		vector<int> temp;

		Node* t = l1.front;

		while (t != nullptr) {
			Node* deleteNode = t;
			temp.push_back(t->data);
			t = t->next;
			delete deleteNode;
		}
		// Clear Node
		front = rear = nullptr;


		// Sort
		sort(temp.begin(), temp.end());

		// reverse o( log n ) if sorted
		reverse(temp.begin(), temp.end());


		// For Each For Display
		for (int out : temp)
			cout << out << " -> ";


	}



	// Print O(n) 
	void Display() {
		Node* temp = front;

		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}

		cout << "nullptr" << endl;
	}

};



int main()
{
	QueueLinkedList qll;

	//qll.Dequeue();
	//qll.EnqueueOddEven(1);

	qll.Enqueue(2);
	qll.Enqueue(1);
	qll.Enqueue(3);
	qll.Enqueue(5);
	qll.Enqueue(8);
	qll.Enqueue(6);
	qll.Enqueue(4);

	// qll.KO();
	qll.Sorting(qll);
	
	// qll.Display();

	// qll.SortVector(qll);

	return 0;
}
