#include "../inc/stringVector.h"
#include <stdexcept>
namespace lab2 {
    stringVector::stringVector() { //Test Passed

        data = nullptr;
        length = 0;
        allocated_length = 0;
    }

    stringVector::~stringVector() { //Test Passed
        delete[] data;
    }

    unsigned stringVector::size() const { //Test Passed
        return length;
        //return ;
    }

    unsigned stringVector::capacity() const { //Test Passed
        return allocated_length;
        //return ;
    }
    void stringVector::reserve(unsigned new_size) { //Test Passed
       auto *fixArr = new std::string[new_size];
        if(length>new_size){
            length =new_size;
        }
            for (int i = 0; i < new_size && i < length; i++) {
                fixArr[i] = data[i];
            }
        allocated_length = new_size;
        delete[]data;
        data = fixArr; // Tried to do delete []fixArr but I got errors, this one works but I do not know why. ask for explanation in class.
    }

    bool stringVector::empty() const { //Test passed
        if (length == 0) { // I tried data!= NULL but there is something in the code, not sure why.
            return true;
        }
        return false;
        //return ;
    }

            void stringVector::append(std::string new_data) { //Test Passed //Might need a pointer because of the test fail in another test
        if (allocated_length == 0) {
            this->reserve(1);
            this->append(new_data);
        } else if (length == allocated_length) {
            this->reserve(allocated_length * 2);
            this->append(new_data);
        }
            data[length] = new_data;
            length++;
        return;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        if ((pos1 > length) || (pos2 > length)) {
            throw 0;
        } else {
            std::string tmp = data[pos1];
            data[pos1] = data[pos2];
            data[pos2] = tmp;
        }
    }

    stringVector &stringVector::operator=(stringVector const &rhs) { //Test Passed

        if (&rhs == this) {
            return (*this);
        } else {
            delete[] data;
            length = rhs.length;
            allocated_length = rhs.allocated_length;
            this->data = new std::string[allocated_length];
            for (int i = 0; i < length; i++) {
                this->data[i] = rhs.data[i];

            }

        }
    }

    std::string &stringVector::operator[](unsigned position) { //Test Passed
        if (position >= allocated_length) { // out of scope
            throw 0;
        }//std::out_of_range
        return data[position];
        //return ;
    }

    void stringVector::sort() {
        std::string str;
        for(int k = (length -1); k>0; k--){
            for (int j=0; j<k; j++){
                if (data [j].compare(data[j+1])>0){
                    str=data[j];
                    data[j] = data[j+1];
                    data[j+1] = str;
                }
            }
        }
    }
}
