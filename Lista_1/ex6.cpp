#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 


void ex6(int a, int b, int c){
    if (int d = (b * b) - (4 * a * c); d < 0) {
        std::cout<<"no roots\n";
        return;
    }
    else if (d == 0) {
        std::cout<<(-b/(2*a))<<"\n";
        return;
    }
    else{
    std::cout<<((-b + sqrt(d))/(2*a))<<" "<<((-b - sqrt(d))/(2*a))<<"\n";
    }
}

int main() {
    ex6(1, 0, 0);
    ex6(1, -1, 0);
    ex6(1, 0, -1);
}