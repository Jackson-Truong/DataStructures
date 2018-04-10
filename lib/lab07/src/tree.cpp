#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);
    unsigned maxDepth(node *ptr);
    struct node* Rinsert(node* ptr, int key);
    // Construct an empty tree
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert DONE
    void tree::insert(int value) {
       node* current = root;
       Rinsert(current, value);
       tree_size++;
    }
    // Remove key
    bool tree::remove(int key) {

    }

    // What level is key on?
    int tree::level(int key) {
int lvl =0;
node* current = root;
while(current) {
    if (current->data == key) {
        return lvl;
    }
    else if(current->data > key){
        current = current->left;
        lvl++;
    }
    else if(current->data < key){
        current = current->right;
        lvl++;
    }
}
throw"ERROR, enter another key";
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
std::vector<int>  top= values_above(key);
top.push_back(key);
for(int i =0; i<=top.size(); i++){
    std::cout<< top.at(i);
}
    }
    
    // Number of items in the tree
    unsigned tree::size() {
return tree_size;
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        node *current = root;
        return maxDepth(current);
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
int yes =0;
if(get_frequency(key) == yes){
    return false;
}
return true;
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        node*current = root;
        while(current){
            if(current->data > key){
                current = current->left;
            }
            else if(current->data < key){
                current = current->right;
            }
            else if(current->data == key){
                return current->frequency;
            }
        }
        throw"ERROR, please check your key";
    }

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        std::vector<int> path;
        node *current = root;
        if (current == nullptr) {
            throw "ERROR, can not return a vector of no nodes";
        }
        if (!in_tree(key)) {
            throw "ERROR, please try another key";
        }
        while (current) {
            if (current->data > key) {
                    path.push_back(current->data);
                current = current->left;
            } else if (current->data < key) {
                    path.push_back(current->data);

                current = current->right;
            } else {
                return path;
            }
        }
    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {

    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {

    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {

    }


    /*
     * Extra credit functions
     */

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*
     * Recursion Example
     * Print the linked list from greatest to least using recursion
     */

    // Auxiliary functions
    unsigned maxDepth(node* ptr){ //geeksforgeeks implementation of maxdepth using recursion,
        if(ptr == nullptr){
            return 0;
        }
        else{
            unsigned LeftDepth = maxDepth(ptr->left);
            unsigned RightDepth = maxDepth(ptr->right);

            if(LeftDepth > RightDepth){
                return (LeftDepth+1);
            }
            else{
                return(RightDepth+1);
            }
        }
    }

    struct node* Rinsert(node* ptr, int key) {
        if (ptr == nullptr) {
            node *temp = new node(key);
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        } else {
            if (key < ptr->data) {
                ptr->left = Rinsert(ptr->left, key);
            } else if (key > ptr->data) {
                ptr->right = Rinsert(ptr->right, key);
            } else {
                ptr->frequency++;
                return ptr;
            }
        }
        return ptr;
    }
    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }


}
// node *current = root;
//        node *temp = nullptr;
//        if (root == nullptr) {
//            node *temp = new node(value);
//            tree_size++;
//        } else {
//            node *val = new node(value);
//            while (current) {
//                if (current->data > val->data) {
//                    temp = current;
//                    current = current->left;
//                } else if (current->data < val->data) {
//                    temp = current;
//                    current = current->right;
//                } else { //equal to each other WILL NOT EXIT THE WHILE LOOP
//                    current->frequency++;
//                    tree_size++;
//                    return;
//                }
//            }
//            if (temp->data < val->data) {
//                temp->right = val;
//                tree_size++;
//            } else {
//                temp->left = val;
//                tree_size++;
//            }
//        }