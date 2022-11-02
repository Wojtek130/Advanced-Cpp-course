#include <iostream>
#include <string>
#include <memory>

using namespace std;

const int m = 15;
const int n = 5;

class ex1
{
private:
    /* data */
    uint64_t counter_;
public:
    ex1(/* args */);
    virtual ~ex1();
    void increment(uint64_t n);
};

ex1::ex1(/* args */)
{
    counter_ = 1;
}

ex1::~ex1()
{
    cerr<<counter_<<endl;
}

void ex1::increment(uint64_t n) {
    counter_ += n;
}

void rec(unique_ptr<ex1[]> arr, int i)
{
    if (i >= m) {
        return;
    }
    int rd = std::rand() % n;
    arr[rd].increment(i);
    rec(move(arr), i+1);
}


int main() {
    unique_ptr<ex1[]> fact(new ex1[n]);
    ex1 e1 = ex1();
    ex1 e2 = ex1();
    ex1 e3 = ex1();
    ex1 e4 = ex1();
    ex1 e5 = ex1();
    fact[0] = e1;  
    fact[1] = e2;    
    fact[2] = e3;    
    fact[3] = e4;    
    fact[4] = e5;    
    rec(move(fact), 0);

}
