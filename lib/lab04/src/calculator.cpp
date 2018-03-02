

#include <string>
#include "calculator.h"
#include <iostream>

namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);// This is to call lab 1
        int size = input_expression.size();//Once you call it I made a size just for the while loop ahead
        int counter = 0;
        while (counter < size) {
            stream.get_next_token();
          infix_expression.enqueue(stream.get_current_token());// enqueues and grabs next tokens
            counter++;
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo stack;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        std::string current_token;
        while (!infix_expression.is_empty()) { // This makes sure that the infix_expression is not empty, so it can convert all of the elems in postfix
            current_token = infix_expression.top(); // This will show what is going on
            infix_expression.dequeue();// dequeue to move over
            if (is_number(current_token) == true) { // uses current token
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
                    stack.pop(); // Pops everything until it reaches the (, then it will pop the top, which will be (
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
std::string input_express;
        while(stream.peek()!= EOF){
std::getline(stream, input_express);
         }
         RHS.parse_to_infix(input_express);
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
                final_stack.push(postfix_expression.top()); // I use another lifo to stack the operators
                postfix_expression.dequeue();
            }
            else if (is_operator(postfix_expression.top())) {
                std::string tempOP = postfix_expression.top();
                postfix_expression.dequeue();
                int temp1 = std::stoi(final_stack.top());// SHould pop two operators to calculate
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
        return stream << "Infix" << RHS.infix_expression <<  "\nPostfix "<< RHS.postfix_expression;
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
}
