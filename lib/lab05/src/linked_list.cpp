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
        node *iterator = original.head;//copies head
        node *temp = head;
        for (int i = 0; i < original.listSize(); i++) {
            temp->data = iterator->data;
            temp->next = iterator->next;
        }
        tail = original.tail;
    }

    linked_list::~linked_list() {
        while (head) {
            node *temp = head->next;
            delete head;
            head = temp;
            tail = nullptr;
        }
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        node *current = RHS.head;
        if (this == &RHS) { //Makes sure that it does not delete an element on accident
            return *this;
        }
        while (current->next != nullptr) {
            node *copy = new node(current->data);//Copy will link new nodes with RHS' data
            current = current->next;
            if (head == NULL) {
                node *temp = new node(
                        current->data); //Not too sure on this but this is just for the first element, incase it does not even go through the while loop once

            }
        }
        return *this;
    }


    bool linked_list::isEmpty() const {
        if (!head){
            return true;
        }
        return false;
    }

    unsigned linked_list::listSize() const {
        int size=0;
        node *temp = head;
        if (isEmpty()) { //
            return 0;
        } else {
            while (temp != nullptr) {
                size++;
                temp = temp->next;
            }
        }
        return size;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
node* previous = NULL;
        node* tmp1 = head;
  node* tmp = new node(input);
  for(int i=0 ; i<location; i++){
      previous = tmp1;
      tmp1=tmp1->next;
  }
  if(previous){
      previous->next = tmp;
      tmp->next = tmp1;
  }
  if(location ==0){
      head = tmp;
      head->next = tmp1;
  }
    }

    void linked_list::append(const std::string input) {
        node *current = head;
        if (head == NULL) {
            node *first = new node(input);
            head = first;
            tail = first;
        }
        else {
            while (current->next != NULL) {
                current = current->next;
            }
                node *tmp = new node(input);
                current->next = tmp;
                tmp->next = NULL;
                tail = tmp;
            }
}

    void linked_list::remove(unsigned location) {
        node *prev = NULL;
        node *current = head;
        for (int i = 0; i < location; i++) {
            prev = current;
            current = current->next;
        }
        if (prev) {
            prev->next = current->next;
            current = NULL;
        }
        if(location>listSize()){
            throw 0;
        }
        else if(!prev){
            head = current->next;
        }
        }


    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
int size = RHS.listSize();

for(int i=0; i<size;i++) {
    stream << RHS.get_value_at(i);
    stream << " -> ";
}
        stream << std::string("NULL");
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
      std::string temporary;
      getline(stream, temporary);
      RHS.append(temporary);
        return stream;
    }

    void linked_list::sort() { //Wikipedia based change

     int size;
     size= listSize();
     for(unsigned a =0; a<size-1; a++){
         unsigned minimum=a;
         for(unsigned b=a+1; b<size; b++){
             if(get_value_at(minimum)>get_value_at(b)){ //compares thru the whole linked list
                 minimum=b;
             }
         }
         if(minimum!=a){//This will now sort
             std::string tempb(get_value_at(minimum));
             std::string tempa(get_value_at(a));
             remove(a);
             insert(tempb,a);
             remove(minimum);
             insert(tempa,minimum);
         }
     }

    }

        std::string linked_list::get_value_at(unsigned location) const {
            std::string value;
            node *current = head;
            for (int i = 0; i < location; i++) {
                current = current->next;
            }
            if (head == NULL) {
                throw "ERROR, there is no links on the list";
            }
            value = current->data;
            return value;
        }
    }
