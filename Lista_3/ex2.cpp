#include <iostream>
#include <climits>
#include <cmath>


int main() {
    std::cout<<std::numeric_limits<float>::min()<<std::endl;
    std::cout<<std::numeric_limits<double>::min()<<std::endl;
    std::cout<<std::numeric_limits<float>::max()<<std::endl;
    std::cout<<std::numeric_limits<double>::max()<<std::endl;
    std::cout<<std::numeric_limits<float>::epsilon()<<std::endl;
    std::cout<<std::numeric_limits<double>::epsilon()<<std::endl;
    // https://en.cppreference.com/w/cpp/types/numeric_limits

}

//value stored on 63 bits, 1 bit for the sign