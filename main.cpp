#include <iostream>
#include <stringVector.h>
int main() {
 stringVector sample;
sample.append(std::string("Example String"));
    std::cout<<sample[0]<<std::endl;
    sample.append(std::string("another Example"));
    std::cout<<sample[1]<<std::endl;
    return 0;
}