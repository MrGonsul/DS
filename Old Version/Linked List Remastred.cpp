#include <iostream>

using namespace std;

// Create Node
class Node {

public :
    int data;
    Node*next;

    // If Data is Null
    Node(){
    data = 0;
    next = NULL;

    }
    // If Data Have Value
    Node(int val){
    data = val;
    next = NULL;
    }

};

class LinkedList {
 private :
     Node*head; // Head NOT USING FOR ANY FUNCTION
 public :
    LinkedList(){        // Create Object Without value
    head = new Node();
    }
    LinkedList(int val){ // Create Object With value
    head = new Node(val);
    }

    // Method

    // Insert AT Head
    void InsertATHead(int val){

    // Create Object Node = Head By Default
    Node *newNode = new Node(val);
    newNode -> next = head; // Create Connection Between NewNode Next TO - > Head So We Can Transfer
    head = newNode; // newNode NOW IS Head !!!
    }

    // Traversal (Print)
    void Traversal (){

        if (head == NULL)
        throw runtime_error("Linked List Is Empty...");

    Node *temp = head; // Create Node Temp As Printer

    while (temp != NULL ){ //temp->next = Go Until Last Next Node !!!!!! Not NODE SELF
                           // temp = Go Until TEMP IS NULL NOT NEXT TEMP!!!!!!!!!!
            cout << temp->data;
            if(temp->next != NULL)
                cout << " -> ";

                   // i++
              temp = temp->next;
    }

    cout << endl;
    }

    // INSERT AT TAIL (LAST)
    void InsertATTail (int val){


    if ( head == NULL )
        InsertATHead(val);
    else
    {
        Node *temp = head;

        while (temp->next!= NULL){ // Last Node Connection
            temp = temp->next;
        }

        Node *newNode = new Node (val);
        temp->next = newNode;

    }


    }

    // Insert AT Index
    void InsertATIndex (int idx , int val){
    // i or idx = index

    if (idx == 0)
        InsertATHead(val);
     Node *temp = head;
     for (int i = 0; i <idx-1; i ++)
        temp  = temp->next;

     // Create New Node And Connect previos Location -> next
     Node *newNode = new Node (val);
     newNode->next = temp->next; // NEW NODE NEXT CONNECT  TO TEMP NEXT
     temp->next = newNode; // TEMP SELF NEXT CONNECT  NEWNODE

    }




};




int main()
{









    return 0;
}
