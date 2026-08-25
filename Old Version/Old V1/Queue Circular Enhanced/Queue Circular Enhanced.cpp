#include <iostream>
 //(linked List)
using namespace std;

class node{
public :
int data;
node*next;

    node(){
    data = 0;
    next = NULL;
    }
    node(int val){
    data = val;
    next = NULL;
    }

};

class Circular {
private :
   node*front;
   node*rear;

public :
    Circular(int val){ // size node like array
  front = rear = new node (val);

    }




    // Method

    bool isEmpty (){
    return (front == NULL);
    }

    void Enqueue (int val){
        if(rear != NULL){
        node*newNode = new node (val); // create new node
        rear->next=newNode;
        rear=newNode;
        }
        if(front == NULL) {
                front=rear;


        }
    }

    void Dequeue (){
        if(front == NULL)
            cout<< "The Queue Is Empty..." <<endl;
        node*temp=front;
        front =front->next;
        delete temp;

        if(front == NULL)
            rear=NULL;

    }

    int getFront (){
        return(front->data);

    }
    int getRear (){
        return(rear->data);
    }

    void Display (){
        node*temp=front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
              temp= temp->next;
        }




    }


};





int main()
{
Circular q(2);
q.Enqueue(23);
q.Enqueue(24);
q.Enqueue(25);
q.Display();
cout << "=======" <<endl;
q.Dequeue();
 q.Display();

    return 0;
}
