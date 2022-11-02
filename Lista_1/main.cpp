#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 


??=define MSG "ex1"

template<typename T>
using stringSet = std::set<std::basic_string<T>>;
// using stringSet = std::set<std::string>;
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

void ex6(int a, int b, int c){
    if (int d = (b * b) - (4 * a * c) < 0) {
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

void ex7(std::tm d) {
    std::cout<<"jeeeemeiwk\n";
    std::string m;
    switch (auto month = d.tm_mon)
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


class Person
{
private:
    std::string fname_;
    std::string sname_;
    int birth_year_;

public:
    Person(std::string fname, std::string sname, int birth_year);
    Person();
    friend bool operator<(Person const& lhs, Person const& rhs);
    friend bool operator>(Person const& lhs, Person const& rhs);
    friend bool operator==(Person const& lhs, Person const& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
Person:: Person(std::string fname, std::string sname, int birth_year)
{
    fname_ = fname;
    sname_ = sname;
    birth_year_ = birth_year;
}
Person:: Person()
{
}

bool operator<(Person const& lhs, Person const& rhs) {
  return std::tie(lhs.fname_, lhs.sname_, lhs.birth_year_) <
         std::tie(rhs.fname_, rhs.sname_, rhs.birth_year_);
}

bool operator>(Person const& lhs, Person const& rhs) {
  return std::tie(lhs.fname_, lhs.sname_, lhs.birth_year_) >
         std::tie(rhs.fname_, rhs.sname_, rhs.birth_year_);
}

bool operator==(Person const& lhs, Person const& rhs) {
  return std::tie(lhs.fname_, lhs.sname_, lhs.birth_year_) ==
         std::tie(rhs.fname_, rhs.sname_, rhs.birth_year_);
}

std::ostream& operator<<(std::ostream& os, const Person& p) 
{
    os << "Person("<< p.fname_ << ", " << p.sname_ << ", " << p.birth_year_ << ")";
    return os;
}

std::vector<int>::iterator bin_search(int v_size, const std::vector<int>::iterator & beg, const std::vector<int>::iterator & end, int value) {
    auto mid = beg + (v_size/2);
    // auto ans =  value <= > *mid;
    // auto ans = 5 <= > 3;

    // if (ans == 0)
    // {
    //     return mid;
    // }
    // if (ans > 0)
    // {
    //     return bin_search(v_size/2, mid, end, value);
    // }
    // return bin_search(v_size/2, beg, mid, value);
        // auto ans = 5 <= > 3;
    std::cout<<*mid<<" mid \n";
    if (value == *mid)
    {
        return mid;
    }
    if (value > *mid)
    {
        return bin_search(v_size/2, mid+1, end, value);
    }
    return bin_search(v_size/2, beg, mid-1, value);
}


std::pair<std::vector<int>::iterator, std::vector<int>::iterator> find_beg_end_iters(std::vector<int>::iterator found, std::vector<int>::iterator v_begin, std::vector<int>::iterator v_end)
{
    int v = *found;
    std::vector<int>::iterator beg = found;
    std::vector<int>::iterator end = found;
    std::cout<<v<<" si \n";
    while (*beg == v && std::prev(beg) == found && beg != v_begin) {
        beg = std::prev(beg);
        std::cout<<*beg<<" hah\n";
    }
    while (*end == v && *(std::next(end)) == v && end != v_end) {
        end = std::next(end);
        std::cout<<*end<<" hah2\n";
    
    }
    // if (*beg != v) {
    //     beg = std::prev(beg);
    // }
    // if (*end != v) {
    //     end = std::next(end);
    // }
    std::cout<<*beg<<" "<<v<<" "<<*end<<" ??\n";
    return std::make_pair(beg, end);
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> ex9(std::vector<int> v, int value)
{
    return find_beg_end_iters(bin_search(v.size(), v.begin(), v.end(), value), v.begin(), v.end());
}


int main(){
    std::cout<<MSG<<"\n";

    // ex2 - raw strings: characters inside the string are not interpreted
    std::cout<< R"(Instytut Informatyki Uniwersytetu Wrocławskiego)"<<"\n";
    std::cout<< R"(ul. Joliot-Curie 15)"<<"\n";
    std::cout<< R"(50-383 Wrocław)"<<"\n";
    std::cout<< R"("C:\Program Files")"<<"\n"; //? - right path?
    std::cout<< R"+*((("("())")))+*"<<"\n"; // ") enabled throgu R"+*(i)+*"
    stringSet<char> s{"aaa", "bbb"};
    for (auto& e : s) {
        std::cout<<e<<"\n";
    }
    ex4("Hello", Names::Tom);
    ex4("Hi", Names::Mary);
    for (int i = 0; i < 5; i++)
    {
        std::cout<<ex5(i)<<"\n";
    }
    ex6(1, 0, 0);
    ex6(1, -1, 0);
    ex6(1, 0, -1);
    std::tm tm{};
    tm.tm_year = 2022;
    tm.tm_mon = 0;
    tm.tm_mday = 1;
    std::mktime(&tm);
    ex7(tm);
    Person p1 = Person("Tom", "Jenkins", 1955);
    Person p2 = Person("Ann", "Thomson", 2005);
    Person p3 = Person("Monica", "Bell", 1995);
    std::vector<Person> ex8 {p1, p2, p3};
    for (const auto p: ex8) {
        std::cout<<p<<" ";
    }
    std::cout<<"\n";
    std::sort(ex8.begin(), ex8.end());
        for (const auto p: ex8) {
        std::cout<<p<<" ";
    }
    std::cout<<"\n";
    std::vector<int> v1 {1, 1, 2, 2, 2, 3, 3, 4, 4, 7, 7, 8, 9, 9};
    auto res = bin_search(v1.size(), v1.begin(), v1.end(), 1);
    std::cout<<*res<<" <- bin search\n";
    // auto [b, e] = ex9(v1, 4);
    // std::cout<<*b<<" "<<*e<<"\n";
    auto [b1, e1] = ex9(v1, 7);

    std::cout<<*b1<<" "<<*e1<<" out\n";
}