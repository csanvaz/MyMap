// mymap.h
// Header assists in creating a map function that uses a threaded BST. This header file
// is also self-balancing via a Seesaw-Balanced property. 
// 
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //Helper function called in the clear() function. 
    //It traverses through threaded BST to clear the node
    //Threading is taken into account
    void clearHelper(struct NODE* node) {
        if (node != nullptr) {
            clearHelper(node->left);
            node->left = nullptr;   
            if (node->isThreaded == false) {
                clearHelper(node->right);
            }
            node->right = nullptr;
            delete node;
        }
    }

   
    //Function is used in the copy and equal operator function to properly copy map
    //while addressing threading. 
    NODE* thread_CopyHelper(NODE* node) {
        if (node == nullptr) {
	        return nullptr;
        }

        if (node->left == nullptr && node->right == nullptr) {
	        return node;
        }

        if (node->left != nullptr) {
            NODE* left = thread_CopyHelper(node->left);
            left->right = node; left->isThreaded = true;
        }

        if (node->right == nullptr) {
	        return node;
        }

        return thread_CopyHelper(node->right);
    }

    //Helper funnction that is called in the operator= function
    //This function helps copy the other's nodes variables to the
    //current node
    void copy_Helper(struct NODE** node, struct NODE* other) {
        if (other != nullptr) {
            (*node) = new struct NODE;
            (*node)->key = other->key;
            (*node)->value = other->value;
            (*node)->isThreaded = other->isThreaded;
            (*node)->nL = other->nL;
            (*node)->nR = other->nR;
            (*node)->right = nullptr;
            (*node)->left = nullptr;
            copy_Helper(&((*node)->left), other->left); //recursively going into left node and copying values
        	if ((*node)->isThreaded == false) {
                copy_Helper(&((*node)->right), other->right); //recursively going into right node and copying values
            }
        }
    }

    //Helper function that is called in put function. This helper function helps aid
    //in inserting a new node and adding the necessary threading.
    void insertHelper(struct NODE** node, struct NODE* newNode) {

        struct NODE* par = nullptr;
       
        if (*node == nullptr) {
            *node = newNode; // create new node
        }
        else {
            
            par = (*node); //To help track and debug parent node -- could just use (*node)

            if (newNode->key == (*node)->key) {
                (*node)->value = newNode->value;
            }

            if (newNode->key < (*node)->key) {
                insertHelper(&((*node)->left), newNode); //inserting node to left side
                if ((*node)->left->right == nullptr) {
                    (*node)->left->isThreaded = true;
                    (*node)->left->right = par;
                } 
            }
            
            if (newNode->key > (*node)->key) {
                if ((*node)->isThreaded) {
                    newNode->right = (*node)->right;
                    (*node)->right = newNode;
                    (*node)->isThreaded = false;
                    insertHelper(&((*node)->right), newNode); //inserting node to right side
                    (*node)->right->isThreaded = true;
                }
                else {
                    insertHelper(&((*node)->right), newNode); //inserting node to right side
                    if ((*node)->right->right == nullptr) {
                        (*node)->right->isThreaded = true; //fix not right
                    }
                }
            }
        }
        
    }

    

    //Helper function helps traverse through BTS and store value and key into a 
    //into a string. Function is called in toString().
    void toStringHelper(keyType& key, valueType& value, struct NODE* node, stringstream &stream)
    {
        int i = 0;
       
        if (node == nullptr || i > size) 
            return;
        
        
        /* recursively going throught he left */
        toStringHelper(key, value, node->left, stream);

        /* storing the data into stream */
        
        stream << "key: " << node->key << " value: " << node->value << "\n";
     
        
        /* re-cursively traversing to the right */
        if (node->isThreaded == false) {
            toStringHelper(key, value, node->right, stream);
        }

        /* re-cursively traversing to the right while acknowledging cases of threading*/
        if (node->right == nullptr) {
            toStringHelper(key, value, node->right, stream);
        }

    }

    //Helper function called in begin() to traverse to the left side of 
    //threaded BST to find the lowest key node
    static struct NODE* lowestNodeHelper(struct NODE* node) {

        while (node && node->left) {
            node = node->left;
        }

        return node;
    }

    //
   // iterator:
   // This iterator is used so that mymap will work with a foreach loop.
   //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        valueType value () {
            return curr->value;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {

            if (curr == nullptr) {
                return iterator(nullptr);
            }

            if (curr->isThreaded) {
                curr = curr->right;
            }
            else {
                curr = lowestNodeHelper(curr->right);
            }

            return iterator(curr); 
        }
    };

 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {

        root = nullptr;  
        size = 0;
    }

    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(mymap& other) {

        root = nullptr;
        size = 0;

        //using operator functiont to copy
        this->operator=(other);
    }

    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(mymap& other) {

        if (this == &other)
            return *this;

        clear();
        
    	copy_Helper(&root, other.root); //copying other values into root
        thread_CopyHelper(root); //initiating threading for copied nodes
        size = other.Size();
        

        return *this;  
    }

    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {


        clearHelper(root);

        root = nullptr;
        size = 0;
       
    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {

        clear();

    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {

        struct NODE* temp = new struct NODE;
        temp->value = value;
        temp->isThreaded = false;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->key = key;
        temp->nL = 0;
        temp->nR = 0;


        insertHelper(&root, temp);

        size++;
        //delete temp;
    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {

        NODE* temp = root; 

        while (temp != nullptr) {
            if (temp->key == key) {
                return true;
            }

            if (key < temp->key) { //traversing to the left
                temp = temp->left;
            }
            else {
                temp = temp->right; //traversing to the right
            }
        }
       
        return false;  // key was not found
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {


        NODE* temp = root;

        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value; //if key exits return the curr value
            }

            if (key < temp->key) { //traversing to the left
                temp = temp->left;
            }
            else {
                if (temp->isThreaded == false) {
                    temp = temp->right; //traversing to the right
                }
                else
                {
                    break; //reached nullptr
                }
            }
        }


        return valueType();  //return default value
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {


        NODE* temp = root;
        int i = 0;

        while (temp != nullptr && i < size) {
            if (temp->key == key) {
                return temp->value; //if key exits return the curr value
            }

            if (key < temp->key) { //traversing to the left
                temp = temp->left;
            }
            else {
                temp = temp->right; //traversing to the right
            }

            i++; //way to counter nullptr that is not avaible to break loop in threaded BST
        }

        if (temp->key != key) {
            put(temp->key, temp->value); //inserting new key and value pair
        }



        return valueType (); // return default value
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {

        if (size == 0) {
            return size = 0;
        }

        return size;  
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {

        struct NODE* temp = nullptr; 

        if (root != nullptr) {
            temp = lowestNodeHelper(root); //finding node with the smallest key
        }


        return iterator(temp);  // returning node with the smallest key
    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    // 
    // Time Complexity: O(1)
    //
    iterator end() {
        return iterator(nullptr);
    }

    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
 
        stringstream streamer;
        NODE* temp = root;
        keyType key;
        valueType value;

        toStringHelper(key, value, root, streamer);
      
        return streamer.str();
    }

    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    /* vector<pair<keyType, valueType> > toVector() {


        // TODO: write this function.


        return {};  // TODO: Update this return.
    }*/

    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {


        // TODO: write this function.


        return {};  // TODO: Update this return.
    }
};
