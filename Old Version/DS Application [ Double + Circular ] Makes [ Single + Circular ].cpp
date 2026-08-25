#include <iostream>
using namespace std;

// Double Linked List
class DNode
{
public:
	int data;
	DNode* Dnext;
	DNode* Dprev;
	
	DNode(int value)
	{
		data = value;
		Dnext = nullptr;
		Dprev = nullptr;
	}


};

// Single Linked List
class Node {

public :
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = nullptr;
	}

};

class CircularSingleDoubleLinkedList {
private:
	// Single
	Node* even;
	Node* odd;
	Node* head;
	Node* tail;


	// Double
	DNode* Dhead;
	DNode* Dtail;
public:
	CircularSingleDoubleLinkedList() {
		// Single
		head = nullptr;
		tail = nullptr;
		odd = nullptr;
		even = nullptr;

		// Double
		Dhead = nullptr;
		Dtail = nullptr;
	}

	// Methods

	// Insert At Head --> Single
	void InsertAtHeadSingle(int val) {

		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			head->next = head;

			return;
		}

		// If Not Null head
		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}

		// If We have One Node The Result of Out While is Self
		newNode->next = head;
		temp->next = newNode;
		temp = newNode;




	}


	// Insert At End -- > [ Single ]
	void InsertAtEndSingle(int val) {
		if (head == nullptr)
		{
			InsertAtHeadSingle(val);
			return;
		}
		Node* newNode = new Node(val);
		Node* temp = head;
		while (temp != head) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->next = head;
	}

	// Insert At Pos --> [ Single ]

	void InsertAtPosSingle(int val, int pos) {
		if (pos == 0) {
			InsertAtHeadSingle(val);
			return;
		}
		Node* newNode = new Node(val);
		Node* temp = head;
		int count = 0;
		while (count < pos - 1 && temp->next != head) {
			temp = temp->next;
			count++;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}

	// Delete At Head --> [ Single ]

	void DeleteAtHeadSingle() {
		if (head == nullptr) {
			cout << "Linked List Is Empty";
			return;
		}

		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}

		// We In Last Node
		Node* oldHead = head;
		head = head->next;
		temp->next = head; // New Head
		delete oldHead;

	}

	// Delete At Pos
	void DeleteAtPosSingle(int pos) {
		if (head == nullptr) {
			cout << "Linked List Is Empty";
			return;
		}

		if (pos == 0) {
			DeleteAtHeadSingle();
			return;
		}

		if (pos < 0) {
			return throw runtime_error("Invalid Input...");
		}

		Node* temp = head;
		Node* pre = nullptr;
		int i = 0;
		while (i < pos && temp->next != head) {
			pre = temp;
			temp = temp->next;
			i++;
		}

		pre->next = temp->next;
		delete temp;

	}

	// Display --> [ Single ]
	void Display() {
		if (head == nullptr)
			cout << "Linked List Is Empty..." << endl;
		else {
			Node* temp = head;
			do {

				cout << temp->data;
				if (temp->next != head)
					cout << " -> ";

				temp = temp->next;
			} while (temp != head);

		}


	}




	void Count() {

		if (head == nullptr) {
			return throw runtime_error("Null bro");
		}
		Node* temp = head;
		int c = 0;
		do {
			c++;
			temp = temp->next;
		} while (temp != head);

		cout << "Node Count : " << c << endl;
	}

	// Search
	void Search(int val) {

		if (head == nullptr) {
			return throw runtime_error("Null bro");
		}
		Node* temp = head;
		bool c = false;
		do {
			if (temp->data == val)
			{
				c = true;
				break;
			}
			temp = temp->next;
		} while (temp != head);

		if (c == true)
			cout << "The Value Is Found In List : " << val << endl;
		else
			cout << "The Value Is Not Found In List : " << val << endl;


	}

	// Reverse Circular Single Linked List
	void reverse() {
		if (head == nullptr) {
			return throw runtime_error("Null bro");
		}
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;
		do {
			next = current->next; // Store next node
			current->next = prev; // Reverse current node's pointer
			prev = current; // Move prev to current
			current = next; // Move to next node
		} while (current != head);
		head->next = prev; // Make the last node point to the new head
		head = prev; // Update head to the new first node
	}


	//===============================================================================
	// Insert At Head --> [ Double ]
	void InsertAtHeadDouble(int val) {
		DNode* newNode = new DNode(val);
		if (Dhead == nullptr) {
			Dhead = newNode;
			Dhead->Dnext = Dhead;
			Dhead->Dprev = Dhead;
			return;
		}
		DNode* temp = Dhead;
		while (temp->Dnext != Dhead) {
			temp = temp->Dnext;
		}
		newNode->Dnext = Dhead;
		newNode->Dprev = temp;
		temp->Dnext = newNode;
		Dhead->Dprev = newNode;
		Dhead = newNode;
	}

	// Insert At End --> [ Double ]
	void InsertAtEndDouble(int val) {
		if (Dhead == nullptr) {
			InsertAtHeadDouble(val);
			return;
		}
		DNode* newNode = new DNode(val);
		DNode* temp = Dhead;
		while (temp->Dnext != Dhead) {
			temp = temp->Dnext;
		}
		temp->Dnext = newNode;
		newNode->Dprev = temp;
		newNode->Dnext = Dhead;
		Dhead->Dprev = newNode;
	}

	// Insert At Pos --> [ Double ]
	void InsertAtPosDouble(int val, int pos) {
		if (pos == 0) {
			InsertAtHeadDouble(val);
			return;
		}
		DNode* newNode = new DNode(val);
		DNode* temp = Dhead;
		int count = 0;
		while (count < pos - 1 && temp->Dnext != Dhead) {
			temp = temp->Dnext;
			count++;
		}
		newNode->Dnext = temp->Dnext;
		newNode->Dprev = temp;
		temp->Dnext->Dprev = newNode;
		temp->Dnext = newNode;
	}
	// Delete At Head --> [ Double ]
	void DeleteAtHeadDouble() {
		if (Dhead == nullptr) {
			cout << "Linked List Is Empty";
			return;
		}
		DNode* temp = Dhead;
		while (temp->Dnext != Dhead) {
			temp = temp->Dnext;
		}
		DNode* oldHead = Dhead;
		Dhead = Dhead->Dnext;
		temp->Dnext = Dhead; // New Head
		Dhead->Dprev = temp; // New Head's Previous
		delete oldHead;
	}
	// Delete At Pos --> [ Double ]
	void DeleteAtPosDouble(int pos) {
		if (Dhead == nullptr) {
			cout << "Linked List Is Empty";
			return;
		}
		if (pos == 0) {
			DeleteAtHeadDouble();
			return;
		}
		if (pos < 0) {
			return throw runtime_error("Invalid Input...");
		}
		DNode* temp = Dhead;
		DNode* pre = nullptr;
		int i = 0;
		while (i < pos && temp->Dnext != Dhead) {
			pre = temp;
			temp = temp->Dnext;
			i++;
		}
		pre->Dnext = temp->Dnext;
		temp->Dnext->Dprev = pre;
		delete temp;
	}

	// Display --> [ Double ]
	void DisplayDouble() {
		if (Dhead == nullptr)
			cout << "Linked List Is Empty..." << endl;
		else {
			DNode* temp = Dhead;
			do {
				cout << temp->data;
				if (temp->Dnext != Dhead)
					cout << " <-> ";
				temp = temp->Dnext;
			} while (temp != Dhead);
		}
	}
	// Count --> [ Double ]
	void CountDouble() {
		if (Dhead == nullptr) {
			return throw runtime_error("Null bro");
		}
		DNode* temp = Dhead;
		int c = 0;
		do {
			c++;
			temp = temp->Dnext;
		} while (temp != Dhead);
		cout << "Node Count : " << c << endl;
	}

	// Search --> [ Double ]
	void SearchDouble(int val) {
		if (Dhead == nullptr) {
			cout << "List Is Empty" << endl;
			return;
		}

		bool found = false;
		DNode* temp = Dhead;
		do {
			if (temp->data == val) { found = true; break; }
			temp = temp->Dnext;
		} while (temp != Dhead);

		if (found)
			cout << "The Value Is Found In Double List : " << val << endl;
		else
			cout << "The Value Is Not Found In Double List : " << val << endl;
	}

	// Traversal BackWord

	void BackWord() {
		if (Dhead == nullptr)
			return;

		DNode* temp = Dhead->Dprev;  // Last Node

		do {
			cout << temp->data << " ";
			temp = temp->Dprev;
		} while (temp != Dhead->Dprev);
	}

};



int main()
{

	cout << "Welcome To DS Application [ Double + Circular ] Makes [ Single + Circular ]" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Linked List Single Circular" << endl;
	CircularSingleDoubleLinkedList list;
	


	list.InsertAtHeadSingle(10);
	list.InsertAtHeadSingle(20);
	list.InsertAtHeadSingle(30);
	list.InsertAtPosSingle(25, 2);
	list.DeleteAtPosSingle(2);


	list.Display();
	
	cout << endl;

	list.Count();

	list.Search(20);












	return 0;
}
