

#include <string>
#include "calculator.h"
#include <iostream>

namespace lab4 {
    bool is_number(std::string input_string);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in);
    void calculator::parse_to_infix(std::string &input_expression) {
        int size = 0;
        std::string TempArr[input_expression.size()];
        std::string white;
        for(std::string::iterator it = input_expression.begin(); it != input_expression.end(); ++it) {
            white = *it;
            TempArr[size] = *it;
            size++;
            if(white == " "){      //this will get rid of white spaces
    size--;
            }
        }

        for(int i=0; i<size; i++){ // for loop

            if(!is_number(TempArr[i])){
                infix_expression.enqueue(TempArr[i]);
            }
            else {
                int j= i;
                if(is_number(TempArr[i+1])){
                    std::string concatenate;
                    while(j<size && is_number(TempArr[j])){
                        concatenate+=TempArr[j];
                        j++;
                    }
                    infix_expression.enqueue(concatenate);
                    i= j-1;
                }
                else{
                    infix_expression.enqueue(TempArr[i]);
                }
            }
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {      //infix_expression is already a copy, so we can change it
        lab3::lifo stack;
        std::string current_token;
        while (!infix_expression.is_empty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();

            if (is_number(current_token)){
                postfix_expression.enqueue(current_token);
            }

            if (is_operator(current_token)){
                while (!stack.is_empty() && operator_priority(current_token) <= operator_priority(stack.top()) && stack.top() != "(") {
                    postfix_expression.enqueue(stack.top());// If the stack isn't empty it must check the priority
                    stack.pop();
                }
                stack.push(current_token);
            }
            if (current_token == "(") { //Must automatically push this inside
                stack.push(current_token);
            }

            if (current_token == ")") { // This will enqueue everything until it reaches the "("
                while (stack.top() != "(") {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
        }

        while (!stack.is_empty()) {     //makes sure the stack gets empty before the end of the whole conversion
            if(stack.top()=="(") {
                stack.pop();
            }
            postfix_expression.enqueue(stack.top());
            stack.pop();
        }
    }

    calculator::calculator() { //constructor
    }

    calculator::calculator(std::string & input_expression) { //This should just call two functions
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }
//Can turn the istream into a string then call the functions that you already wrote
//documentation for stream operator

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string temp= "";
        while(!RHS.infix_expression.is_empty())RHS.infix_expression.dequeue();
        while(!RHS.postfix_expression.is_empty())RHS.postfix_expression.dequeue();
        while(stream.peek()!= EOF){
            temp += stream.get();
        }

        RHS.parse_to_infix(temp);
        RHS.convert_to_postfix(RHS.infix_expression);

        return stream; //store an expression from stdio
    }

    int lab4::calculator::calculate() {
        int answ =0;
        int calc =0;
        lab3::lifo final_stack;
        lab3::fifo postfixCopy;
        postfixCopy = postfix_expression;
        while(!postfixCopy.is_empty()) {
            if (is_number(postfixCopy.top())) {
                final_stack.push(postfixCopy.top()); // I use another lifo to stack the operators
                postfixCopy.dequeue();
            }
            else if (is_operator(postfixCopy.top())) {
                std::string tempOP = postfixCopy.top();
                postfixCopy.dequeue();
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
        unsigned infixSize = RHS.infix_expression.size();
        unsigned postfixSize = RHS.postfix_expression.size();
        lab3::fifo infix_copy;
        lab3::fifo postfix_copy;
        infix_copy = RHS.infix_expression;
        postfix_copy = RHS.postfix_expression;
        stream << std::string("Infix: ");
        for (int i = 0; i < infixSize; i++) {
            stream <<infix_copy.top();
            infix_copy.dequeue();
            if(i<infixSize-1){
                stream << std::string(",");
            }
        }
        stream << std::string("\n");
        stream << std::string("Postfix: ");
        for (int i = 0; i < postfixSize; i++) {
            stream << postfix_copy.top();
            postfix_copy.dequeue();
            if(i<postfixSize-1){
                stream << std::string(",");
            }

        }
        return stream;
    }

    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string) {
        if (input_string >= "0" && input_string <= "999999") {
            if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "(" || input_string == ")") {
                return false;
            }
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
    int operator_priority(std::string operator_in){
        int priority;
        if(operator_in=="+"||operator_in=="-"){
            priority=1;
        }
        else if (operator_in=="*"||operator_in=="/") {
            priority = 2;

        }
        else if(operator_in== "^"){
            priority = 3;
        }
        return priority;
    }
}


