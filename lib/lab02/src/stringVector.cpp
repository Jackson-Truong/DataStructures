#include "../inc/stringVector.h"

stringVector::stringVector() {
    data = nullptr;
    length = 0;
    allocated_length=length;
}

stringVector::~stringVector() {
    length = 0;
    allocated_length=0;
    delete []data;
}

unsigned stringVector::size() {
    return 0;

    //return ;
}

unsigned stringVector::capacity() {
   return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {
new

    data[length] = data[new_size];
}

bool stringVector::empty() {
    if(data == 0){
        return true;
    }
    //return ;
}

void stringVector::append(std::string new_data) {



}

void stringVector::swap(unsigned pos1, unsigned pos2) {

}

stringVector &stringVector::operator=(stringVector const &rhs) {

    //return ;
}

std::string &stringVector::operator[](unsigned position) {
    for(int i=0; i<position; ++i){

    }
    //return ;
}

void stringVector::sort() {

}
