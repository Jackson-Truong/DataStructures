#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"

namespace lab5{
    bool is_number(std::string input_string);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in);
    void calculator::parse_to_infix(std::string &input_expression) {
        int size = 0;
        int Operate = 0;
        int infix = 0;
        std::string TempArr[input_expression.size()];
        for(std::string::iterator it = input_expression.begin(); it != input_expression.end(); ++it) {
            TempArr[size] = *it;
            size++;
        }

        for(int i=0; i<size; i++){ // for loop

            if(TempArr[i] == " "){      //this will get rid of white spaces
                i++;
            }

            else if(i==size-1){
                infix_expression.enqueue(TempArr[i]);
                infix++;
            }

            if(i!= size-1 && !is_number(TempArr[i])){ //enqueues operators
                infix_expression.enqueue(TempArr[i]);
                infix++;
            }

            if(i!=size-1 && is_number(TempArr[i]) && !is_number(TempArr[i+1]) ){  //checks the next element in the array, if they are not both numbers then it will enqueue the ith element
                infix_expression.enqueue(TempArr[i]);
                infix++;
            }

            if(i!=size-1 && is_number(TempArr[i]) && is_number(TempArr[i+1])){    //Operate will find where the operators are inside of the input_expression
                Operate=i;
                if(Operate == size-2){
                    Operate=Operate+2;
                }
                if(Operate == size-3){
                    Operate=Operate+3;
                }
                if(Operate != size) {
                    while (Operate != size - 1 && is_number(TempArr[Operate])) {      //position of operator
                        Operate++;
                    }// For some reason ) is giving me a number so i changed my bool is_number statement
                }
                std::string int_temp;
                for(int z=i; z < Operate; z++){
                    int_temp += TempArr[i++];      //concatenates all of the numbers there until it reaches operate
                }
                i = Operate-1;
                infix_expression.enqueue(int_temp);
                infix++;
            }
        }
    }
    void calculator::convert_to_postfix(lab5::queue infix_expression) {

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
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
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
        if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "(" || input_string == ")"|| input_string == "^"|| input_string == "%") {
            return true;
        }
        return false;
    }
    int operator_priority(std::string operator_in){
        int priority;
        if(operator_in=="+"||operator_in=="-"){
            priority=1;
        }
        else if (operator_in=="*"||operator_in=="/"||operator_in == "%") {
            priority = 2;

        }
        else if(operator_in== "^"){
            priority = 3;
        }
        return priority;
    }

    std::string get_operator(std::string input_string);


}

