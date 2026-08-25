#include <iostream>
using namespace std;

// ================== Generic Stack Class ==================
template <class T>
class stack {

private:
    // ---------- Node Structure ----------
    struct node {
        T item;        // Data stored in the node
        node* next;    // Pointer to the next node
    };

    node* top;        // Points to the top element of the stack
    node* current;    // Used for traversal (display)

public:
    // ---------- Constructor ----------
    stack() {
        top = NULL;    // Stack starts empty
    }

    // ---------- Check if Stack is Empty ----------
    bool isEmpty() {
        return top == NULL;
    }

    // ---------- Push Operation ----------
    void push(T Element) {
        node* ElementPtr = new node;  // Create new node

        // If memory allocation fails
        if (ElementPtr == NULL) {
            cout << "Stack Push Cannot Allocate Memory..." << endl;
            return;
        }

        ElementPtr->item = Element;   // Store value in node
        ElementPtr->next = top;       // New node points to old top
        top = ElementPtr;             // Top moves to new node
    }

    // ---------- Pop (without return value) ----------
    void pop() {
        if (isEmpty()) {              // Check if stack is empty
            cout << "Stack Empty ON POP!" << endl;
            return;
        }

        node* temp = top;             // Save top node
        top = top->next;              // Move top to next node
        delete temp;                  // Delete old top
    }

    // ---------- Pop (with returned top value) ----------
    void pop(T &stackTop) {
        if (isEmpty()) {
            cout << "Stack Empty ON POP!" << endl;
            return;
        }

        stackTop = top->item;         // Save top value
        node* temp = top;             // Save top node
        top = top->next;              // Move top pointer
        delete temp;                  // Delete node
    }

    // ---------- Get Top Element ----------
    void getTop(T &stackTop) {
        if (isEmpty()) {
            cout << "Stack Empty on getTop" << endl;
            return;
        }

        stackTop = top->item;         // Return top value only
    }

    // ---------- Display Stack Elements ----------
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        current = top;                // Start from top
        cout << "Show All items in Linked Stack: ";
        cout << "[ ";

        // Traverse the linked list
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }

        cout << "]" << endl;
    }
};

// ================== Main Function ==================
int main() {

    stack<int> obj;   // Create stack of integers

    // Push elements into stack
    obj.push(5);
    obj.push(53);
    obj.push(537);
    obj.push(883);
    obj.push(43);
    obj.push(33);
    obj.push(33);

    // Display stack
    obj.display();

    return 0;
}
