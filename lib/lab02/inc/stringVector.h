
#ifndef CMPE126S18_LABS_STRINGVECTOR_H
#define CMPE126S18_LABS_STRINGVECTOR_H

#include <string>

namespace lab2 {
    class stringVector {
    private:
        std::string *data;
        unsigned length;
        unsigned allocated_length;
        bool isValidPosition(unsigned pos1);

    public:
        stringVector();
        virtual ~stringVector();
        unsigned size()const;
        unsigned capacity()const;
        void reserve(unsigned new_size);
        bool empty()const;
        void append(std::string new_data);
        void swap(unsigned pos1, unsigned pos2);
        stringVector &operator=(stringVector const &rhs);
        std::string &operator[](unsigned position) const;
        void sort();
        void set_size(unsigned new_size);
    };
}

#endif //CMPE126S18_LABS_STRINGVECTOR_H
