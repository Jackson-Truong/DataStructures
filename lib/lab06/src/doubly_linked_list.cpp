#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input) {
node* current = new node(input);
head = current;
tail = head;

    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {

    }

    doubly_linked_list::~doubly_linked_list() {
while(head!=NULL){
    node* temp = head;
    head=head->next;
    delete temp;
}

    }

    int doubly_linked_list::get_data(unsigned position) {
node*current =head;
for(int i=0; i<position; i++){
    current = current->next;
    current->prev=current;
}
if(head ==NULL){
    throw"ERROR, there is no links in this list";
}
return get_data(position); // Not sure if this is correct
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {


    }

    unsigned doubly_linked_list::size() {

    }

    bool doubly_linked_list::is_empty() {
if(!head){
    return true;
}
return false;
    }

    void doubly_linked_list::append(int input) {

    }

    void doubly_linked_list::insert(int input, unsigned int location) {

    }

    void doubly_linked_list::remove(unsigned location) {

    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
// keep track of b-1 b+1 b c-1 c c+1, 6 nodes temporary values
        //b->next = c
        //b+1-> prev=c
        //c-1->next = b
        //c+1->prev = b
        // b->bnext = c+1 b->prev = c-1
        //c->next = b+1
        //c-Prev = c-1 take care of edge cases under 6 length
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
/*
 * 8 pointers
 * a-1->next = c
 * B+1 ->previous = c
 * c-1->next = ca
 * d+1->previous = b
 * a prev = c-1
 * b next = d+1
 * c prev = a-1
 * d next = b+1
 * work o nheads and tails
 */
    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {

    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {

    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {

    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {

    }
}

