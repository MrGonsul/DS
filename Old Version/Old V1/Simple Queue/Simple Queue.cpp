#include <iostream>

using namespace std;

class Queue{

// Create Variable
int Rear;
int Front;
int Size;
int *arr;
int sArray;
public :
Queue(int val){  // Constructor !!
Rear=Front=-1;
sArray=val;
Size=0;
arr=new int [val];
}


// Methods

void Enqueue(int item){ // Add

if(Rear!=sArray-1){
  if(Front == -1 && Rear == -1 && Front<= Rear ){ // Empty
    Rear ++;
    Front ++;
    arr[Rear]=item; // Or arr[++Rear]=item; So the Upper Rear Can Cancel it

  }
  else{
    arr[++Rear]=item;  // if Not Full But there have Item !
  }


}
else{
    cout<<"The Queue Is Full..."<<endl;
    return;
}


}
void Dequeue(){

if (Front != -1 && Rear != -1 && Front <= Rear ) { // All Expantion
    Front ++;

}
else cout << "Queue Is Empty..." <<endl;

}
int getFront () {
if (Front != -1 && Rear != -1 && Front <= Rear ) { // All Expantion
   return arr[Front];

}

int getRear () {
if (Front != -1 && Rear != -1 && Front <= Rear ) { // All Expantion
   return arr[Rear];

}
else {cout << "Queue Is Empty..." <<endl;
}
}
void display ( ){
if (Front != -1 && Rear != -1 && Front <= Rear ) { // All Expantion
    for (int i=Front; i<=Rear ; i++){
        cout<<arr[i]<< " ";
    }
cout<<endl;
}
else cout << "Queue Is Empty..." <<endl;


}




};













int main()
{
    Queue Q(10);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.display();
    cout<<"==========="<<endl;
    Q.Dequeue();
    Q.display();




    return 0;
}
