#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {
storage_structure.append(data);
    }

    stack::stack(const stack &original) {
        stack temporary;
        temporary= original;
        for (int i = 0; i < original.queueSize(); i++) {
            storage_structure.append(temporary.top());
            temporary.pop();
        }
    }

    stack::~stack() {
        for(unsigned i=storage_structure.listSize()-1; i<=0;i--){
            storage_structure.remove(i);
        }
    }

    stack &stack::operator=(const stack &RHS) {
        for(int i=0;i<RHS.queueSize(); i++){
            this->storage_structure.append(RHS.storage_structure.get_value_at(i));
        }
        return *this;
    }

    bool stack::isEmpty() const {
        if(storage_structure.isEmpty()){
            return true;
        }
        return false;
    }

    unsigned stack::queueSize() const {
        return storage_structure.listSize();
    }

    std::string stack::top() const {
        if(storage_structure.isEmpty()){
            return 0;
        }
        return storage_structure.get_value_at(storage_structure.listSize()-1);
    }

    void stack::push(const std::string &data) {
storage_structure.append(data);
    }

    void stack::pop() {
storage_structure.remove(storage_structure.listSize()-1);
    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        stream<<"Queue:";
        for(unsigned i=RHS.storage_structure.listSize()-1; i<=0;i--){
            stream<< RHS.storage_structure.get_value_at(i);
            stream<<", ";
        }
        if(RHS.storage_structure.isEmpty()){
            throw 0;
        }
        return stream;
    }
    std::istream& operator>>(std::istream &stream, stack &RHS) {
        std::string temporary;
        getline(stream, temporary);
        RHS.storage_structure.append(temporary);
        return stream;
    }
}