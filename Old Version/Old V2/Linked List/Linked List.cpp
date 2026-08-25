#include <iostream>
using namespace std;
//template<class T>

class node{
public :
int data;
node*next;
};
class LinkedList{
public :
node*head;
LinkedList(){
head=NULL;
}
bool IsEmpty(){return (head==NULL);}

// Insert Method :-
void FirstInsert(int item){
    //Yes ->  Create new Node And Put In First node  Connected To Head !!
    //No  ->  Create New Node And Connected To Head Node And Old Node  !!!
    if(IsEmpty()){
node*newNode=new node();
newNode->data=item;  // One For Data Init
newNode->next=NULL; // Two For Next (Pointer) Init
head=newNode; // Point Header To New Node
    }
    else{
      node*newNode=new node();
        newNode->data=item;
        newNode->next=head;
        head=newNode;
    }

}
// Searching Found Method

bool isFound(int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}


void LastInsert(int item){
if(IsEmpty()){
    FirstInsert(item);
    return;
}

else{
    node*temp=head; // Now The Temp Have Same Data ANd Next As The Head Have...

    while(temp->next!=NULL){
        temp=temp->next;
    }
    // Create New Node   + Master IN Here IS Temp Not Head
    node*newNode=new node();

    // init Node
    newNode->data=item;
    temp->next=newNode; // Node That BeFore Item  That nextPtr Connect To New Node !!!
    newNode->next=NULL; // New Node Just Need To Add NULL Bc We In Last ... you Know That !--!
}
}
void InsertBefore(int oldItem, int newItem){
    if(!isFound(oldItem)){
        cout<<"Item Not Found"<<endl;
        return;
    }

    node* newNode = new node();
    newNode->data = newItem;

    // áæ ÇáÚäÕÑ Ýí ÇáÑÃÓ
    if(head->data == oldItem){
        newNode->next = head;
        head = newNode;
        return;
    }

    node* temp = head;
    while(temp->next->data != oldItem){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


// Replace Method

void Replacer(int Old, int Newer){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == Old){
            temp->data = Newer;
            return;
        }
        temp = temp->next;
    }
    cout<<"Item Not Found"<<endl;
}


// Delete Method
  void Delete(int Old){
    if(IsEmpty()){
        cout<<"List Is Empty"<<endl;
        return;
    }

    // ÍÐÝ ÇáÑÃÓ
    if(head->data == Old){
        node* delptr = head;
        head = head->next;
        delete delptr;
        return;
    }

    node* pre = head;
    node* cur = head->next;

    while(cur != NULL && cur->data != Old){
        pre = cur;
        cur = cur->next;
    }

    if(cur == NULL){
        cout<<"Item Not Found"<<endl;
        return;
    }

    pre->next = cur->next;
    delete cur;
}


// Display

void display(){
node * temp = head;
cout<<" Linked List : "<<endl;
cout<<"[" << " ";
while (temp!= NULL) {

    cout<< temp->data << " " ;
    temp= temp -> next;
}
cout<<"]" << " ";


}

int Counter(){
node * temp = head;
int Count=0;

cout<<"[" << " ";
while (temp->next != NULL) {

    Count++;
    temp= temp -> next;
}
return Count ;


}








};



int main()
{
LinkedList Admin;

while (true){
    cout << "===============================================" <<endl;
    cout << "Linked List Mod Menu" <<endl;
    cout << "===============================================" <<endl;
    cout << "1-Insert Linked List" <<endl;
    cout << "2-Display Linked List" <<endl;
    cout << "3-Search What If is Here Or Not In Linked List" <<endl;
    cout << "4-Counter Linked List" <<endl;
    cout << "5-Replace Linked List" <<endl;
    cout << "6-Delete Linked List" <<endl;
    cout << "7-Exit The Program" <<endl;
    cout << "Choose Between 1~7" <<endl;
    cout << "===============================================" <<endl;

int sw;
    cin>>sw;
    switch (sw){
    case 1 : {cout<<"Enter Your Number What Do You Need To Select ! "<<endl;

    cout << "1-First Insert Linked List" <<endl;
    cout << "2-Before Insert Linked List" <<endl;
    cout << "3-Last Insert List" <<endl;
    int c,Re;
    cin>>c;
    switch(c){
    case 1 : {
                int x;
            cout<<"Enter Your Number : "<<endl;

             cin>>x;


            Admin.FirstInsert(x);
            break;}
        case 2 : {
      int x,y;
            cout<<"Enter Your Old Number :"<<endl;
            cin>>y;

            cout<<"Enter Your New Number : "<<endl;
            cin>>x;

               Admin.InsertBefore(y,x);
        break;
        }
        case 3 : {
      int x;
            cout<<"Enter Your Number :"<<endl;
                   cin>>x;
            Admin.LastInsert(x);



            break;}
            default : cout<<"Error...Return"<<endl;  break;
        }





        }
        case 2 : { Admin.display(); break;}
        case 3 : {
        int x;
            cout<<"Enter Your Number :"<<endl;
                   cin>>x;
                   if(Admin.isFound(x))
                    cout<<"Yes There Is Here"<<endl;
                   else
                        cout<<"No There Isnt Here"<<endl;



        break;}
        case 4 : {int x,counterx;
            cout<<"Enter Your Number : "<<endl;
                   cin>>x;
                   counterx=Admin.Counter();
                   cout<<"Counter The Linked List = "<< counterx <<endl;

                   break;}
        case 5 : {

            int x,y;
            cout<<"Enter Your Old Number :"<<endl;
            cin>>y;

            cout<<"Enter Your New Number :"<<endl;
            cin>>x;

            Admin.Replacer(y,x);





            break;}
        case 6 : {   int x;
            cout<<"Enter Your Number"<<endl;

             cin>>x;

            Admin.Delete(x);










            break;}
        case 7 : {cout<<"See You Later -_- ..."<<endl; break;}
        default : {cout<<"Error Selection"<<endl;}


        }
    }





        return 0;
    }
