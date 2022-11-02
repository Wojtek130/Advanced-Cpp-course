#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

template<typename T>
using stringSet = std::set<std::basic_string<T>>;

int main() {
    stringSet<char> s{"aaa", "bbb"};
    for (auto& e : s) {
        std::cout<<e<<"\n";
    }
}