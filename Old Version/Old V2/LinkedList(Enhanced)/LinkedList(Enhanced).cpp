#include <iostream>
using namespace std;

/* ================= NODE ================= */

struct node {
public :
int data; // Create Data
node*next; // Create Pointer
node(){ // Constructor But Without Paramitter
    data=0; // init Data is 0
    next=NULL; // init Pointer Is Null {empty}
    }

node(int val){ // Constructor But With Paramitter
    data=val; // init Data is Data From Paramitter
    next=NULL; // init Pointer Is Null {empty}
    }

};

/* ================= LINKED LIST ================= */

class LinkedList {

private :
    node*head; // Create Node For Head As Main Linked List [ Leader ]
public:
    LinkedList(){
    head=NULL; // When We Creating Linked List The Leader Pointer Must Be NULL !!!
    }

    // Operaitor Cheaking If The List Is Empty Or Not  !
    bool isEmpty() {
        return (head == NULL); // true ·Ê head ·« Ì‘Ì— ·√Ì ‰Êœ
    }



    /* ================= Method In LINKED LIST ================= */


    // Insert

    //1- Insert IN First
    void InsertFirst(int val){
        node*newNode = new node (val); // Creation Node As Object As Reference And Give it Value To Data !
        newNode->next=head; // Connecting newNode To Head As First Node
        head=newNode; // Update Nodes The Head Pointer Is Now With NewNode !!!
        return; // close
    }


    //2- Last Insert
    void InsertLast (int val){

    // If The Value is Empty Creating AS First Node by Using First Insert Method !
    if(isEmpty()){
        InsertFirst(val);
        cout<<"This LINKED LIST IS Empty So WE Creating As First Linked List..."<<endl;
        return;
    }
    else{ // If isnt Empty Then Create Node And Connect Between Last(using loop With Temp) and before Node pointer
            node*newNode = new node(val);
            node*Temp=head; // Pointer So We Can Control it As it Leader

            // While Loop  To  Get Last Place
            while(Temp->next!=NULL){ // This Brach is Talking About Going To All Node Pointer Not All NODE DATA AND POINTER !!!!!

                Temp=Temp->next; // like i++
            }
            // Now We In Last Node
            Temp->next=newNode; //Connecting Last Node To Head !!! Still The newnode is Null
    }
    }
    //3- Insert At position  And  New Item  To insert it
        void InsertAt(int pos , int newer){
            // if The Linked List Is Empty
            if(isEmpty()){
                InsertFirst(newer);
                return;}
            if(pos<0){
              cout<<"Invalid Position..."<<endl;
              return;
            }

            // If Its Not Empty AND IN Right Position
            node*Temp=head; // Pointer Leader
            int i=0;
            while(i<pos-1 && Temp!=NULL){ // If The Position you Choose it it will add before you choose it and not in Null
                Temp=Temp->next;
                i++;
            }
             if (Temp == NULL) {              // Out OF Range
            cout << "Position out of range\n";
            return;
        }
        node*newNode = new node (newer); // Create object Node
        newNode->next=Temp->next; // Connect newNode Pointer To Another Node Pointer
        Temp->next=newNode;  // // Connect newNode Pointer To Head=Temp  Pointer
        return;
    }

    //4-Insert After Method
    void InsertAfter(int target , int val){
    if(isEmpty()){
        cout<<"List Is Empty"<<endl;
        return;
    }
    if(head->data==target){ // If the user Select The Header
        InsertFirst(val);
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        if(temp->data == target){ // If the Data And Before Pointer == Target Data Do Create Node
        node*newNode = new node(val); // create Node
        newNode->next=temp->next; // Connect New node to previous next node
        temp->next=newNode; // Connect head=Temp to New Node  --> update Node
        return;
    }
    temp=temp->next; // I++
    }
    cout << "Target Value is Not found... " <<endl;
    }


    //5-Insert Before
    void InsertBefore(int target , int val){
    if(isEmpty()){
        cout<<"List Is Empty"<<endl;
        return;
    }
    if(head->data==target){ // If the user Select The Header
        InsertFirst(val);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        if(temp->next->data == target){ // If the Data And Before Pointer == Target Data Do Create Node
        node*newNode = new node(val); // create Node
        newNode->next=temp->next; // Connect New node to previous next node
        temp->next=newNode; // Connect head=Temp to New Node  --> update Node
        return;
    }
    temp=temp->next; // I++
    }
    cout << "Target Value is Not found... " <<endl;
    }


        // Display Method
        void Display(){

        node*temp=head;
        while(temp!=NULL){
            cout << temp->data << " ";
            if(temp->next!=NULL)
               cout << " -> ";
            temp=temp->next;

        }
        cout<<endl;
        }

        // Replace Method
        void Replacer (int target , int newdata){
        if(isEmpty()){
        cout<<"List Is Empty"<<endl;
        return;
        }
        node*temp=head;
        while(temp!=NULL){
            if(temp->data ==target){
                temp->data=newdata;
                return;
            }
            temp=temp->next;

        }
        cout << "Target Value is Not found... " <<endl;


        }

        // Delete First
        void deleteFirst() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }

        node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete Last
    void deleteLast() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        node* temp = head;
        node* pre = NULL;


        while (temp->next != NULL) {
            pre = temp;
            temp = temp->next;
        }

        delete temp;
        pre->next = NULL;
    }
    // Delete At

    void DeleteAt(int pos){

    if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
         if(pos<0){
              cout<<"Invalid Position..."<<endl;
              return;
            }

            // If Its Not Empty AND IN Right Position
            node*Temp=head; // Pointer Leader
            node*pre=NULL;
            int i=0;
            while(i<pos && Temp!=NULL){ // If The Position you Choose to delete it it will you choose it and not in Null same pos target
                pre=Temp;
                Temp=Temp->next;
                i++;

            }

             if (Temp == NULL) {              // Out OF Range
            cout << "Position out of range\n";
            return;
        }
        // time to delete
        pre->next=Temp->next;
        delete Temp;






    }



    // Search Method
    void Search(int item){
    bool Found=false;
    node*temp=head;
    while(temp!=NULL){
        if(temp->data ==item){
            cout<<"Your Item Is Found !"<<endl;
            return;}
            temp=temp->next;
    }

    if(!Found){
        cout<<"Your Item Is Not Found !"<<endl;
        return;
    }


    }











};









int main()
{

    LinkedList list;
    int choice, val, target, pos;

    do {
        system("CLS"); // „”Õ «·‘«‘… ﬁ»· ⁄—÷ «·„Ì‰ÌÊ
        cout << "======= LINKED LIST MENU =======\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At Position\n";
        cout << "4. Insert After\n";
        cout << "5. Insert Before\n";
        cout << "6. Delete First\n";
        cout << "7. Delete Last\n";
        cout << "8. Display List\n";
        cout << "9. Replace\n";
        cout << "10.Search\n";
        cout << "11.Delete At\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        system("CLS"); // „”Õ «·‘«‘… »⁄œ «Œ Ì«— «·⁄„·Ì…

        switch(choice) {
            case 1:
                cout << "Enter value to insert at first: ";
                cin >> val;
                list.InsertFirst(val);
                break;

            case 2:
                cout << "Enter value to insert at last: ";
                cin >> val;
                list.InsertLast(val);
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;
                list.InsertAt(pos, val);
                break;

            case 4:
                cout << "Enter target value to insert after: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.InsertAfter(target, val);
                break;

            case 5:
                cout << "Enter target value to insert before: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.InsertBefore(target, val);
                break;

            case 6:
                list.deleteFirst();
                break;

            case 7:
                list.deleteLast();
                break;

            case 8:
                cout << "Current Linked List: \n";
                list.Display();
                break;

            case 9:
                cout << "Enter target value to replace: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.Replacer(target, val);
                break;

            case 10:
                cout << "Enter value to search: ";
                cin >> val;
                list.Search(val);
                break;

            case 0:
                cout << "Exiting...\n";
                break;
           case 11:
                cout << "Enter position: ";
                cin >> pos;
                list.DeleteAt(pos);
                break;


            default:
                cout << "Invalid choice! Try again.\n";
        }

        if(choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore(); // · Ã«Â· '\n' «·„ »ﬁÌ…
            cin.get();    // «‰ Ÿ«— ÷€ÿ Enter
        }

    } while(choice != 0);

    return 0;
}
