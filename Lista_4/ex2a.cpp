#include <functional>
#include <iostream>

using namespace std;

template <class T1, class T2, class T3>
class in_order {
    public:
        in_order(function<T1(T2)> f1, function<T1(T3)> f2) : f1_(f1), f2_(f2) {}  ;
        void operator()(T1 x)  { f1_(x), f2_(x); };

    private:
        function<T1(T2)> f1_;
        function<T1(T3)> f2_;
};


int mul2(int x) {
    cout<<"mul2"<<endl;
    return 2*x;
}

int mul3(int x) {
    cout<<"mul3"<<endl;
    return 3*x;
}

int main() {
    in_order<int, int, int> e1(mul2, mul3);
    in_order<int, int, int> e2(e1, mul3);

    e1(5);
    // cout << c(5) << endl;
}
