#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);

    unsigned maxDepth(node *ptr);

    struct node *Rinsert(node *ptr, int key);

    int Rlevel(node *ptr, int key);

    int RFrequency(node *ptr, int key);

    bool RinTree(node *ptr, int key);

    struct node *copying(node *Copyroot);

    void Rpath(node *ptr, int key);

    void Rprint(node *ptr);

    node *RoperatorEq(node *ptr);

    std::vector<int> RValuesAbove(int key, node *ptr, std::vector<int> &values_above);


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
        node *current = root;
        if (current == nullptr) { // Empty tree
            node *insert = new node(value);
            root = insert;
        }
        Rinsert(current, value);
        tree_size++;
    }

    // Remove key
    bool tree::remove(int key) {

    }

    // What level is key on?
    int tree::level(int key) {
        if (in_tree(key)) {
            return Rlevel(root, key);
        } else {
            return -1;
        }
    }


    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        if (in_tree(key) == true) {
            Rpath(root, key);
        }
    }

    // Number of items in the tree
    unsigned tree::size() {
        return tree_size;
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        node *current = root;
        unsigned depth = maxDepth(current);
        if (depth < 0) {
            return 0;
        }
        if (depth == 0) {
            return 0;
        } else {
            return (depth - 1);
        }
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        return (RinTree(root, key));
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        return RFrequency(root, key);
    }

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        std::vector<int> current = std::vector<int>();
        return RValuesAbove(key, root, current);

    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        Rprint(root);
        std::cout<< "\n";
    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {
        Rprint(RHS.root);
        stream<< "\n";
    }

    tree::tree(const tree &copy) {
        root = copying(copy.root);
    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {
        if(rhs.root == nullptr){
            this->root = nullptr;
        }
        else{
            root = RoperatorEq(rhs.root);
        }
        return *this;
    }


    /*
     * Extra credit functions
     */

    // Merge rhs into this. Demo to a TA for credit

    tree tree::operator+(const tree &rhs) {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*
     * Recursion Example
     * Print the linked list from greatest to least using recursion
     */

    // Auxiliary functions
    unsigned maxDepth(node *ptr) { //geeksforgeeks implementation of maxdepth using recursion,
        if (ptr == nullptr) {
            return 0;
        } else {
            unsigned LeftDepth = maxDepth(ptr->left);
            unsigned RightDepth = maxDepth(ptr->right);

            if (LeftDepth > RightDepth) {
                return (LeftDepth + 1);
            } else {
                return (RightDepth + 1);
            }
        }
    }

    int RFrequency(node *ptr, int key) {
        if (ptr == nullptr) {
            return 0;
        } else if (key < ptr->data) {
            return RFrequency(ptr->left, key);
        } else if (key > ptr->data) {
            return RFrequency(ptr->right, key);
        } else if (key == ptr->data) {
            return ptr->frequency;
        }

    }

    int Rlevel(node *ptr, int key) {
        unsigned lvl;
        if (ptr->data == key) {
            return 0;
        }
        if (ptr->data > key) {
            lvl = Rlevel(ptr->left, key);
            return (lvl + 1);
        }
        if (ptr->data < key) {
            lvl = Rlevel(ptr->right, key);
            return (lvl + 1);
        }

    }

    struct node *Rinsert(node *ptr, int key) {
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

    bool RinTree(node *ptr, int key) {
        if (ptr == nullptr) {
            return false;
        } else if (ptr->data == key) {
            return true;
        } else if (ptr->data < key) {
            return (RinTree(ptr->right, key));
        } else if (ptr->data > key) {
            return (RinTree(ptr->left, key));
        }
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

    struct node *copying(node *Copyroot) {

        if (NULL == Copyroot) {
            return NULL;
        } else {
            node *cNode = new node(Copyroot);
            cNode->data = Copyroot->data;
            cNode->frequency = Copyroot->frequency;
            cNode->left = copying(Copyroot->left);
            cNode->right = copying(Copyroot->right);
            return cNode;
        }
    }

    void Rpath(node *ptr, int key) {
        std::cout << ptr->data;
        if (ptr->data == key) {
            std::cout << "\n";
            return;
        } else {
            std::cout << " ";
            std::cout << "-> ";
            if (key < ptr->data) {
                Rpath(ptr->left, key);
            } else if (key > ptr->data) {
                Rpath(ptr->right, key);
            }
        }

    }


    void Rprint(node *ptr) {
        if (ptr == nullptr) {
            return;
        }
        Rprint(ptr->left);
        for (unsigned i = 0; i < ptr->frequency; i++) {
            std::cout << ptr->data;
            std::cout << " ";
        }

        Rprint(ptr->right);

    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }

    node *RoperatorEq(node *ptr) {
       if(ptr == nullptr){
           return nullptr;
       }
       node* current = new node(ptr->data);
        current->left = RoperatorEq(ptr->left);
        current->right = RoperatorEq(ptr->right);
        return current;
        }

    std::vector<int> RValuesAbove(int key, node *ptr, std::vector<int> &values_above) {
        if (ptr == nullptr) {
            return std::vector<int>();
        }
        RValuesAbove(key, ptr->left, values_above);
        for(int i=0; ptr->data >key && i<ptr->frequency; i++){
            values_above.push_back(ptr->data);
        }
        RValuesAbove(key, ptr->right, values_above);
        return values_above;
    }
}

