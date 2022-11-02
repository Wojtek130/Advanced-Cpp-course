#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

enum class Names : uint16_t { Tom, Ben, Mary, Jane};


void ex4(std::string msg, Names n) {
    int a = 0;
    switch (n)
    {
    case Names::Tom:
        a = 2;
        break;
    case Names::Ben:
        a = 3;
        break;
    case Names::Mary:
        a = 4;
        break;
    case Names::Jane:
        a = 5;
        break;

    }
    std::cout<<msg<<" You have "<<a<<" apples."<<"\n";
}

int main() {
    ex4("Hello", Names::Tom);
    ex4("Hi", Names::Mary);
}