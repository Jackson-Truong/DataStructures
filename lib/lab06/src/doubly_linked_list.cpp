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
int value = 0;
value = current->data;
return value;
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {


    }

    unsigned doubly_linked_list::size() {
int size =0;
node* current = head;
if(is_empty()){
    return 0;
}
else{
    while(current!= NULL){
        size++;
        current = current->next;
        current->prev=current;
    }
}
return size;
    }

    bool doubly_linked_list::is_empty() {
if(!head){
    return true;
}
return false;
    }

    void doubly_linked_list::append(int input) {
node* current = head;
node*previous = NULL;
if(head==NULL){
    node* first = new node(input);
    head = first;
    tail = first;
}
else{
    while(current->next!=NULL){
        previous = current;
        current = current->next;
        current->prev=previous;
    }
    node* tmp = new node(input);
    current->next = tmp;
    current->prev=previous;
    tmp->next=NULL;
    tmp->prev=current;

}
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
node* previ = NULL;
node *current=head;
node* tmp = new node(input);
if(head == NULL){
    head = tmp;
    tail = tmp;
}
else if(head !=NULL){
    for (int i = 0; i < location; i++) {
        previ= current;
        current = current->next;
        current->prev = previ;
    }
}
if(current!=NULL){//insert between previous and current
            previ->next =  tmp;
            tmp->prev = previ;
            tmp->next = current;
            current->prev= tmp;
        }
else{// insert at the tail, basically appending
    previ->next = current;
    current->prev=previ;
    current->next = tmp;
    tmp->next = NULL;
    tmp->prev = current;
}
    }

    void doubly_linked_list::remove(unsigned location) {
node* current = head;
node* prev =NULL;
        if(is_empty()){
    throw "ERROR,can not remove an empty linked list ";
}
if(location >size()){
    throw"ERROR, can not have a location higher than the size of the linked list";
}
for(int i=0; i<location; i++){

            prev = current;

            current = current->next;
            current->prev=prev;
        }
        if(prev){
            prev->next = current->next;
            current->next->prev= prev;
            current = NULL;
        }
        else if(!prev){
            head = current->next;
            current->prev= NULL;
        }

    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
node* pre = NULL;
node* current = head;
node* tmptail=  NULL;
node* tmphead = NULL;
        if(is_empty()){
            throw "ERROR,can not remove an empty linked list ";
        }
        if(position >size()){
            throw"ERROR, can not have a location higher than the size of the linked list";
        }
for(int i=0; i<position; i++){
    pre = current;
    current = current->next;
    current->prev= pre;
}
        //Not sure how to truncate the original linked list and return the split off linked list
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

