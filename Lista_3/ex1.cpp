#include <iostream>
#include <climits>
#include <cmath>


int main() {
    std::cout<<LLONG_MAX<<" "<<LLONG_MIN<<std::endl;
    std::cout<<std::numeric_limits<long long int>::max()<<" "<<std::numeric_limits<long long int>::min()<<std::endl;
    std::cout<<log2(LLONG_MAX)<<std::endl;
    std::cout<<std::numeric_limits<long long int>::digits<<std::endl;
    std::cout<<std::numeric_limits<long long int>::digits10<<std::endl;
}

//value stored on 63 bits, 1 bit for the sign