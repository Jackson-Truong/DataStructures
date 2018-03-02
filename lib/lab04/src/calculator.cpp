

#include <string>
#include "calculator.h"
#include <iostream>

namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);
        int size = input_expression.size();
        int counter = 0;
        while (counter < size) {
            stream.get_next_token();
          infix_expression.enqueue(stream.get_current_token());
            counter++;
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if (is_number(current_token) == true) {
                postfix_expression.enqueue(current_token);
            }
            if (is_operator(current_token)) {
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) && stack.top() != "(") {
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
                    stack.pop();
            }
        }         while (!stack.is_empty()) {// this area
                if(stack.top() == "(" ){
                    stack.pop();
                }
                std::string temp = stack.top();
            postfix_expression.enqueue(temp);
            stack.pop();
            }
        }

    calculator::calculator() { //constructor

    }

    calculator::calculator(std::string & input_expression) { //This should just call two functions
parse_to_infix( input_expression);
convert_to_postfix(infix_expression);
    }
//Can turn the istream into a string then call the functions that you already wrote
//documentation for stream operator
    std::istream &operator>>(std::istream &stream, calculator &RHS) {
         std::string input;
        while(stream.peek()!= EOF){

         }
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream; //store an expression from stdio
    }

    int lab4::calculator::calculate() {
        int answ =0;
        int calc =0;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        lab3::lifo final_stack;
        while(!postfix_expression.is_empty()) {
            if (is_number(postfix_expression.top())) {
                final_stack.push(postfix_expression.top());
                postfix_expression.dequeue();
            }
            else if (is_operator(postfix_expression.top())) {
                std::string tempOP = postfix_expression.top();
                postfix_expression.dequeue();
                int temp1 = std::stoi(final_stack.top());
                final_stack.pop();
                int temp2 = std::stoi(final_stack.top());
                final_stack.pop();
                if (tempOP == "/") {
                    calc = temp2 / temp1;
                    std::string hi = std::to_string(calc);
                    final_stack.push(hi);
                }
                else if (tempOP == "*"){
                    calc = temp2 * temp1;
                    std::string hi = std::to_string(calc);
                    final_stack.push(hi);
                }
                else if(tempOP == "+"){
                    calc = temp2 + temp1;
                    std::string hi = std::to_string(calc);
                    final_stack.push(hi);
                }
                else if(tempOP == "-"){
                    calc = temp2 - temp1;
                    std::string hi = std::to_string(calc);
                    final_stack.push(hi);
                }
            }
        }
        answ = std::stoi(final_stack.top());
        return answ;
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
            if(input_string == "+"||input_string == "-"||input_string == "*"||input_string == "/"){
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