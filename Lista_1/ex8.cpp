#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 

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

int main() {
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
}