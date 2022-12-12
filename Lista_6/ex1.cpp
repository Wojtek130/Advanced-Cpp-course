#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
// #include <ranges>
#include <iterator>


using namespace std;

class Person
{
private:
    string name_;
    string surname_;
    double age_;
    double weight_;
    double height_;
public:
    Person(string name, string surname, double age, double weight, double height);
    ~Person();
    double bmi() const;
    double get_height_meters() const;
    double get_weight() const;
    void set_weight(double weight);
    double get_age() const;
    friend ostream& operator<<(ostream& os, const Person& p);
};

Person::Person(string name, string surname, double age, double weight, double height)
{
    name_ = name;
    surname_ = surname;
    age_ = age;
    weight_ = weight;
    height_ = height;
}

Person::~Person()
{
}

double Person::get_height_meters() const
{
    return height_/100.0;
}

double Person::bmi() const
{
    return weight_/pow(this->get_height_meters(), 2);
}

double Person::get_weight() const
{
    return weight_;
}

void Person::set_weight(double weight)
{
    weight_ = weight;
}

double Person::get_age() const
{
    return age_;
}



ostream& operator<<(ostream& os, const Person& p) 
{
    os << "Person("<< p.name_ << ", " << p.surname_ << ", " << p.age_ << ", " << p.weight_ << ", " << p.height_ << ")";
    return os;
}

void print_d(deque<Person> de) {
    cout<<"Deque("<<endl;
    for (const auto & p : de) {
        cout << "\t"<< p << ", \n";
    }
    cout<<")"<<endl;
}

int get_random(int ind_beg, int ind_end) {
    return ind_beg + ( rand() % ( ind_end - ind_beg + 1 ) );
}

void shuffle(deque<Person> & de, int ind_beg, int ind_end) {
    for (int i = 0; i < 10; i++)
    {
        int ind1 = get_random(ind_beg, ind_end);
        const auto tmp = *(de.begin()+ind1);
        de.erase(de.begin()+ind1);
        if (ind_beg == 0)
        {
            de.push_front(tmp);
        }
        else
        {
            de.push_back(tmp);
        }
    }
}


Person get_oldest_person(const deque<Person> & de) {
    auto curr_max = *de.begin();
    auto curr_iter = de.begin();
    while(curr_iter != de.end()) {
        if(curr_max.get_age() < curr_iter->get_age())
            curr_max = *curr_iter;
        ++curr_iter;
    }
    curr_max = (de.end()->get_age() > curr_max.get_age()) ? *de.end() : curr_max;
    return curr_max;
}

Person get_youngest_person(const deque<Person> & de) {
    auto curr_min = *de.begin();
    auto curr_iter = de.begin();
    while(curr_iter != de.end()) {
        if(curr_min.get_age() > curr_iter->get_age())
            curr_min = *curr_iter;
        ++curr_iter;
    }
    curr_min = (de.end()->get_age() < curr_min.get_age()) ? *de.end() : curr_min;
    return curr_min;
}


int main() {
    Person p1 = Person("Tom", "Henderson", 30.0, 80.0, 180.0);
    Person p2 = Person("Mary", "Scott", 25.0, 50.0, 160.0);
    Person p3 = Person("Steven", "Jordan", 60.0, 90.0, 175.0);
    Person p4 = Person("Daniel", "Adams", 50.0, 115.0, 200.0);
    Person p5 = Person("Pam", "Houston", 35.0, 70.0, 170.0);
    Person p6 = Person("Harry", "Tomson", 40.0, 150.0, 170.0);
    Person p7 = Person("John", "Mug", 40.0, 70.0, 195.0);


    deque<Person> d {p1, p2, p3, p4, p5, p6, p7};
    print_d(d);
    sort(d.begin(), d.end(), [](const Person & a, const Person & b) -> bool
    { 
        return a.bmi() < b.bmi(); 
    });
    print_d(d);
    auto lose_weight = [](Person & a) -> void
    { 
        a.set_weight(a.get_weight()*0.9);
    };
    for_each(d.begin(), d.end(), lose_weight);
    print_d(d);
    deque<Person> d_over_100, d_under_100;
    copy_if (d.begin(), d.end(), back_inserter(d_over_100), []( const Person & p){return p.get_weight()>=100;} );
    print_d(d_over_100);
    copy_if (d.begin(), d.end(), back_inserter(d_under_100), []( const Person & p){return p.get_weight()<100;} );
    print_d(d_under_100);
    sort(d.begin(), d.end(), [](const Person & a, const Person & b) -> bool
    { 
        return a.get_height_meters() < b.get_height_meters(); 
    });
    print_d(d);
    int mid_ind = d.size()/2;
    Person tmp = d.at(mid_ind);
    d.erase(d.begin()+mid_ind);
    // d.at(5) = tmp;
    d.insert(d.begin() + 5, tmp);
    print_d(d);
    shuffle(d, 0, 4);
    print_d(d);
    shuffle(d, d.size()-5, d.size()-1);
    print_d(d);
    cout<<get_oldest_person(d)<<endl;
    cout<<get_youngest_person(d)<<endl;

}