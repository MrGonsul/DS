#include <iostream> // Lecture ---> Stack Implemetation !!!

using namespace std;
const int MAX_SIZE = 6; // The Maximum Index Or Size Can be handle The Array Stack!
template <class T>  // T is ANY Name + Genetric Yes!@!
class stack{
int top; // Initalization Top Index As First item Can Be Added !
T item[MAX_SIZE]; // Create Stack Array    in Genetric Use  --> T item[MAX_SIZE];

public :
    stack(){ //  Create First Method
    top=-1;  // Start Stack  -- Point As First Index !
    }

// Create Second Method :: Used to add the Element Into Stack!
    void push(int Element){
    if(top>=MAX_SIZE-1){
        cout<<" The Stack Is Full "<<endl;
        cout<<" The Last Item ("<<Element<< ") Will not be Added..."<< endl;
         cout<<endl;
        }else{
    top++;
    item[top]=Element;
    }}
    bool isEmpty() // Method Used to Check the Stack if Its Empty or Not !
    { // You Can Use " return top <0 ; " it will be work !
        if(top==-1) // is Empty ???
            return true;  // Yes
        else
            return false; // NO
    }
// Create Third Method :: Used to remove the Element !  -- Note That In MicroComputer The Pop used to delete item in Stack and add to any Variable outside Stack like (Mov With copy)
    // Pop Delete   --- OverLoading !!!

    // Pop Return Item  -- Like MicroComputer !
    T pop(){ // Call By Reference + Still OverLoading !!! ==> Any Array Stack In Genetric Dont Use any DataType Just Use Name Of Templete (T) ---> void pop(T &Element)
    if(top==-1)
    cout<<"Sorry The Stack Is Empty"<<endl;
    else{
    return item[top--];
    }}
    void getTop(int &StackTop){ // Call By Reference + Still OverLoading !!! ==> Any Array Stack In Genetric Dont Use any DataType Just Use Name Of Templete (T) --->  void getTop(T &StackTop)
    if(isEmpty())
    cout<<"The Stack Is Empty"<<endl;
    else
    StackTop = item[top];

    }
    void print (){ // Method Used To Print All Items !
    cout<<"Show All items in Stack"<<endl;
     cout<<"[";
    for(int i =top; i >=0; i--)
    cout<< item[i]<< " ";
    cout<<"]";
    }







};

// After Complete Create And init Stack Class !
int main()
{
    stack<int> obj; // Create an Object To use the Method! ++>>  stack<Any DataType> obj;  --> if You Using Template (Genetric Class(Array Object))
obj.push(5); // <------- The First Item In Stack
obj.push(53);
obj.push(537);
obj.push(883);
obj.push(43);
obj.push(33);
obj.push(33); // <------ The Last In Stack + Won Be Added Bc Out Of Range To Be Handle !
int pop;
pop=obj.pop();
cout<<"POP Value = " <<pop<<endl;
obj.print();



















































    return 0;
}
