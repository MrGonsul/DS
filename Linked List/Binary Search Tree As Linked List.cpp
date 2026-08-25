#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// Mastered By Mr.Gonsul


// Lecture Linked List [ Tree ] 

 // Binary Tree   
struct BTree {
    int key; // Data == KEY
    BTree* left; // LEFT == Prev
    BTree* right; // Right == Next
    int count = 1;

    BTree(int val , int i) {
        key = val;
        left = nullptr;
        right = nullptr;
        count = i;

    }
};


// Binary Search = left < VALUE > right
class BSTree {

private:
    vector <int> parents; // OR Vector <Node*> Withe For Each Node* x : parents
    vector <int> childs;  // OR Vector <Node*> Withe For Each Node* x : childs
    BTree* root;
    void insert(BTree* parent, int val) {

        if (val < parent->key) {

            if (parent->left == nullptr)
                parent->left = new BTree(val, 1);
            else
                insert(parent->left, val);

        }
        else if (val > parent->key) {

            if (parent->right == nullptr)
                parent->right = new BTree(val, 1);
            else
                insert(parent->right, val);

        }
        else {
            // duplicate case
            parent->count++;
        }
    }
    void clear(BTree* node) {

        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // Traversal
    // 1 - In Order ==> Print [ Left ] Then [ Root ] Then Print [ Right ]

    void InOrder(BTree* node) {

        // return early if node is null to avoid dereferencing a null pointer
        if (node != nullptr)
        {

            InOrder(node->left);
            cout << node->key << " "; // Print Root
            InOrder(node->right);
        }
    }

    // 2 - Pre Order ==> Print [ Root ] Then [ Left ] Then Print [ Right ]
    void PreOrder(BTree* node) {
        if (node != nullptr)
        {
            cout << node->key << " "; //  Print Root
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }
    // 3 - Post Order ==> Print [ Right ] Then [ Root ] Then Print [ Left ]
    void PostOrder(BTree* node) {
        if (node != nullptr)
        {
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->key << " "; // Print Root
        }
    }

    // Find Max [Right]
    int FindMax(BTree* node) {
        if (node == nullptr)
            throw runtime_error("Tree is empty");
        if (node->right == nullptr)
            return node->key;

        return FindMax(node->right);
        // Another Plan
        //BTree* temp = root;
        //while (temp->right != nullptr)
        //    temp = temp->right;
        //return temp->key;


    }
    // Find Min [Left]
    int FindMin(BTree* node) {
        if (node == nullptr)
            throw runtime_error("Tree is empty");
        if (node->left == nullptr)
            return node->key;

        return FindMin(node->left);

        // Another Plan
        //BTree* temp = root;
        //while (temp->left != nullptr)
        //    temp = temp->left;
        //return temp->key;

    }
    BTree* min(BTree* node) {
        // return the pointer to the minimum node in this subtree
        while (node != nullptr && node->left != nullptr)
            node = node->left;
        return node;

        // Another Plan
        //BTree* temp = root;
        //while (temp->left != nullptr)
        //    temp = temp->left;
        //return temp->key;

    }

    BTree* Find(BTree* node, int val) {

        if (node == nullptr)
            return nullptr;
        if (node->key == val)
            return node;
        if (val < node->key)
            return (Find(node->left, val));
        else
            return (Find(node->right, val));

    }

    BTree* replacer(BTree* node, int val , int newData) {

        if (node == nullptr)
            return nullptr;
        if (node->key == val) {
            node->key = newData;
            return node;
        }
        if (val < node->key)
            return (replacer(node->left, val , newData));
        else
            return (replacer(node->right, val , newData));

    }

    BTree* Deletion(BTree* node, int key) {

        if (node == nullptr)
            return nullptr;

        if (key < node->key)
            node->left = Deletion(node->left, key);
        else if (key > node->key)
            node->right = Deletion(node->right, key);
        else
        {
            // No Children
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // One Children  [ right or  left ]

            // 1 - left

            if (node->left == nullptr) {
                BTree* temp = node->right;
                delete node;
                return temp;
            }

            // 2 - right

            if (node->right == nullptr) {
                BTree* temp = node->left;
                delete node;
                return temp;
            }

            // What if The Parent have Two Children

            if (node->left != nullptr && node->right != nullptr) {

                BTree* temp = min(node->right);
                // copy successor's key and delete successor
                if (temp != nullptr) {
                    node->key = temp->key;
                    node->right = Deletion(node->right, temp->key);
                }

            }

        }
        return node;
    }

    // childe == leaf 
    // Recursive function to collect parent nodes
    void getChilde(BTree* root) {
        if (root == nullptr)
            return;

        // collect children
        if (root->left == nullptr && root->right == nullptr) {
            childs.push_back(root->key);
        }

        // recursion
        getChilde(root->left);
        getChilde(root->right);
    }

    // Print vector
    void printChildes() {
        for (int x : childs)
            cout << x << " ";
        cout << endl;
    }

    // Recursive function to collect parent nodes
    void getParents(BTree* root) {
        if (root == nullptr)
            return;

        // if the Parent have one or two children
        if (root->left != nullptr || root->right != nullptr) {
            parents.push_back(root->key);
        }

        // recursion
        getParents(root->left);
        getParents(root->right);
    }

    // Counter Odd Even
    void CountEvenOdd(BTree* root, int& even, int& odd)
    {
        if (root == nullptr)
            return;

        if (root->key % 2 == 0)
            even++;
        else
            odd++;

        CountEvenOdd(root->left, even, odd);
        CountEvenOdd(root->right, even, odd);
    }


    // Print vector
    void printParents() {
        for (int x : parents)
            cout << x << " ";
        cout << endl;
    }

    set<int> seen;

    BTree* removeDuplicates(BTree* root) {
     
        if (root == nullptr)
            return nullptr;

        root->left = removeDuplicates(root->left);
        root->right = removeDuplicates(root->right);

        if (seen.find(root->key) != seen.end()) {
            delete root;
            return nullptr;
        }

        seen.insert(root->key);
        return root;
    }

public:
    BSTree() {
        root = nullptr;
    }
    ~BSTree() {
        clear(root);

    }


    // Methods

    void insert(int val)
    {
        if (root == nullptr) {
           
            root = new BTree(val ,1);
            return;
        }
        insert(root, val);
    }

    void Inorder() {
        InOrder(root);
    }

    void Preorder() {
        PreOrder(root);
    }
    void Postorder() {
        PostOrder(root);
    }
    int findMax() {
        return FindMax(root);
    }
    int findMin() {
        return FindMin(root);
    }
    bool Find(int val) {
        return Find(root, val);

    }

    void Delete(int key) {
        Deletion(root, key);
    }

    void ShowLeaf() {
        getChilde(root);
        printChildes();
    }
    void ShowParent() {
        getParents(root);
        printParents();

    }
    void replace(int val, int target) {
        replacer(root, val, target);

    }
    void Count_ODD_Even() {
        int odd = 0;
        int even = 0;
        CountEvenOdd(root,even,odd);
        
        
        cout << "Odd : "<< odd << endl;
        cout << "Even : " << even << endl;
    }

    // Find Balanced Final Quesion
    void FM(vector<int> &Tree , BTree* &n) {

       sort(Tree.begin(), Tree.end());
       // Sorted
       int mid = Tree.size()/ 2;

       insert(Tree[mid]); // Root Balanced 
       for (int out : Tree)
       {    
           insert(out);

       }    
       // Print Just For Showing
       PreOrder(root);

    }
    void ff(vector<int> &value)
    {
        FM(value, root);
        
        
    }

};




































int main()
{
    BSTree b1;
   // b1.insert(50);
   // b1.insert(80);
   // b1.insert(40);
   // b1.insert(10);
   // b1.insert(10);
   // b1.insert(10);
   // b1.insert(1);
   // b1.insert(20);
   // b1.insert(70);
   // b1.replace(1, 100);
   // vector<int> temp{ 1,5,4,2,6,8 };
   // b1.ff(temp);

    

 
  
   
    //cout << "Leaf : " << endl;
    //b1.ShowLeaf();
    //cout << "Parent : " << endl;
    //b1.ShowParent();
    //b1.Count_ODD_Even();

	return 0;
}