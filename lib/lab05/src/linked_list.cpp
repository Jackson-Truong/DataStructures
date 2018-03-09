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
    tail = tail->next;
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
        }


    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {

        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
      std::string temporary;
      getline(stream, temporary);
      RHS.append(temporary);
        return stream;
    }

    void linked_list::sort() {
int size;
        node* current = head;
node* last = tail;
while(current->next !=nullptr){
    ++size;
        current = current->next;
}
for(int i=0; i<=size; i++){
if(current->data > current->next->data){
    node* tmp = current;
    current->data = current->next->data;
    current->next->data = tmp->data;
}
}
    }

    std::string linked_list::get_value_at(unsigned location) {

    }
}