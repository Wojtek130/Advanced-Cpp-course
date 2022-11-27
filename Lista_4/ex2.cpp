#include <functional>
#include <iostream>

using namespace std;

int mul2(int x) {
    cout<<"mul2"<<endl;
    return 2*x;
}

int mul3(int x) {
    cout<<"mul3"<<endl;
    return 3*x;
}

int mul4(int x) {
    cout<<"mul4"<<endl;
    return 2*x;
}

int mul5(int x) {
    cout<<"mul5"<<endl;
    return 3*x;
}

int main() {
    auto in_order = [](auto f, auto g) {
        return [=](auto x) {
            f(x);
            g(x);
        };
    };
    // compose(mul2, mul3)(5);
    in_order(in_order(mul2, mul3), mul4)(4);
}



