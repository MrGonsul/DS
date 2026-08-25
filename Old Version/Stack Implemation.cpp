#include <iostream>

// Or Use const int Sizer = 8;
#define Sizer 8
using namespace std;


// Struct Data Type [Stack] !
class stack {

// Switch Mode From Default (Package) To Private
private :
int Array[Sizer];
int top;

// Switch Mode From Default (Private) To Public
public :

// Constractor To init Object Stack Index To Begin
stack (){
top = -1;
}

// Method (Function In C++)

// Create 2 Important Tool  (IsFull,IsEmpty)
bool IsEmpty(){ return (top == -1); }
bool IsFull(){ return (top >= Sizer -1); }


// Add (Push)

void push (){
system("cls");
if(!IsFull()){
int E;
cout<<"Enter Number OF Value."<<endl;
cin >> E;

// Move Index From UnderGround To Ground (Zero)
top++;
Array[top] = E; // Or We Can Do This ==> Array[++top] = E ;  Simple Right !!!

  cout << "=============================================="<<endl;
  cout<< "Completed Operation..." <<endl;
  cout << "=============================================="<<endl;

}
else
cout<< "Sorry The Stack Is Empty..." <<endl;
}

// Remove (Pop) With Store OR Not (Both)  By Using Function Overloading ?!

// (1) With Store
void popS(){
    string E;
system("cls");

cout << "Would You Like To Store Value Before Remove it ? Y/N..." << endl;
cin >> E;
if(E=="Yes" || E=="Y" || E=="y" || E=="yes" ){

if (IsEmpty()){
    cout<< "Sorry The Stack Is Empty..." <<endl;
}
else{


cout << "=============================================="<<endl;
    cout << "Value Before Deleted Is = "<< Array[top] << endl;
    cout<< "Completed Operation..." <<endl;

cout << "=============================================="<<endl;
E=Array[top--];
}
}
else
    popR();
}

// (2) Just Remove It
void popR(){
system("cls");

if (IsEmpty()){
    cout<< "Sorry The Stack Is Empty..." <<endl;
}
else
--top;
cout << "=============================================="<<endl;

    cout<< "Completed Operation..." <<endl;
cout << "=============================================="<<endl;


}

// GetTop (Last Top)
void getTop(){
int GetTop;
system("cls");

if (IsEmpty()){
    cout<< "Sorry The Stack Is Empty..." <<endl;
}
else
GetTop=Array[top];
cout << "Get Top Value = " <<GetTop<<endl;
cout << "=============================================="<<endl;

    cout<< "Completed Operation..." <<endl;
cout << "=============================================="<<endl;


}

// Print (Traverse)

void Print () {

    system("cls");

    if (IsEmpty()){
        cout<< "Sorry The Stack Is Empty..." <<endl;
        return;
    }

    cout << "====== Stack ======" << endl;

    for(int i = top ; i >= 0 ; i-- ){
        cout << "|   " << Array[i] << "   |" << endl;
    }

    cout << "---------" << endl;

    cout << "=============================================="<<endl;
    cout<< "Completed Operation..." <<endl;
    cout << "=============================================="<<endl;
}

// Exit
void exitor (){system("cls"); cout<<"Good Bye..."<<endl; }
};



int main()
{
     // Definiton
     stack Admin;
     int Choose;
     while (true){

cout << "======================================================="<<endl;
cout << "============== Welcome To System ======================"<<endl;
cout << "============== Stack Implemetion ======================"<<endl;
cout << "======================================================="<<endl;
cout << "1 - Add Value [PUSH]."<<endl;
cout << "2 - Remove Value [POP]."<<endl;
cout << "3 - Show All Value [SHOW]."<<endl;
cout << "4 - Show Top Value [GetTop]."<<endl;
cout << "5 - Exit."<<endl;
cout << "=============================================="<<endl;
cout << "Choose Between 1 ~ 5 ...."<<endl;
cout << "=============================================="<<endl;
cin >> Choose;
         switch(Choose){

         case 1 : Admin.push();   break;
         case 2 : Admin.popS();   break;
         case 3 : Admin.Print();  break;
         case 4 : Admin.getTop(); break;
         case 5 : Admin.exitor(); break;
         default : cout<<"Try Again..."<<endl;

         }
     }

    return 0;
}


