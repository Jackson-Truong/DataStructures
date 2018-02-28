

#include <string>
#include "calculator.h"
#include <iostream>

namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);
        int size = input_expression.size();
        for(int i=0 ; i<size; i++){
                infix_expression.enqueue(stream.get_current_token());
                stream.get_next_token();//Might not work because these enqeueue unsigned ints
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {      //infix_expression is already a copy, so we ca change it
        lab3::lifo stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if (is_number(current_token)) {
                postfix_expression.enqueue(current_token);
            }
            if (is_operator(current_token)) {
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) &&
                       current_token != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.push(current_token);
            }
            if (current_token == "(") {
                stack.push(current_token);
            }

            if (current_token == ")") {
                while (stack.top() != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
            }
        }

        while (!stack.is_empty()) {
            postfix_expression.enqueue(current_token);
        }
    }
    calculator::calculator() { // Just made some bool statements
infix_expression.is_empty();
        postfix_expression.is_empty();
    }

    calculator::calculator(std::string & input_expression) { //This should just call two functions
parse_to_infix( input_expression);
convert_to_postfix(infix_expression);
        calculate();
    }
//Can turn the istream into a string then call the functions that you already wrote
//documentation for stream operator
    std::istream &operator>>(std::istream &stream, calculator &RHS) {

      //RHS.parse_to_infix(RHS.&stream);
        RHS.convert_to_postfix(RHS.infix_expression);

        return stream; //store an expression from stdio
    }

    int lab4::calculator::calculate() {
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int size = postfix_expression.size();
        std::string temp[size];
        lab3::fifo final_calc;
        postfix_expression.dequeue();
        for (int i = 1; i <= size-1; i++) {
            temp[i] = postfix_expression.top();
            if (!is_operator(temp[i])) {
                final_calc.enqueue(temp[i]);
                postfix_expression.dequeue();
            }
            else {
                std::string temp_t = final_calc.top();
                int temp1 = std::stoi(temp_t); // Debug doesnt' pass through this.
                final_calc.dequeue();// WORK ON THIS LINE
                std::string temp_OP = postfix_expression.top();
                final_calc.enqueue(temp_OP);
                postfix_expression.dequeue();
                std::string temp_t2 = postfix_expression.top(); //returns ""

                int temp2 = std::stoi(temp_t2);
                if (temp_OP == "/") {
                    int answ = temp1/temp2;
                    return  answ;
                }
            }


            /*            if (is_number(temp[i])) {
                int temp2 = std::stoi(final_calc.top());

            }
             */
        }
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
lab3::fifo infix_expression = RHS.infix_expression;
        lab3::fifo postfix_expression = RHS.postfix_expression;
        stream <<RHS; // When i try to do stream.RHS I get an error stating Binary operator << can't be applied to expressions of type std::ostream and lab3::fifo, so i kept it as what it is right now
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

    int get_number(std::string input_string);
// convert to postfix

    std::string get_operator(std::string input_string);
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