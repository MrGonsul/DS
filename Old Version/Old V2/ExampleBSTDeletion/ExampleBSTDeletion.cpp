#include <iostream>

using namespace std;

class Node {

public:
       int data;
       Node*left;
       Node*right;

       Node(int val){
       data = val;
       left = right = nullptr;

       }

};

class BST{
private:
Node*root;
public:
            BST(){
            root = nullptr;
            }
            Node*findMin(Node*node){
            while(node&&node->left!=nullptr)
                node = node->left;
            return node;

            }

            Node*DeleteNode(Node*node , int key){

            if(node == nullptr)
            return nullptr;

            // Search + Store Return All Node

            if(key < node->data)
            node->left = DeleteNode(node->left , key);

            else
            if(key > node->data)
            node->right = DeleteNode(node->right , key);

            else{
                // parent dosent have children
               if(node->left == nullptr && node->right == nullptr){
                delete node;
                return NULL;


               }
               else
               if(node->left == nullptr){
                Node*temp = node->right;
                delete node;
                return temp;



               }
               else
               if(node->right == nullptr){
                 Node*temp = node->left;
                delete node;
                return temp;

               }
               else{
                Node*temp = findMin(node->right);
                node->data = temp->data;
                node->right = DeleteNode(node->right,temp->data);

               }
                return node;




            }









            }











};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
