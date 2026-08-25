#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//                          Linked List Mastered By Mr.Gonsul


class Node {
public:
    int data;
    Node* next;

    vector<int> grade; 

    Node(int val ) {
        data = val;
        next = nullptr;
     
    }

    Node(int val, vector<int> g) {
        data = val;
        next = nullptr;
        grade = g;
    }
};

class LinkedList {

private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    //---------------------------------------------------------------------------------------------------------------------------------------

        // Methods

        // Insert At Head  ->  O(1)
    void InsertAtHead(int val , vector<int> Grade) {

        Node* newNode = new Node(val , Grade);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;

        }
        else {

            newNode->next = head;
            head = newNode;
          //   tail = newNode;  // باصي لي صاحبك خليه يعرف ينظمها
        }
    }

    // Insert At Head  ->  O(1)
    void InsertAtH(int val) {

        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;

        }
        else {

            newNode->next = head;
            head = newNode;
            //   tail = newNode;  // باصي لي صاحبك خليه يعرف ينظمها
        }
    }

    //---------------------------------------------------------------------------------------------------------------------------------------

    void InsertAtTail(int val , vector<int> grade) {

        if (head == nullptr)
            InsertAtHead(val ,grade);
        else {
            Node* newNode = new Node(val,grade);

            tail->next = newNode;
            tail = newNode;

        }


    }
    //---------------------------------------------------------------------------------------------------------------------------------------

        // Reverse
        // Time complexly is O(n)
    void DisplayReverse() {

        Node* prev = nullptr;
        Node* next = nullptr;

        while (head != nullptr) {
            next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }


        head = prev;


    }
    //---------------------------------------------------------------------------------------------------------------------------------------

        // Display 
    void Display() {

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Nullptr" << endl;
    }


    //---------------------------------------------------------------------------------------------------------------------------------------

        // Merge
        // O(N * M + Log n)
    void Merge(LinkedList OtherLinkedList) {

        vector <int> num;

        Node* temp = head;

        while (temp != nullptr) {

            num.push_back(temp->data);
            temp = temp->next;

        }

        temp = OtherLinkedList.head;

        while (temp != nullptr) {

            num.push_back(temp->data);
            temp = temp->next;

        }

        // بعد ما عبيت توا ندير ترتيب ايزي
        sort(num.begin(), num.end());


        // Free Memory
        while (head != nullptr)
            DeleteHead();

        head = new Node(num.at(0));  // Or Just Use - 1 Called dummy Linked List

        Node* curr = head;
        for (int i = 1; i < num.size(); i++) {

            curr->next = new Node(num.at(i));
            curr = curr->next;

        }


    }





    //---------------------------------------------------------------------------------------------------------------------------------------

     // Delete At head
    void DeleteHead() {

        Node* temp = head;
        head = head->next;
        delete temp;

    }








    //---------------------------------------------------------------------------------------------------------------------------------------
       
   
    // O(m*n) Another Linked List Merge
    void Merge1(LinkedList& OtherLinked)
    {
        Node* curr = head;
        Node* currOther = OtherLinked.head;

        if (curr == nullptr) {
            head = currOther;
            return;
        }

        if (currOther == nullptr)
            return;

        Node* result = nullptr;

        if (curr->data <= currOther->data) {
            result = curr;
            curr = curr->next;
        }
        else {
            result = currOther;
            currOther = currOther->next;
        }

        Node* currResult = result;

        while (curr != nullptr && currOther != nullptr)
        {
            if (curr->data <= currOther->data)
            {
                currResult->next = curr;
                currResult = curr;

                curr = curr->next;
            }
            else
            {
                currResult->next = currOther;
                currResult = currOther;

                currOther = currOther->next;
            }
        }

        if (curr != nullptr)
            currResult->next = curr;

        if (currOther != nullptr)
            currResult->next = currOther;

        head = result;
        OtherLinked.head = nullptr;
    }






    //---------------------------------------------------------------------------------------------------------------------------------------

    // Sort
    void Sort(LinkedList l1) {

        Node* node = l1.head;
        if (node == nullptr) {
            return;
        }

        for (Node* temp = node; temp->next != nullptr; ) {

            if (temp->data > temp->next->data) {

                int get = temp->data;
                temp->data = temp->next->data;
                temp->next->data = get;

                temp = node; // نرجع للبداية
            }
            else {

                temp = temp->next;
            }

        }
    }


            



        



    void ss(LinkedList l1) {

        Sort(l1);

    }




    //---------------------------------------------------------------------------------------------------------------------------------------

    // Fibonatchi I Factoria
    
    int factorial(int n) {
        if (n == 0 || n == 1)
            return 1;

        return n * factorial(n - 1);
    }

    int Factorial(Node* root) {

        if (root == nullptr)
            return 1;

        return factorial(root->data) * Factorial(root->next);
    }



    //---------------------------------------------------------------------------------------------------------------------------------------

    Node* dupbop(Node*& node) {

        if (node == nullptr) return nullptr;

        Node* pre = node;
        Node* temp = node->next;

        while (temp != nullptr) {

            if (temp->data == pre->data) {
                Node* todelete = temp;
                pre->next = temp->next;
                temp = temp->next;
                delete todelete;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }

        return node;
    }


    void Rduplic() {

        dupbop(head);
    }

    //---------------------------------------------------------------------------------------------------------------------------------------


    void HBBO(LinkedList& l1) {

        Node* temp = l1.head;

        while (temp != nullptr) {

            int num = temp->data;
            int sum = 0;

            // جمع digits
            while (num > 0) {

                sum += num % 10;
                num /= 10;
            }

            l1.InsertAtH(sum);   

            
            temp = temp->next;
        }
        head->next = nullptr;
        delete tail;

        l1.Display();
    }


    //---------------------------------------------------------------------------------------------------------------------------------------

    // Fibonatichi  -->  123 = 1+2+3 O(n)
    void FBBO(LinkedList & l1){

        
        Node* temp = l1.head;
       
        
        
        
        while (temp->data > 0) {
            

           int div =  temp->data % 10;
           if(div !=0)
           InsertAtH(div);

            temp->data /= 10;
        }
      
        Node* TT = l1.head;
        while (TT->next != l1.tail) {


            TT=TT->next;
        }
        tail = TT;
        TT->next = nullptr;
        TT = TT->next;
        delete TT;

        l1.Display();
    }



    //---------------------------------------------------------------------------------------------------------------------------------------

     // Convert Node Into Vector
    void ConvertnTOv() {
        vector <Node*> node;

        Node* temp = head;
        while (temp != nullptr) {
            node.push_back(temp);
            temp = temp->next;
        }

        cout << endl;
        cout << "Now The Linked List Is Inserted InTo Vector And Size is = " << node.size()<<endl;
        ConvertVTOL(node);
    }




    //---------------------------------------------------------------------------------------------------------------------------------------

     // Convert Vector Into Vector
    void ConvertVTOL(vector<Node *> node) {
        

        Node* temp = tail;
        int i = node.size()-1;
        while (temp->next!= nullptr) {
            temp->next = node.at(i);
            i--;
            temp = temp->next;
        }

        cout << endl;
        cout << "Now The vector Is Inserted InTo LinkedList And Size is = " << node.size() << endl;
    }




    //---------------------------------------------------------------------------------------------------------------------------------------

    void ConvertVTOL2(vector<Node*> node) {

        if (node.empty()) return;

       
        for (int i = 0; i < node.size() - 1; i++) {
            node[i]->next = node[i + 1];
        }

        node[node.size() - 1]->next = nullptr; // Last Node

        head = node[0]; // head Node
        tail = node[node.size() - 1]; // Tail Node

        cout << "\nVector converted back to Linked List. Size = " << node.size() << endl;
    }

    //---------------------------------------------------------------------------------------------------------------------------------------

    // Calc The Grade
    void CalcGrade(LinkedList l1) {
        double divided = 4.0;  double avg;
        for (Node* i = l1.head; i != nullptr; i = i->next) {
            int sum = 0; 
            for (int j = 0; j < i->grade.size(); j++) {

                sum += i->grade[j];

               
            }
            avg = (double)sum / divided;
            cout << "Student Grade : " << avg << endl;
        }
    }




    //---------------------------------------------------------------------------------------------------------------------------------------


    //---------------------------------------------------------------------------------------------------------------------------------------






    //---------------------------------------------------------------------------------------------------------------------------------------





    //---------------------------------------------------------------------------------------------------------------------------------------

};





int main()
{

    LinkedList l1;
    // vector<int> gg1{ 100,100,100,100 };
    
    //l1.InsertAtHead(5 ,gg1);  // Taha
    l1.InsertAtH(565);
    
    //vector<int> gg2{ 44,25,30,40 };
    //l1.InsertAtHead(10,gg2); // Moayeed
    //
    //vector<int> gg3{ 12,24,21,65 };
    //l1.InsertAtHead(15,gg3); // Ali

    //l1.CalcGrade(l1);
    //l1.DisplayReverse();
    //l1.Rduplic();
    ////------------------------
    //LinkedList l2;
    //l2.InsertAtHead(1);
    //l2.InsertAtHead(1);
    //l2.InsertAtHead(2);
    //l2.InsertAtHead(3);
    //l2.InsertAtHead(3);
    //l2.ss(l2);
    l1.FBBO(l1);

    //l2.Display();
    //cout << l2.factorial(5);
    //l2.ConvertnTOv();
    //l2.Display();
    return 0;
}
