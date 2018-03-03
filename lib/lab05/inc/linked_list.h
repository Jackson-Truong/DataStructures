#ifndef CMPE126S18_LABS_LIB_LAB05_INC_LINKED_LIST_H
#define CMPE126S18_LABS_LIB_LAB05_INC_LINKED_LIST_H

#include "node.h"
#include <iostream>

namespace lab5 {
    class linked_list {
        node *head, *tail;

    public:
        linked_list();

        explicit linked_list(std::string &data);

        linked_list(const linked_list &original);

        virtual ~linked_list();

        linked_list &operator=(const linked_list &RHS);

        friend std::ostream& operator<<(std::ostream& stream, linked_list& RHS);
        friend std::istream& operator>>(std::istream& stream, linked_list& RHS);

        bool isEmpty() const;
        unsigned listSize() const;

        void insert(const std::string input, unsigned location = 0 ); // This is going to insert a new node, can inssert at the end of the list or beginning
        // to insert at the end of the linked list all we need to do is make the last node and set the address part of it to point at the new node.
        //thsi new node will point at NULL
        void append(const std::string input);
        void remove(unsigned location = 0); // remove end of the list or the beginning of the list.

        void sort();
    };
}
//`linked_list::insert(input, location = 0)`: create a node from the input string and put it into the linked list at the given location
//
//`linked_list::append(input)`: create a new node and put it at the end/tail of the linked list
//
//`linked_list::remove(location = 0)`: Remove the node at the given location
//
//`linked_list::sort()`: Perform selection sort on the linked list
//
//`linked_list::listSize()`: Note that you do **not** have a size variable in your linked list. You *MUST* count the nodes.
#endif