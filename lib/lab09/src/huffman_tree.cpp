#include "../inc/huffman_tree.h"

namespace lab9{
    node *huffman_tree::remove() {
        node *hello = priority_head;
        if(hello==nullptr){
            throw"ERROR, can not remove an empty tree";
        }
        if(hello->next == nullptr){
            priority_head = nullptr;
            priority_tail = nullptr;
            return hello;
        }
        priority_head = priority_head->next;
        priority_head->prev = nullptr;
        // TODO: Write function that removes the first node form the priority queue and returns it
        return hello;
    }

    huffman_tree::huffman_tree() {
        root = nullptr;
        priority_head = nullptr;
        priority_tail = nullptr;
    }

    huffman_tree::huffman_tree(std::string &dict_string_from_file) {
        // Constructor that parses in the huffman dictionary from the file and creates the tree

        // State machine variable declarations
        const int default_state = 0, character_state = 1, tree_state = 2;
        int state = default_state;
        bool first_quote = false, second_quote = false;
        char key = 0;

        // Create our current node* and set it to root which is nullptr
        node* current = root;
        for(char c: dict_string_from_file) {
            switch(state) {
                case character_state:
                    switch (c) {
                        case '\'': {
                            if (!first_quote) first_quote = true;
                            else if (!second_quote) second_quote = true;
                            else key = c;
                        }
                            break;
                        case ':': {
                            if (first_quote && second_quote) {
                                state = tree_state;
                                first_quote = false;
                                second_quote = false;
                            } else key = c;
                        }
                            break;
                        default:
                            key = c;
                            break;
                    }
                    break;
                case tree_state:
                    switch (c) {
                        case ',': {
                            current->set(key);
                            current = root;
                            state = default_state;
                        }
                            break;
                        case '0': {
                            if (current->left == nullptr) current->left = new node('\0');
                            current = current->left;
                        }
                            break;
                        case '1': {
                            if (current->right == nullptr) current->right = new node('\0');
                            current = current->right;
                        }
                            break;
                        default:
                            return;
                    }
                    break;
                default:
                    if (c == '\'') {
                        state = character_state;
                        first_quote = true;
                    }
                    break;
            }
        }
        current->set(key);
    }

    huffman_tree::~huffman_tree() {
        // TODO: Write the destructor. Make sure to clear out both the priority queue and the tree
    }

    void huffman_tree::add(char character) {
        node *add = new node(character);
        node *hello = priority_head; // This is to see if there is the same character already in this
        while (hello != nullptr) {
            if (add->get_character() == hello->get_character()) {
                delete[]add;
                hello->increment_frequency(); //Change the order of the queue after
                if(hello->next) {
                    if (hello->get_frequency() >= hello->next->get_frequency()) {//swap
                        node*prev = hello->prev;
                        node*next = hello->next->next;
                        hello->next=next;
                        hello->prev = hello->next;
                        hello->next->next=hello;
                        hello->next->prev=prev;
                        prev->next = hello->next;
                    }
                    else if(hello->get_frequency()<hello->next->get_frequency()){
                        hello = hello->next;
                    }
                }
                return;
            }
            hello = hello->next;
        }
        node *queue = priority_head; //This is to fix the queue
        if (add->get_frequency() <= queue->get_frequency()) {
            add->next = queue;
            queue->prev = add;
            priority_head = add;
        } else if (add->get_frequency() > queue->get_frequency()) {
            while (queue-> next!= nullptr) {
                if (add->get_frequency() > queue->get_frequency()) {
                    queue = queue->next;
                } else if (add->get_frequency() <= queue->get_frequency()) {//order should not matter if they have the same frequency, which is why i added the = in <=
                    node *prev = queue->prev;
                    prev->next = add;
                    add->prev = prev;
                    add->next = queue;
                    queue->prev = add;
                }
            }
            priority_tail = add;
            queue->next = add;
            add->prev = hello;
            add->next = nullptr;
        }
        // TODO: Add the character to the priority queue, increasing the frequency if needed
    }

    void huffman_tree::generate_tree() {
        node* generated_tree = nullptr;
        while(priority_head !=nullptr && priority_head->next !=nullptr) {
            node *first = this->remove();
            node *second = this->remove();
           node combined = node(first, second);


        }
        if(priority_head!=nullptr &&priority_head->next ==nullptr){//Odd number in the queue, which means we will have one more node left over.

        }
        // TODO: Generate the tree from the priority queue
    }

    node *huffman_tree::get_root() {
        // So complicated
        return root;
    }

    bool huffman_tree::valid_tree() {
        if(priority_head==nullptr && root!=nullptr){
            return true;
        }
        return false;
        // TODO: Check to see if priority_head is null and root isn't
    }
}
