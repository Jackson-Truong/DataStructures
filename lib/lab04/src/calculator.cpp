

#include <string>
#include "calculator.h"
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        char tempo[input_expression.size()];
 input_expression.std::copy(tempo,input_expression.size());
input_expression = tempo[input_expression.size()];
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
//Uses lifo
        //std::string::iterator position=input_expression.begin()
    }

    calculator::calculator() {
calculator::calculator()= default;
    }

    calculator::calculator(std::string &input_expression) {
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
               lab3::fifo enqueue(input_string);//gotta do lifo/fifo here
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

                lab3::lifo push(input_string);
            }
             else if(is_number){
                std::string get_number(std::string input_string);
            }
            else{
                throw "ERROR: NOT OPERATOR OR NUMBER ";
            }
        }
//in convert to postfix

    int operator_priority(std::string operator_in){
        int tier;
        if(operator_in == "("||")"){
            tier = 1;
        }
        if(operator_in == "^"){
            tier =2;
        }
        if(operator_in == "+"|| "-"){
            tier = 3;
        }
        if(operator_in == "*"|| "/"){
            tier =4;
        }
        return tier;
    }
    //in convert to postfix
}