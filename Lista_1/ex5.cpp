#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

auto ex5(uint32_t n) {
    if (n == 0)
    {
        return 2;
    }
    if (n == 1)
    {
        return 1;
    }
    return ex5(n-1) + ex5(n-2);
}

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout<<ex5(i)<<"\n";
    }
}