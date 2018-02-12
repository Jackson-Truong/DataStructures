#include "../inc/stringVector.h"
#include <stdexcept>
stringVector::stringVector() { //Test Passed
data = nullptr;
    length =0;
    allocated_length=0;
}

stringVector::~stringVector() { //Test Passed
delete[] data;
}

unsigned stringVector::size() const{ //Test Passed
return length;
    //return ;
}

unsigned stringVector::capacity() const{ //Test Passed
return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) { //Test Passed
std::string *fixArr = new std::string[new_size];
    if(new_size < allocated_length){
        for(int i=0; i<new_size && i< length; i++){
            fixArr[i]=data[i];
        }
    }
    allocated_length = new_size;
    delete []data;
    data = fixArr; // Tried to do delete []fixArr but I got errors, this one works but I do not know why. ask for explanation in class.
}

bool stringVector::empty() const{ //Test passed
    if(length ==0){ // I tried data!= NULL but there is something in the code, not sure why.
        return true;
    }
    return false;
    //return ;
}

void stringVector::append(std::string new_data) { //Test Passed
if(allocated_length > length) {
    data[length] = new_data;
    length++;
    return;
}
    else if (allocated_length==0){
    allocated_length = 1;
}
    else{
    allocated_length = allocated_length*2;
}
    reserve(allocated_length);
    delete[] data;

}

void stringVector::swap(unsigned pos1, unsigned pos2) {
if((pos1>=length)|| (pos2>=length)){

}
}

stringVector &stringVector::operator=(stringVector const &rhs) {
   delete[] data;
    if (&rhs == this) {
        return (*this);
    } else {
        length = rhs.length;
        allocated_length= rhs.allocated_length;
        this->data=new std::string[allocated_length];
        for(int i=0; i<length; i++){
            this->data[i]=rhs.data[i];

    }

}
}

std::string &stringVector::operator[](unsigned position) { //Test Passed
if(position > allocated_length){ // out of scope
   throw 0;
}//std::out_of_range
    return data[position ];
    //return ;
}

void stringVector::sort() {

}
