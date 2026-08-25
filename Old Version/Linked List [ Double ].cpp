#include <iostream>
using namespace std;


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


class DoubleLinkedList {

private :
	Node* head;
public :
	DoubleLinkedList() {
		head = nullptr;
	}

	// Methods

	// Insert At head
	void InsertAtHead(int val) {

		Node* newNode = new Node(val);
		newNode->next = head;
		if (head != nullptr) {
			head->prev = newNode;
		}

		head = newNode;

	}

	// Insert At Pos 
	void InsertAtpos(int pos, int val) {

		if (head == nullptr){
			InsertAtHead(val);
		return;
	}
		if (pos < 0)
			cout << "Invalid Pos..." << endl;
		else {
			Node* newNode = new Node(val);
			Node* temp = head;
			int i = 0;
			while (i < pos-1 && temp != nullptr) {
				temp = temp->next;
				i++;
			}
			if (temp == nullptr)
				return throw runtime_error("Item Not Found ... ");
			else {

				// We Are At Pos-1 And We Want Do link newNode At Pos
				newNode->next = temp->next;
				newNode->prev = temp;
				
				// if temp->next is not null then only we can access its prev
				if (temp->next != nullptr)
				temp->next->prev = newNode;
				temp->next = newNode;

			}




		}


	}

	// Insert At End
	void InsertAtEnd(int val) {

		if (head == nullptr) {
			InsertAtHead(val);
			return;
		}
		
		Node* newNode = new Node(val);
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;


	}
	

	// Delete At Head
	void DeleteAtHead() {
		if (head == nullptr) {
			cout << "List Is Empty...";
			return;
		}
		
		// If We Have One Linked List [ Node ]
		// if (head->next == nullptr) {
		//  head = nullptr;
		// }


		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}

	// Display Forword

	void DForword() {

		if (head == nullptr) {
			cout << "List Is Empty...";
			return;
		}

		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data;
			if (temp->next != nullptr)
				cout << " -> ";
			temp = temp->next;
		}



	}



	// BackWord Display
	void BackWord() {

		if (head == nullptr) {
			cout << "List Is Empty...";
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		// Now Back Word
	
		while (temp != nullptr)
		{
			cout << temp->data;
			if (temp->prev != nullptr)
				cout << " <- ";
			temp = temp->prev;
		}


	}


	// Delete At End
	void DeleteAtEnd() {
		if (head == nullptr) {
			cout << "List Is Empty...";
			return;
		}
		
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->prev->next = nullptr; // Go To Prev Node And Make Its Next Null
		delete temp;

	}


	// Count
	void Counter(Node* Find , int* i) {
		if (Find == nullptr) {
			return;
		}

		(*i)++;
		Counter(Find->next, i);
	}

	void c() {
		if (head == nullptr) {
			cout << "Linked List Is Empty..." << endl;
			return;
		}

		int Count = 0;
		 
			Counter(head, &Count);
			cout << "Count Of Node Is : " << Count << endl;

	}

	// Search
	bool Search(Node* Find, int key) {
		if (Find == nullptr) {
			return false;
		}
		if (Find->data == key) {
			return true;
		}
		return Search(Find->next, key);
	}

	// Replacer Using Recursion
	void Replacer(Node* Find, int key, int newVal) {
		if (Find == nullptr) {
			return;
		}
		if (Find->data == key) {
			Find->data = newVal;
		}
		Replacer(Find->next, key, newVal);
	}

	/* 
	
		Question 1 :
		Enter from 1 - 10 Node with Same Value 1-10
		The Even Node will be left and right will be odd
		
		Hint : Using Recursion 
	
	*/ 
	void OddEven(Node* BST) {

		if (BST == nullptr) 
			return;
		
	
		if (BST->data % 2 == 0)
			cout << BST->data << " -> ";
		

		// Mid	
		OddEven(BST->next);


		if (BST->data % 2 != 0)
			cout << BST->data << " -> ";
		
		
	
	}






	void OddEven() {
		if (head == nullptr) {
			cout << "List Is Empty..." << endl;
			return;
		}
		cout << "Odd Even List : " << endl;
		OddEven(head);


	}

	};







int main()
{
	DoubleLinkedList Dll;
	Dll.InsertAtHead(1);
	Dll.InsertAtHead(2);
	Dll.InsertAtHead(3);
	Dll.InsertAtHead(4);
	Dll.InsertAtHead(5);
	Dll.InsertAtHead(6);
	Dll.InsertAtHead(7);
	Dll.InsertAtHead(8);
	Dll.InsertAtHead(9);

	Dll.DeleteAtEnd();
	cout << "List Forword : ";
	Dll.DForword();
	cout << endl;
	cout << "=========================================="<<endl;
	cout << "List Backward : ";
	Dll.BackWord();
	cout << endl;
	cout << "==========================================" << endl;
	Dll.c();

	cout << "==========================================" << endl;
	// Dll.Replacer(Dll.head, 20, 100);
	
	Dll.OddEven();
	
	
	
	return 0;
}
