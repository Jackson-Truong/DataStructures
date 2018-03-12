#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {
head->data = data;
tail = head;
    }

    linked_list::linked_list(const linked_list &original) {
node* iterator = original.head;//copies head
node* temp = head;
for(int i=0; i< original.listSize(); i++){
    temp->data = iterator->data;
   temp->next = iterator->next;
}
tail = original.tail;
    }

    linked_list::~linked_list() {
while(head){
    node *temp = head->next;
    delete head;
    head= temp;
    tail = nullptr;
}
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
node* current = RHS.head;
if(this == &RHS){ //Makes sure that it does not delete an element on accident
    return *this;
}
while(current->next != nullptr){
node* copy = new node(current->data);//Copy will link new nodes with RHS' data
current= current->next;
if(head == NULL){
  node* temp= new node(current->data); //Not too sure on this but this is just for the first element, incase it does not even go through the while loop once

}
}
return *this;
    }


    bool linked_list::isEmpty() const {
node *head = head;
node *tail;
if(head== nullptr){
    if(tail== nullptr){//Has to go through the if head is nullptr first just incase
        return true;
    }
    return false;
}
        return false;
    }

    unsigned linked_list::listSize() const {
     unsigned size;
     node* temp =head;
       if(head == nullptr && tail == nullptr){ //
return isEmpty();
       }
       else{
          while(temp!=nullptr){
              size++;
              temp = temp->next;
          }
       }
        return size;
    }

    void linked_list::insert(const std::string input, unsigned int location) {

        node *previous = NULL;
        node *current;
            node *temporary = new node(input);
        current = head;
        if(head== NULL){
            head = temporary;
            tail = temporary;
        }
        for(int i=0; i<location; ++i){
            previous = temporary;
            current = current->next;
        }
if(previous){ // if it does exist set it to temporary
    previous->next = temporary;
    temporary->next = current;

}

        else{
            head= temporary;
            temporary->next = current;
        }
        delete temporary;
    }

    void linked_list::append(const std::string input) {
          node* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = new node(input);
    tail = tmp->next;
    tail->next = NULL;
    }

    void linked_list::remove(unsigned location) {
        node *previous = NULL;
        node *current;
        current = head;
        for(int i=0; i<location; ++i) {
                previous = current;
                current = current->next;
            }
            if(previous){
                previous->next = current->next; // unlinks the node
            delete current;
        }
        else{
            head= current->next;
            delete current;
        }
        }


    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
unsigned size = linked_list::listSize();
stream<< "Linked List: ";
for(int i=0; i<size;i++) {
    stream << RHS.get_value_at(i);
    stream << ", ";
}
        stream << std::string("\n");
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
      std::string temporary;
      getline(stream, temporary);
      RHS.append(temporary);
        return stream;
    }

    void linked_list::sort() {//wikipedia sort function pseudocode
int size;
size = listSize();
std::string tmp;
for(unsigned j=0; j< size-1; j++){
std::string minimum;
  minimum=  get_value_at(j); //J becomes the minimum value, j is the beginning of the linked list. using the get_value_at function made below
for(int k=j+1; k<size; k++){//value ahead of J so that it can compare one vs the one after it
    if(get_value_at(k)<minimum){//Compares the minimum value(j) with the value ahead of it, if passes minimum = k, the value ahead of the current minimum
        minimum = get_value_at(k);
    }
    if(minimum!=get_value_at(j)){// if it did get swapped then this is how you fully swap the whole thing.
std::string tempj = get_value_at(j);
std::string tempk = get_value_at(k);
remove(k);
insert(tempk, k);
remove(j);
insert(tempj,j);

    }
}
}

    }

    std::string linked_list::get_value_at(unsigned location) const {
std::string value =0;
node* current = head;
for(int i=0; i<location; i++){
    current= current->next;
}
if(head == NULL){
    throw "ERROR, there is no links on the list";
}
value = current->data;
return value;
    }
}