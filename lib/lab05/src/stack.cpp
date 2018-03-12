#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {

    }

    stack::stack(const stack &original) {

    }

    stack::~stack() {

    }

    stack &stack::operator=(const stack &RHS) {
        //return <#initializer#>;
    }

    bool stack::isEmpty() const {
        return false;
    }

    unsigned stack::queueSize() const {
        return 0;
    }

    std::string stack::top() const {
        if(storage_structure.isEmpty()){
            return 0;
        }
        return storage_structure.get_value_at(storage_structure.listSize()-1);
    }

    void stack::push(const std::string &data) {

    }

    void stack::pop() {

    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}