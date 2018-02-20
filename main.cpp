#include <iostream>
#include <stringVector.h>

int main() {
 lab2::stringVector ex;
ex.append(std::string("Testring TeString"));
    std::cout<<ex[0]<<std::endl;
    ex.append(std::string("another one"));
    std::cout<<ex[1]<<std::endl;


    return 0;
}