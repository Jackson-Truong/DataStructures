

#include <string>
#include "calculator.h"
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
lab1::expressionstream stream(input_expression);
        int counter =0;
        while(counter<input_expression.size()){
            while (stream.get_current_token() != "\0") {
                stream.get_next_token();
                infix_expression.enqueue(stream.get_current_token()); //Might not work because these enqeueue unsigned ints
             ++counter;
            }
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
//Uses lifo for operators
        //std::string::iterator position=input_expression.begin()
        // tiers, maybe a while loop instead of a for loop that decremeents
        lab3::lifo op_stack;
        int size = infix_expression.size();
        std::string temp[size];
        for (int i = 0; i <= size; i++) {
            temp[i] = infix_expression.top();
            infix_expression.dequeue();
        }
        int counter =0;
        lab1::expressionstream post(temp[size]);
        while(counter <= size) {
            if (post.next_token_is_int()) {
                postfix_expression.enqueue(temp[counter]); // 1+2 postfix enqueues 1 then op push +  postfix enqueues 2 then somehow get 12 together and + after it
            }
            if (post.next_token_is_op()) {
                if (op_stack.is_empty()) {
                    op_stack.push(temp[counter]);
                }
                std::string tempOP = op_stack.top();
                int operator_priority(std::string operator_in);
                if (operator_priority(op_stack.top()) >= operator_priority(temp[counter])) {
                    while (!op_stack.is_empty()) {
                        postfix_expression.enqueue(op_stack.top());
                        op_stack.pop();
                    }
                }
                else if(operator_priority(op_stack.top())<= operator_priority(temp[counter])){
                        op_stack.push(temp[counter]);
                    }
                 else if (post.next_token_is_paren_open()) { //First parathesis this is priority
                    op_stack.push(temp[counter]);
                } else if (post.next_token_is_paren_close()) {
                    while (op_stack.top() != ")") {
                        while (!op_stack.is_empty()) {
                            postfix_expression.enqueue(op_stack.top());
                            op_stack.pop();
                        }
                    }
                }
            }
                post.get_next_token(); // itll never get a null because counter = size at the end
                ++counter;
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) { //This should just call two functions
parse_to_infix(input_expression);
convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream; //store an expression from stdio
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
            if(input_string =="0"||input_string =="1"||input_string =="2"||input_string =="3"||input_string =="4"||input_string =="5"||input_string =="6"||input_string =="7"||input_string =="8"||input_string =="9"){
                return true;
            }
            return false;

    }
    bool is_operator(std::string input_string){
            if(input_string == "+"||input_string == "-"||input_string == "*"||input_string == "/"||input_string == "("||input_string ==")"||input_string =="^"){
                return true;
            }
            return false;
        }
// conver to postfix

    int get_number(std::string input_string){
            if(is_number){
// Not done but I did not use this function
            }
            else if (is_operator){
                std::string get_operator(std::string input_string);
            }
        else {
                throw"ERROR: NOT OPERATOR OR NUMBER";
            }
        }
// convert to postfix

    std::string get_operator(std::string input_string){
        if(is_operator){
return input_string;
// Not done but i did not use this function
            }
             else if(is_number){

            }
            else{
                throw "ERROR: NOT OPERATOR OR NUMBER ";
            }
        }
//in convert to postfix

    int operator_priority(std::string operator_in){ // Slack said that we did not have to use "^" in this project
        if(operator_in == "*"|| "/"){
           return 2; // Separate the PEMDAS tier ignoring P and E
        }
        if(operator_in == "+"|| "-"){
         return 1;
        }

    }
    //in convert to postfix
    // )5+3 +(4+3)
}
// ITS GOING TO BE expressionstream then do auxillary if it passes the certain expressionstream boolean statement