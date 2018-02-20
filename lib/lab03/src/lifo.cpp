#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);//You would need to reserve 100 spaces because of the readme
    index=0;//Set the index of the array = to 0
    }

    lifo::lifo(std::string input_string) {
lifo_storage.reserve(100);
        lifo_storage.append(input_string);// same as the first constructor but you are appending an input_string
        index=1;
    }

    lifo::lifo(const lifo &original) {
index = original.index;//Copies the information from the private to &original. had to add const to the lab2 std::string &operator[](unsigned position) in order for this to work.
        for(int i=0; i<index;i++){
            lifo_storage[i]=original.lifo_storage[i];// Have to do an array to copy each array element onto original
        }
    }

    lifo::~lifo() {
lifo_storage.set_size(0);// same as fifo, but you just need to make index =0
        index=0;
    }

    lifo &lifo::operator=(const lifo &right) {// Same as fifo, assignment operator
        lifo_storage.reserve(right.lifo_storage.capacity());
        index= right.index;
        for(int i=0; i<= index; i++){
            lifo_storage[i]=right.lifo_storage[i];
        }
        //return <#initializer#>;

    }

    bool lifo::is_empty() const {// It should return true unless the index is greater than or equal to 1
       if(index>=1){
           return false;
       }
        else{
           return true;
       }
    }

    unsigned lifo::size() const {
        if(is_empty()==false){ // Just to check if index is = to 0, if it is 0 then you return nothing which has the value of 0
            return index;//Probably did extra steps in this function
        }
        else {
            int nothing=0;
            return nothing;
        }
    }

    std::string lifo::top() const {
        return lifo_storage[index-1]; // I do not know what std::__cxx11:string() means
        //return std::__cxx11::string();
        //The top of the stack should always be the index-1 because both index and the array starts at 0, but when you add an elem it adds to 0 but array goes to 1
    }

    void lifo::push(std::string input) {
       ++index;// Need to add a space into the index first before appending the input string
        lifo_storage.append(input);
    }

    void lifo::pop() {
        if(index == -1){//This makes sure that index is not = 0, remember index is a number above the elems in array
            throw"ERROR, empty";
            }
        else{
           --index;//takes away from the index
        }
    }
}