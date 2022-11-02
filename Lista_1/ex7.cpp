#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

void ex7(std::tm d) {
    std::string m;
    switch (auto month = d.tm_mon; month)
    {
    case 0:
        m = "January";
        break;
    case 1:
        m = "February";
        break;
    case 2:
        m = "March";
        break;
    case 3:
        m = "April";
        break;
    case 4:
        m = "May";
        break;
    case 5:
        m = "June";
        break;
    case 6:
        m = "July";
        break;
    case 7:
        m = "August";
        break;
    case 8:
        m = "September";
        break;
    case 9:
        m = "October";
        break;
    case 10:
        m = "November";
        break;
    case 11:
        m = "December";
        break;
    }
    std::cout<<d.tm_mday<<" "<<m<<" "<<d.tm_year<<"\n";
}

int main() {
        std::tm tm{};
    tm.tm_year = 2022;
    tm.tm_mon = 4;
    tm.tm_mday = 5;
    std::mktime(&tm);
    ex7(tm);
}