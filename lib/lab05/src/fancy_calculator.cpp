#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"

namespace lab5{
    bool is_number(std::string input_string);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in);
        void calculator::parse_to_infix(std::string &input_expression) {
            int size = 0;
            std::string TempArr[input_expression.size()];
            for(std::string::iterator it = input_expression.begin(); it != input_expression.end(); ++it) {
                TempArr[size] = *it;
                size++;
            }

            for(int i=0; i<size; i++){ // for loop

                if(TempArr[i] == " "){      //this will get rid of white spaces
                    i++;
                }

                else if(!is_number(TempArr[i])){
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
    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        lab5::stack stack;
        std::string current_token;
        while (!infix_expression.isEmpty()) {
            current_token = infix_expression.top();
            infix_expression.dequeue();
            if (is_number(current_token)) {
                postfix_expression.enqueue(current_token);
            }
            if (is_operator(current_token)) {
                while (!stack.isEmpty() && operator_priority(current_token) <= operator_priority(stack.top()) && stack.top() != "(" ) {
                    postfix_expression.enqueue(stack.top());// If the stack isn't empty it must check the priority
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
            }
        while (!stack.isEmpty()) {     //makes sure the stack gets empty before the end of the whole conversion
                if (stack.top() == "(") {
                    stack.pop();
                }
                postfix_expression.enqueue(stack.top());
                stack.pop();
            }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix( input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string temp= "";
        lab5::queue infix_expression;
        while(stream.peek()!= EOF){
            temp = stream.get();
        }
        RHS.parse_to_infix(temp);
        RHS.convert_to_postfix(infix_expression);
        return stream; //store an expression from stdio
    }

    int calculator::calculate() {
        int answ =0;
        int calc =0;
        lab5::stack final_stack;
        lab5::queue postfixCopy;
        postfixCopy = postfix_expression;
        while(!postfixCopy.isEmpty()) {
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
                if(tempOP == "^"){
                    int temp3 = 1;
                    if(temp1 == 0){
                        std::string hi = std::to_string(temp3);
                        final_stack.push(hi);
                    }
                    for(int i=1; i<=temp1;i++){
                        temp3 *= temp2;
                    }
                    calc = temp3;
                    std::string hi = std::to_string(calc);
                    final_stack.push(hi);
                }
               else if(tempOP == "%"){
                    calc = temp2 % temp1;
                    std::string hi =  std::to_string(calc);
                    final_stack.push(hi);
                }
               else if (tempOP == "/") {
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
        unsigned infixSize = RHS.infix_expression.queueSize();
        unsigned postfixSize = RHS.postfix_expression.queueSize();
        stream << std::string("Infix: ");
        for (int i = 0; i < infixSize; i++) {
            stream << RHS.infix_expression.top();
            stream << std::string(", ");
            RHS.infix_expression.dequeue();
        }
        stream << std::string("\n");
        stream << std::string("Postfix: ");
        for (int i = 0; i < postfixSize; i++) {
            stream << RHS.postfix_expression.top();
            stream << std::string(", ");
            RHS.postfix_expression.dequeue();
        }
        stream << std::string("\n");
        return stream;
    }



    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string) {
        if (input_string >= "0" || input_string <= "999") {
            if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "(" || input_string == ")"|| input_string == "^"|| input_string == "%") {
                return false;
            }
            return true;
        }
        return false;
    }
    bool is_operator(std::string input_string){
        if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "^"|| input_string == "%") {
            return true;
        }
        return false;
    }
    int operator_priority(std::string operator_in){
        int priority;
        if(operator_in=="+"||operator_in == "-"){
            priority=1;
        }
        else if (operator_in=="*"||operator_in == "/"||operator_in == "%") {
            priority = 2;

        }
        else if(operator_in== "^"){
            priority = 3;
        }
        return priority;
    }

    std::string get_operator(std::string input_string);


}

