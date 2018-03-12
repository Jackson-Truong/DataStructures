#include "queue.h"
namespace lab5{
    queue::queue() {
    }

    queue::queue(std::string &data) {
    storage_structure.append(data);
    }

    queue::queue(const queue &original) {
        queue temporary = original;
        for (int i = 0; i < original.queueSize(); i++) {
            storage_structure.append(temporary.top());
            temporary.dequeue();
        }
    }

    queue::~queue() {
        for(unsigned i=0; i<storage_structure.listSize();i++){
            storage_structure.remove(i);
        }
    }

    queue &queue::operator=(const queue &RHS) {
        for(int i=0;i<storage_structure.listSize(); i++){
            this->storage_structure.append(RHS.storage_structure.get_value_at(i));
        }
    }

    bool queue::isEmpty() const {
        if(storage_structure.isEmpty()){
            return true;
        }
        return false;
    }

    unsigned queue::queueSize() const {
            return storage_structure.listSize();
    }

    std::string queue::top() const {
if(storage_structure.isEmpty()){
    return 0;
}
        return storage_structure.get_value_at(0);

    }

    void queue::enqueue(const std::string &data) {
storage_structure.append(data);
    }

    void queue::dequeue() {
storage_structure.remove(0);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        stream<<"Queue:";
        for(int i=0; i<RHS.storage_structure.listSize(); i++){
            stream<< RHS.storage_structure.get_value_at(i);
            stream<<", ";
        }
        if(RHS.storage_structure.isEmpty()){
          throw 0;
      }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        std::string temporary;
        getline(stream, temporary);
        RHS.storage_structure.append(temporary);
        return stream;
    }
}
