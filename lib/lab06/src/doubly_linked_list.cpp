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
if(vector_input.size() == 0){
 throw 0;
}
for(int i=0; i<vector_input.size();i++){
    append(vector_input.at(i));
}
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        node *iterator ;
        iterator= original.head;//copies head
        for (int i = 0; i < original.size(); i++) {
            node* copy = new node(iterator->get_data());
            copy->next = iterator->next;
            copy->prev = iterator->prev;
            iterator= iterator->next;
        }
        tail = original.tail;
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
}
if(head ==NULL){
    throw"ERROR, there is no links in this list";
}
      int value=0;
value=  current->get_data();
return value;
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        std::vector<int> links;
        node* current = head;
        if(position_from<0 && position_from>=size() && position_to<0 && position_to>=size()){
            throw "ERROR, please do not choose any negative numbers, or exceed the linked list size";
        }
        if(position_from> position_to){
            unsigned temp = position_from;
            position_from= position_to;
            position_to = temp;
        }
        for(unsigned i=0; i<position_from; i++){
            current = current->next;
            current->prev = current;
        }
        for(unsigned i=position_from; i<=position_to; i++){
            int data = 0;
            data = current->get_data();
            links.push_back(data);
            current = current->next;
        }
        return links;
    }

    unsigned doubly_linked_list::size() const{
int size =0;
node* current = head;
if(!head){
    return size;
}
else{
    while(current!= NULL){
        size++;
        current = current->next;
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
if(location>size()){
   append(input); //Basically destroys what the user location is and appends it to the last location.
}
else if(head !=NULL){
    for (int i = 0; i < location; i++) {
        previ= current;
        current = current->next;
        current->prev = previ;
    }
}
if(current!=NULL&& previ){//insert between previous and current, has to make sure that current isnt past the end as well as previous exists
            previ->next =  tmp;
            tmp->prev = previ;
            tmp->next = current;
            current->prev= tmp;
        }
else{// insert at the tail, basically appending, i have one with location but they might want to insert at the exact size, could have done location>=size() but wanted to keep them distinct
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
    throw "ERROR,can not remove elements from an empty linked list ";
}
if(location >size()){
    location = size(); // kind of like insert, instead of throwing an error i would rather just make it dequeue from the last element
}
for(int i=0; i<location; i++){
            prev = current;
            current = current->next;
            current->prev=prev;
        }
        if(prev){
            prev->next = current->next;
            current->next->prev= prev;
        }
        else if(!prev){
            head = current->next;
            head->prev= NULL;//unlinks current node
        }
        delete(current);
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
doubly_linked_list first(get_set(0, position-1)); // kept the first one just in case
for(int i=0; i<position; i++){
    pre = current;
    current = current->next;
    current->prev= pre;
}
        tmphead= current; //copy constructor might do this already
        tmphead->prev=NULL;// copy constructor might do this already
doubly_linked_list second (get_set(position, size()-1));
for(int i= size()-1; i<=position;i++){
  remove(i);
}
return second;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
        node* pre = NULL;
        node* current = head;
        node* tmptail=  NULL;
        node* tmphead = NULL;
        if(is_empty()){
            throw "ERROR,can not remove an empty linked list ";
        }
        if(position_1 >size()|| position_2>size()){
            throw"ERROR, can not have a location higher than the size of the linked list";
        }
        for(int i=0; i<position_1; i++){
            pre = current;
            current = current->next;
            current->prev= pre;
        }
        tmphead= current; //copy constructor might do this already
        tmphead->prev=NULL;// copy constructor might do this already
        doubly_linked_list splitset(get_set(position_1, position_2));
        for(int i= position_2; i<=position_1;i++){
            remove(i);
        }
        return splitset;

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) { //void swap(unsigned position_1, unsigned position_2)`: Swap the node located at position 1 with the node located at position 2.
node * first = head;
node * firstprev= NULL;
node * second = head;
node *secondprev = NULL;
node *firstnext = first->next;
node *secondnext = second->next;
unsigned count1=0;
unsigned count2=0;
if(position_1>position_2){ //I am going to swap the two positions assuming that they accidently did this
    unsigned temp = position_2;
    position_2= position_1;
    position_1=temp;
}
if(position_1==position_2){
    position_2 +=1;//adds 1 to position_2 to assume that they actually wanted to swap two elements next to each other

}
while(count1!=position_1){ // gets to the node at position 1
    first = first->next;
    count1++;
}
while(count2!=position_2){ // gets to the node at position 2
    second = second->next;
    count2++;
}
firstprev= first->prev; // this reinitializes firstprev
firstnext = first->next; //reinitializes firstnext
secondprev = second->prev; //reinitializes second prev
secondnext = second->next;// reinitializes second next
if(firstprev ==NULL && secondnext !=NULL){// Makes sure that this head swaps with an element that is not tail
    if(firstnext==second){//This means that they are next to each other
second->next = first;
first->prev = second;
first->next = secondnext;
second->next = first;
second->prev = NULL; // Have to make second previous = to NULL, just like normal head nodes
head =second; // Have to reinitialize second as the head
    }
    else{ //they are not next to each other
      first->next = secondnext;
      second->next = firstnext;
      first->prev = secondprev;
      second->prev = NULL; // Now this is the head
      secondprev->next = first;
      secondnext->prev = first;
      firstnext->prev = second;
      head = second;
    }
}
else if (firstprev == NULL&& secondnext == NULL){ // This means that you are swapping head with tail
    if(size() == 2){//There are only two elements in the linked list, a head and a tail.
        second->next = first;
        first->prev = second;
        first->next = NULL;
        second->prev = NULL;
        head = second;
        tail = first;
    }
    else{ // they are not next to each other but it is the head and tail
first->prev = secondprev;
first->next = NULL; //makes this the tail
secondprev->next = first;
second->prev = NULL; // makes this the head
second->next = firstnext;
firstnext->prev = second;
        head = second;
        tail = first;
    }
}
else if(secondnext==NULL &&firstprev !=NULL) {//This means that you swap tail with a random element
    if (firstnext == second) { // n-1 element and nth element
        firstprev->next = second;
        second->prev = firstprev;
        second->next = first;
        first->prev = second;
        first->next = NULL; //makes this the tail
        tail = first;
    }
        else{
            firstprev->next = second;
            second->prev = firstprev;
            second->next = firstnext;
            firstnext->prev = second;
            secondprev->next = first;
            first->prev = secondprev;
            first->next = NULL;//makes this the tail
        tail = first;

    }
}
else if(firstnext==second&& firstprev !=NULL && secondnext !=NULL){//This swaps elements next to each other if they are not head or tai.
    firstprev->next = second;
    second->prev = firstprev;
    second->next = first;
    first->prev = second;
    first->next = secondnext;
    secondnext->prev = first;

}
else{ //They are just random elements in the linked list
firstprev->next =second;
firstnext->prev= second;
secondprev->next = first;
secondnext->prev = first;
first->prev= secondprev;
second->prev = firstprev;
first->next = secondnext;
second->next = firstnext;
}


//swap head with element next to you
        // swap tail with previous elemen
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

