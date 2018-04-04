#include "../inc/stringVector.h"
#include <stdexcept>
namespace lab2 {
    stringVector::stringVector() { //Test Passed

        data = nullptr;// set the pointer to nullptr
        length = 0;// set the length of the array to 0
        allocated_length = 0;// set the allocated length of the array to 0
    }

    stringVector::~stringVector() { //Test Passed
        delete[] data;//This is to avoid memory leaking
    }

    unsigned stringVector::size() const { //Test Passed
        return length;// This is to return the private member function of length
        //return ;
    }

    unsigned stringVector::capacity() const { //Test Passed
        return allocated_length;// This is to return the private member function of allocated_length
        //return ;
    }
    void stringVector::reserve(unsigned new_size) { //Test Passed
        auto *fixArr = new std::string[new_size]; //Made a temporary pointer equal to a dynamic array with the function's parameter
        if(length>new_size){
            length =new_size;
        }
        for (int i = 0; i < new_size && i < length; i++) {
            fixArr[i] = data[i];//Copies data's info
        }
        allocated_length = new_size;// basically an else statement that is used to truncate for the reserve function
        delete[]data;
        data = fixArr; // Tried to do delete []fixArr but I got errors, this one works but I do not know why. ask for explanation in class.
    }

    bool stringVector::empty() const { //Test passed
        if (length == 0) { // I tried data!= NULL but there is something in the code, not sure why.
            return true;// if length is 0 then empty is true
        }
        return false;//Else returns false
        //return ;
    }


     void stringVector::append(std::string new_data) { //Test Passed //Might need a pointer because of the test fail in another test
        if (allocated_length == 0) {// equality operator
            this->reserve(1);//reserves a space if the allocated_length is equal to 0 to 1 because you can not just multiply 0 by 2
            this->append(new_data);// goes through the append function
        } else if (length == allocated_length) { // equality operator
            this->reserve(allocated_length * 2);// Reserves double the amount of allocated_length because of README
            this->append(new_data);//Goes through the append function
        }
         else {
            data[length] = new_data;
            length++;//Adds an element to the data array
            return;
        }
    }
   void stringVector::swap(unsigned pos1, unsigned pos2) {
        if ((pos1 > length) || (pos2 > length)) { //This is used to check if the positions are out of bounds
            throw 0; //Threw 0 because I was not sure what to throw, strings did not work
        } else {
            std::string tmp = data[pos1];//Have to create a temporary string in order to hold the data of pos1
            data[pos1] = data[pos2];
            data[pos2] = tmp;
        }
    }
    stringVector &stringVector::operator=(stringVector const &rhs) { //Test Passed

        if (&rhs == this) {// equality operator
            return (*this);
        } else {
            delete[] data; //avoids leaking
            length = rhs.length;
            allocated_length = rhs.allocated_length;
            this->data = new std::string[allocated_length];
            for (int i = 0; i < length; i++) {
                this->data[i] = rhs.data[i];//This is the hard copying part

            }
        }
        return *this;
    }

    std::string &stringVector::operator[](unsigned position)const  { //Test Passed

        if (position >= allocated_length) { // out of scope
            throw 0;
        }//std::out_of_range does not work for the throw statement
        return data[position];//returns the reference to the string at this position
        //return ;
    }

    void stringVector::sort() {//Test passed

        for(int x = (length -1); x>0; x--){ // Googled bubble algorithm sorting i'll be honest I referenced a lot of this function to an online algorithm site
            for (int y=0; y<x; y++){ // start at length -1 and decrement because thats the allocated size for the next for loop
                if (data [y].compare(data[y+1])>0){
                  swap(unsigned(y),unsigned (y+1));//Uses the swap function
                }
            }
        }

    }
    void stringVector::set_size(unsigned new_size){
        length = new_size;
        if(allocated_length != new_size) {
            reserve(new_size);
        }

    }
}

