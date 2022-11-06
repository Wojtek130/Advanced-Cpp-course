#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>


using namespace std;

enum sex { male, female, unknown };


class alpaca : enable_shared_from_this<alpaca>
{
public:
    string name_;
    sex sex_;
    shared_ptr<alpaca> father_;
    shared_ptr<alpaca> mother_;
    vector<weak_ptr<alpaca>> children_;
    void validate_name(string name);
    static shared_ptr<alpaca> nonname_;
    static vector<string> used_names_; 
    alpaca(string name, sex sex);
    alpaca(string name, sex sex, shared_ptr<alpaca> mother);
    alpaca(string name, sex sex, shared_ptr<alpaca> mother, shared_ptr<alpaca> father);
    alpaca(string name, sex sex, nullptr_t, nullptr_t);
    ~alpaca();
    friend ostream &operator<<(std::ostream &os, const alpaca &a);
    friend bool operator==(const alpaca& lhs, const alpaca& rhs);

};




alpaca::alpaca(string name, sex sex)
{
    this->validate_name(name);
    name_ = name;
    used_names_.push_back(name_);
    sex_ = sex;
    father_ = nonname_;
    mother_ = nonname_;
}

alpaca::alpaca(string name, sex sex, nullptr_t, nullptr_t)
{
    this->validate_name(name);
    name_ = name;
    used_names_.push_back(name_);
    sex_ = sex;
    father_ = nonname_;
    mother_ = nonname_;
}

alpaca::alpaca(string name, sex sex, shared_ptr<alpaca> mother)
{
    this->validate_name(name);
    name_ = name;
    used_names_.push_back(name_);
    sex_ = sex;
    father_ = nonname_;
    mother_ = mother;
}

alpaca::alpaca(string name, sex sex, shared_ptr<alpaca> mother, shared_ptr<alpaca> father)
{
    this->validate_name(name);
    name_ = name;
    used_names_.push_back(name_);
    sex_ = sex;
    father_ = father;
    mother_ = mother;
}

alpaca::~alpaca()
{
}


void alpaca::validate_name(string name)
{
    if (find(used_names_.begin(), used_names_.end(), name) != used_names_.end())
    {
        throw invalid_argument( "Alpaca with this name alreasdy exists! Try diffrent one" );
    }
    
}


ostream &operator<<(std::ostream &os, const alpaca &a)
{
    os<<"alpaca("<<a.name_<<")\n";
    return os;
}

bool operator==(const alpaca& lhs, const alpaca& rhs)
{
    return lhs.name_ == rhs.name_;
}



class herd
{
private:
    vector<shared_ptr<alpaca>> herd_;
public:
    herd(/* args */);
    ~herd();
    void buy_alpaca(string name, sex sex);
    void born_in_herd(string name, sex sex, string mother_name);
    void born_in_herd(string name, sex sex, string mother_name, string father_name);
    shared_ptr<alpaca> find_parent(string name, sex sex);
    friend ostream &operator<<(std::ostream &os, const herd &h);
    void died(string name);
    shared_ptr<alpaca> get_alpaca(string name);

};

herd::herd(/* args */)
{
}

herd::~herd()
{
}

void herd::buy_alpaca(string name, sex sex){
    alpaca a = alpaca(name, sex, nullptr, nullptr);
    herd_.push_back(make_shared<alpaca>(std::move(a)));
}

void herd::born_in_herd(string name, sex sex, string mother_name){
    shared_ptr<alpaca> mother = this->find_parent(mother_name, sex::female);
    alpaca na = alpaca(name, sex, mother);
    shared_ptr<alpaca> naptr = make_shared<alpaca>(std::move(na));
    mother->children_.push_back(naptr);
    herd_.push_back(naptr);
}

void herd::born_in_herd(string name, sex sex, string mother_name, string father_name){
    shared_ptr<alpaca> mother = this->find_parent(mother_name, sex::female);
    shared_ptr<alpaca> father = this->find_parent(father_name, sex::male);
    alpaca na = alpaca(name, sex, mother, father);
    shared_ptr<alpaca> naptr = make_shared<alpaca>(std::move(na));
    mother->children_.push_back(naptr);
    father->children_.push_back(naptr);
    herd_.push_back(naptr);
}

shared_ptr<alpaca> herd::find_parent(string name, sex sex) {
    bool found = false;
    shared_ptr<alpaca> parent;
    for (auto a : herd_) {
        if (a->name_ == name && a->sex_ == sex) {
            parent = a;
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw invalid_argument( "Parent with the given name does not exist in the herd" );
    }
    return parent;
}

void herd::died(string name) {
    bool found = false;
    shared_ptr<alpaca> alpc;
    for (auto a : herd_) {
        if (a->name_ == name) {
            alpc = a;
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw invalid_argument( "Alpaca with the given name does not exist in the herd" );
    }
    alpaca::used_names_.erase(std::find(alpaca::used_names_.begin(),alpaca::used_names_.end(), name));
    // herd_.erase(std::find(herd_.begin(), herd_.end(), *alpc));
    int ind = 0;
    for (long unsigned int i = 0; i < herd_.size(); i++)
    {
        if (herd_[i]->name_ == name)
        {
            ind = i;
        }
        
    }
    herd_.erase(herd_.begin() + ind);
    alpc.reset();
    // delete alpc;
}

shared_ptr<alpaca> herd::get_alpaca(string name) {
    bool found = false;
    shared_ptr<alpaca> alpc;
    for (auto a : herd_) {
        cout<<"hejj"<<"\n";
        if ((*a).name_ == name) {
            alpc = a;
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw invalid_argument( "aaAlpaca with the given name does not exist in the herd" );
    }
    return alpc;
}


ostream &operator<<(std::ostream &os, const herd &h) {
    os<<"Herd{\n";
    for (const auto & a : h.herd_) {
        os<<"\t"<<*a;
    }
    os<<"}\n";
    return os;
}




shared_ptr<alpaca> alpaca::nonname_ = shared_ptr<alpaca>(new alpaca(string(""), sex::unknown, nullptr, nullptr));
vector<string> alpaca::used_names_; 


int main(){
    // alpaca a1 = alpaca("emma", sex::female, nullptr, nullptr);
    // alpaca a2 = alpaca("john", sex::male, nullptr, nullptr);
    herd h = herd();
    h.buy_alpaca("emma", sex::female);
    h.buy_alpaca("john", sex::male);
    h.born_in_herd("jack", sex::male, "emma");
    h.born_in_herd("george", sex::male, "emma", "john");
    cout<<h;

    auto emma = h.get_alpaca("emma");
    cout<<emma->name_<<endl;
    cout<<emma->children_.size()<<endl;
    for (const auto &p : emma->children_) {
        if(auto tmp = p.lock())
            cout << "weak value is " << *tmp;
        else
            cout << "weak is expired\n";
    }
    h.died("george");
    cout<<h;
    for (const auto &p : emma->children_) {
        if(auto tmp = p.lock())
            cout << "weak value is " << *tmp;
        else
            cout << "weak is expired\n";
    }
    // cout<<*(h.get_alpaca("george")->father_)<<endl;

    // alpaca a3 = alpaca("mark", sex::male, make_shared<alpaca>(a1), make_shared<alpaca>(a2));
    // a3.smother(make_shared<alpaca>(a1));
    // cout<<a1<<a2<<a3;
}