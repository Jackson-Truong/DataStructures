#include "../inc/stringVector.h"

stringVector::stringVector() {
data = nullptr;
    length =0;
    allocated_length=0;
}

stringVector::~stringVector() {
delete[] data;
}

unsigned stringVector::size() const{
return length;
    //return ;
}

unsigned stringVector::capacity() const{
return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {
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

bool stringVector::empty() const{
    if(length ==0){ // I tried data!= NULL but there is something in the code, not sure why.
        return true;
    }
    return false;
    //return ;
}

void stringVector::append(std::string new_data) {
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
length = rhs.length;
    allocated_length= rhs.allocated_length;
    data = new std::string[allocated_length];
    for(int i=0; i<length; i++){
        data[i] = rhs.data[i];
    } // not sure if this is going to affect the string vector std library part of the assignment
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
if(position > allocated_length){ // out of scope
   throw ("Out of scope");
}//std::out_of_range
    return data[position ];
    //return ;
}

void stringVector::sort() {

}
