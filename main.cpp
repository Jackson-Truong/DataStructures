#include <iostream>
#include <stringVector.h>

int main() {
 lab2::stringVector sample;
sample.append(std::string("Example String"));
    std::cout<<sample[0]<<std::endl;

    return 0;
}