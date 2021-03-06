#ifndef CMPE126S18_LABS_QUEUE_H4
#define CMPE126S18_LABS_QUEUE_H4
#include "stringVector.h"


namespace lab3 {
    class fifo {
        lab2::stringVector Fifo_storage;
        unsigned front_index;
        unsigned back_index;

    public:
        fifo();                                          //Default constructor. Reserve 100 spaces in lifo_storage
        explicit fifo(std::string input_string);        //Create new fifo from string input
        fifo(const fifo &original);                     //Copy constructor
        virtual ~fifo();                                //Destructor
        fifo &operator=(const fifo &right);            //Assignment operator

        bool is_empty() const;  // Return true if the fifo is empty and false if it is not
        unsigned size() const;  // Return the size of the fifo

        std::string top() const;           // Return the front string of the fifo.
        void enqueue(std::string input);   // Add input string to the back of the fifo
        void dequeue();                    // Remove the front string from the fifo
    };
}

#endif
