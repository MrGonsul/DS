#include <iostream>
using namespace std;

//                  Mastered Linked List [ Single ]

class Node{
	public:
		int data;
		Node* next;

public :
	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class LinkedListSingle {

private:
	Node* head;

public :

	LinkedListSingle() {
		head = nullptr;
	}

	// Methods


	// Insert at head
	void InsertAtHead(int val) {
	
		Node* newNode = new Node(val);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	
	}

	// Insert at end
	void InsertAtEnd(int val) {

		Node* newNode = new Node(val);
		if (head == nullptr) {
			InsertAtHead(val);
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}

	}

	// Display the list
	void Display() {
		Node* temp = head;
		while(temp!= nullptr)
		{ 
			if (temp->next != nullptr)
				cout<<" -> ";
				cout << temp->data;
			
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}

	// Delete At Head
	void DeleteAtHead() {

		Node* temp = head;
		head = head->next;
		delete temp;


	}

	// Delete At End
	void DeleteAtEnd() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}

		if (head->next == nullptr) {
			DeleteAtHead();
			return;
		}

		Node* temp = head;
		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		
		delete temp->next;
		temp->next = nullptr;
	}


	// DeleteAtPosition
	void DeleteAtPos(int pos) {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		if (head->next == nullptr || pos == 1) {
			DeleteAtHead();
			return;
		}
		if (pos < 0)
		{
			cout << "Invalid position" << endl;
			return;

		}
		int i = 0;
		Node* temp = head;
		Node* prev = nullptr;
		while (i < pos-1 && temp != nullptr) {
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		delete temp;



	}

	// Insert At Position

	void InsertAtPos(int val, int idx) {
		Node* newNode = new Node(val);

		if (head == nullptr || idx == 1) {
			InsertAtHead(val);
			return;
		}

		Node* temp = head;
		int i = 0;
		while (i<idx-1 && temp!=nullptr) {
			temp = temp->next;
			i++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
				




	}

	// Search
	void Search(int key) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == key) {
				cout << "Element found: " << key << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Element not found: " << key << endl;
	}

	// Traverse the list
	void Traverse() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr) {
			
			cout << temp->data;
			if (temp != nullptr)
				cout << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;

	}

	// Find Item And Replace it
	void Replacer(int old, int New) {

		if (head == nullptr) {
			cout << "List Is Empty";
			return;
		}

		Node* temp = head;
		while (temp != nullptr && temp->data !=old) {
			temp = temp->next;
		}
		temp->data = New;




	}

	// Count 

	void Counter(Node* head, int *counter) {

		if (head == nullptr) {
			return;
		}

		(*counter)++;
		Counter(head->next, counter);

	}

	void C(int &counter) {

		Counter(head, &counter);

		cout << "Counter In List Is :" << counter;

	}


	// Reverse Using Itrator ==> Add Void Display Normally
	void Reverse(Node* &head) {
		// Create New Pointers
		Node* pre = nullptr; // Previous State
		Node* temp = head; // Normal State
		Node* next = nullptr; // Next State like  next->next = temp->next;

		while (temp!=nullptr) {

			next = temp->next;    // Store Next State
			temp->next = pre;     // Change Next State To Previous State
			pre = temp;           // Move Previous State To Normal State
			temp = next;          // Move Normal State To Next State

		}

		head = pre;               // Update Head To New Head After Reverse
		
	}

	



	//  Print Reverse using Recursion
	void PrintReverse(Node* curr) {
		if (curr == nullptr) {
			return;
		}

		PrintReverse(curr->next);// GO TO LAST NODE
		cout << curr->data << " -> ";
	}

	void PR() {
		PrintReverse(head);
		cout << "NULL" << endl;
	}

	
	// Clear All List
	void clear(Node* &head) {
		if (head == nullptr)
			return;
		

		clear(head->next); // Go To last Node
		Node* temp = head;
		delete temp;
		head = nullptr;
	}


	// Delete Node without Using Head Pointer
	void DeleteNoHead(Node* &root) {

		root->data = root->next->data;
		Node* temp = root->next;
		root->next = temp->next; // We Can Do root ->next = root ->next->next;
		delete temp;
	}


	// Sort Single Linked List
	void Sort() {

		if (head == nullptr || head->next == nullptr)
			return;

		// Node* temp = head;    while(temp!=nullptr)  temp = temp->next;
		for (Node* i = head;     i != nullptr;         i = i->next) {
			for (Node* j = i->next; j != nullptr; j = j->next ) {

				if (i->data > j->data) {

					int temp = i->data;   // temp = arr[j];
					i->data = j->data;   // arr[i] = arr[j];
					j->data = temp;     // arr[j] = temp;

				}



			}
		}

	}


	// Merge
	void Merge(LinkedListSingle &l2) { // & For Changing Value And Clear Linked Other

		if (head == nullptr) {
			head = l2.head; 
			
		}
			
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = l2.head; // Link Last Node Of First List To First Node Of Second List


		}

		l2.head = nullptr; // Clear Linked List The Other
		
	


	}


	// Find Middle Node
	void Fmiddle() { 

		Node* pre = head;  // First Step Checking  if the pre have value and Not nullptr
		Node* next = head; // Second Step Checking if the Next Is Null Or Not

		if (head == nullptr)
			return;

		while (next && next->next) { // Check If Next Is Not Null And Next->Next Is Not Null
			pre = pre->next; // Step 1
			next = next->next->next; // Double Step 2
		}

		cout << "The Mid Node Is : " << pre->data << endl;


	}

	// detect Loop In Linked List
	
	bool IsHavingLoop() {
		Node* pre = head;
		Node* next = head;

		if (head == nullptr)
			return false;

		else {
			while (next && next->next){
				pre = pre->next; // 1 step
				next = next->next->next; // 2 step

				if (pre == next) // Yep their IS Loop
					return true;



			}

			return false;
		}


	}


	// MergeSort
	Node* Merge(Node* N1, Node* N2) {
		if (N1 == nullptr) return N2;
		if (N2 == nullptr) return N1;

		if (N1->data < N2->data) {
			N1->next = Merge(N1->next, N2);
			return N1;
		}
		else {
			N2->next = Merge(N1, N2->next);
			return N2;
		}
	}


	void MS(LinkedListSingle* l1, LinkedListSingle* l2) {
		head = Merge(l1->head, l2->head);
		cout << "Merged And Sorted List : " << endl;
		Traverse();

	}


	// Duplicate Removal From Sorted List
	void RemoveDuplicates() {
		if (head == nullptr)
			return;
		Node* temp = head;
		while (temp->next != nullptr) {
			if (temp->data == temp->next->data) {
				Node* toDelete = temp->next;
				temp->next = temp->next->next; // Skip The Duplicate Node
				delete toDelete; // Free Memory
			}
			else {
				temp = temp->next; // Move To Next Node Only If It's Not A Duplicate
			}
		}
	}


	// Find Minimum Value In Linked List
	int minimum(Node* h) {

		if (h == nullptr)
			return 0;

		Node* temp = h;
		int minVal = h->data;
		while (temp != nullptr) {
			if (temp->data < minVal)
				minVal = temp->data;
			temp = temp->next;

		}


		return minVal;

	}

	void Min() {

		int m = minimum(head);

		cout << "The Minimum is : " << m << endl;

	}


	// Find Maximum Value In Linked List
	int maximum(Node* h) {

		if (h == nullptr)
			return 0;

		Node* temp = h;
		int maxVal = h->data;
		while (temp != nullptr) {
			if (temp->data > maxVal)
				maxVal = temp->data;
			temp = temp->next;

		}


		return maxVal;

	}

	void Max() {

		int m = maximum(head);

		cout << "The Maximum is : " << m << endl;

	}

	// Sum Of All Nodes In Linked List
	int sum(Node* h) {
		if (h == nullptr)
			return 0;

		Node* temp = h;
		int sumVal = 0;
		while (temp != nullptr) {
			sumVal += temp->data;
			temp = temp->next;
		}
		return sumVal;
	}
		void Sum() {
			int e = sum(head);

			cout << "Sum Of All Values : " <<e<< endl;
		}












};

int main()
{
	int c = 0;
	LinkedListSingle list;
	LinkedListSingle list2;

	list.InsertAtEnd(10);
	list.InsertAtEnd(20);
	list.InsertAtEnd(30);
	list.InsertAtEnd(40);
	list.InsertAtEnd(50);
	
	list.Replacer(30, 500);

	cout << "Original List: " << endl;
	list.Traverse();
		
	list.C(c);
	cout << endl;

	list.PR();

	list.Sort();
	cout << "Sorted List: " << endl;
	list.Traverse();

	cout << "============================================================";
	list2.InsertAtHead(40);
	list2.InsertAtHead(40);
	list2.InsertAtHead(40);

	list.Merge(list2);
	cout << endl;
	cout << "List 1 After Merge + Sort : " << endl;
	list.Sort();
	list.Traverse();
	list.Fmiddle();
	list.MS(&list , &list2);
	list.Min();
	list.Max();
	list.Sum();
	
	
	return 0;
}

