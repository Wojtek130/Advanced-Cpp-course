#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

int main() {
        // ex2 - raw strings: characters inside the string are not interpreted
    std::cout<< R"(Instytut Informatyki Uniwersytetu Wrocławskiego)"<<"\n";
    std::cout<< R"(ul. Joliot-Curie 15)"<<"\n";
    std::cout<< R"(50-383 Wrocław)"<<"\n";
    std::cout<< R"("C:\Program Files")"<<"\n"; //? - right path?
    std::cout<< R"+*((("("())")))+*"<<"\n"; // ") enabled throgu R"+*(i)+*"
}