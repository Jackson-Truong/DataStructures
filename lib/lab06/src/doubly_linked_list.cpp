#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = NULL;
        tail = NULL;
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
    this->append(vector_input.at(i));
}
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
      node* copy = original.head;
      if(copy==NULL){
this->head = NULL;
this->tail = NULL;
      }
else{
          node* copier = new node(copy->get_data());
          this->head = copier;
    while (copy->next != NULL) {
        node *next = new node(copy->get_data());
        next->prev = copier;
        copier->next = next;
        copier = next;
        next = next->next;
        copy = copy->next;

    }
    copier->next = NULL;
    this->tail = copier;
}
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
        }
        for(unsigned i=position_from; i<=position_to; i++){
            int data = 0;
            data = current->get_data();
            current = current->next;
            links.push_back(data);
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
if(head==NULL){
    node* first = new node(input);
    head = first;
    tail = first;
}
else{
    while(current->next!=NULL){
        current = current->next;
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
        if(is_empty()){
            throw "ERROR,can not remove an empty linked list ";
        }
        if(position_1 >size()|| position_2>size()){
            throw"ERROR, can not have a location higher than the size of the linked list";
        }
        doubly_linked_list splitset(get_set(position_1, position_2));
        for(int i= position_2; i>=position_1;i--){
            remove(i);
        }
        return splitset;

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) { //void swap(unsigned position_1, unsigned position_2)`: Swap the node located at position 1 with the node located at position 2.
node * first = head;
node * second = head;

        if(position_1>=position_2){ //I am going to swap the two positions assuming that they accidently did this
            unsigned temp = position_2;
            position_2= position_1;
            position_1=temp;
        }
        if(position_1==position_2){
throw "ERROR";
        }
for(int i=0 ; i<position_1; i++) {
        first = first->next;
}
for(int i=0; i<position_2; i++) {
        second = second->next;
}
node*firstprev= first->prev; // this reinitializes firstprev
node*firstnext = first->next; //reinitializes firstnext
node*secondprev = second->prev; //reinitializes second prev
node*secondnext = second->next;// reinitializes second next
if(firstprev ==NULL && secondnext !=NULL){// Makes sure that this head swaps with an element that is not tail
    if(firstnext==second){//This means that they are next to each other
second->next = first;
first->prev = second;
first->next = secondnext;
secondnext->prev = first;
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
node*onestart = head;
node*oneend = head;
node*twostart = head;
node*twoend = head;
        unsigned count=0;
if(location_1_start > location_1_end){ //swaps location start and end just in case
   unsigned temp = location_1_end;
   location_1_end = location_1_start;
   location_1_start = temp;
}
if(location_2_start>location_2_end){ // same thing but with location 2
    unsigned temp = location_2_end;
    location_2_end = location_2_start;
    location_2_start = temp;
}
if(location_1_start>location_2_start||location_1_end>location_2_start){ // assuming that you do not need to check if loc>loc2end because the if statement above will already swap it
    unsigned tempstart = location_2_start;
    unsigned tempend = location_2_end;
    location_2_start = location_1_start;
    location_2_end = location_1_end;
    location_1_start = tempstart;
    location_1_end = tempend;
}
while(count!=location_1_start){
    onestart = onestart->next;
    count++;
}
count = 0;
while(count!= location_1_end){
    oneend = oneend->next;
    count++;
}
count =0;
while(count!= location_2_start){
    twostart = twostart->next;
    count++;
}
count =0;
while(count!=location_2_end){
    twoend = twoend->next;
    count++;
}
node* onestartprev = onestart->prev;
node* oneendnext = oneend->next;
node* twostartprev = twostart->prev;
node* twoendnext = twoend->next;
if(onestartprev==NULL&& twoendnext!=NULL){ //swapping head with any element that is not tail
if(oneendnext==twostartprev){//This means that the sets are next to each other
    twoendnext->prev = oneend;
    twoend->next =onestart;
    twostartprev = NULL;
    onestart->prev = twoend;
}
else{// They are not next to eachother but you are still swapping head
    oneend->next =twoendnext;
    twoend->next = oneendnext;
    onestart->prev = twostartprev;
    twostart->prev = NULL;
    twostartprev->next = onestart;
    twoendnext->prev = oneend;
    oneendnext->prev =twoend;
    head = twostart;

}
}
else if(onestartprev == NULL &&twoendnext == NULL ){ //This means that you are swapping head and tail
if(oneendnext == twostart){ // They are next to each ohter
    twoend->next = onestart;
    onestart->prev = twoend;
    oneend->next = NULL;
    twostart->prev = NULL;
    head = twostart;
    tail = oneend;
}

else{
    oneend->next =twoendnext;
    twoend->next = oneendnext;
    onestart->prev = twostartprev;
    twostart->prev = NULL;
    twostartprev->next = onestart;
    twoendnext->prev = oneend;
    oneendnext->prev =twoend;
head = twostart;

}
}
else if(oneendnext == twostart && onestartprev !=NULL && twoendnext !=NULL){ // swaps sets that are not head or tail
    onestartprev->next = twostart;
    twostart->prev = onestartprev;
    twoend->next = onestart;
    onestart->prev = twoend;
    oneend->next = twoendnext;
    twoendnext->prev = oneend;
}
else if(twoendnext==NULL && onestartprev !=NULL){// This means you are swapping tail with an element that is not head
    if(oneendnext == twostart){ //swapping sets next to tail
        onestartprev->next = twostart;
        twostart->prev = onestartprev;
        twoend->next = onestart;
        onestart->prev = twoend;
        oneend->next = NULL; // THis makes this the tail
        tail = oneend;
    }
else{
        onestartprev->next = twostart;
        twostart->prev=onestartprev;
        twoend->next = oneendnext;
        oneendnext->prev = twoend;
        twostartprev->next = onestart;
        onestartprev->prev = twostartprev;
        oneend->next = NULL;
        tail = oneend;
    }
}
else{ // They are just random sets in the linked list
    onestartprev->next = twostart;
    oneendnext->prev = twoend;
    twostartprev->next = onestart;
    twoendnext->prev = oneend;
    onestart->prev=twostartprev;
    twostart->prev= onestartprev;
    oneend->next = twoendnext;
    twoend->next = oneendnext;
}
//   tail with any elem(include tail next to tail),

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
        if(is_empty()){
            throw "ERROR";
        }
        node* current = head;
        int currentLoc = 0;
        node* checker = current->next;
        int checkerLoc = 1;
        while(checker != NULL&& checkerLoc <size()){    // If checker==NULL then no more numbers to sort
            node* temp = checker;
            checker = checker->next;
            int temp1 = currentLoc;
            int temp2 = checkerLoc;
            while(temp1!= -1 && temp2!=-1 &&temp->prev!= NULL && temp->get_data() < temp->prev->get_data()){
                swap(temp2, temp1);
                temp1--;
                temp2--;
            }
            currentLoc++;
            checkerLoc++;
        }
    }
//`doubly_linked_list operator+(const doubly_linked_list &rhs) const`: Append the right doubly linked list to the right doubly linked list and return that new doubly linked list object.
    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list together;
        node* current = head;
        node* copy = rhs.head;
        while(current!=NULL){
            together.append(current->get_data());
            current = current->next;
        }
        while(copy!=NULL){
            together.append(copy->get_data());
            copy = copy->next;
        }
        return together;
    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {
node* current = rhs.head;
if(this == &rhs){
    return *this;
}
while(current!=NULL){
this->append(current->get_data());
        current = current->next;

}
return *this;
    }
//`doubly_linked_list& operator+=(const doubly_linked_list &rhs)`: Append an entire doubly linked list to the end of an existing doubly linked list
    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
node* current = rhs.head;
while(current!=NULL){
    this->append(current->get_data());
    current=current->next;
}
return *this;

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
node* current = head;
node* rcurrent = rhs.head;
if(this->size()>rhs.size() || this->size()<rhs.size()){
    return false;
}
else{
    while(current!=NULL && rcurrent!=NULL){
        if(current->get_data() !=rcurrent->get_data()){
            return false;
        }
        current = current->next;
        rcurrent = rcurrent->next;
    }
    return true;
}
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
node* current = RHS.head;
while(current!=NULL){
    stream<<current->get_data()<<" ";
    current= current->next;
}
return stream;
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
int val;
stream>>val;
RHS.append(val);
return stream;
    }
}

