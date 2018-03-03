#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {

    }

    linked_list::linked_list(const linked_list &original) {

    }

    linked_list::~linked_list() {

    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        return false;
    }

    unsigned linked_list::listSize() const {
        return 0;
    }

    void linked_list::insert(const std::string input, unsigned int location) {

        node *previous = NULL;
        node *current;
        node *temporary = new node(input);
        current = head;
        for(int i=0; i<location; ++i){
            previous = temporary;
            current = current->next;
        }
if(previous){
    previous->next = temporary;
    temporary->next = current;

}
        else{
            head= temporary;
            temporary->next = current;
        }
    }

    void linked_list::append(const std::string input) {
        node *previous;
        node *temporary = new node(input);
temporary->data = input;
temporary->next = nullptr;
    }

    void linked_list::remove(unsigned location) {
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }

    void linked_list::sort() {

    }
}