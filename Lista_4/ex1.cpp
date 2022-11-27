#include <functional>
#include <iostream>

using namespace std;

template <class T1, class T2, class T3, class T4>
class compose_f_gx_hx {
    public:
        compose_f_gx_hx(function<T1(T2, T3)> f, function<T2(T4)> g, function<T3(T4)> h) : f_(f), g_(g), h_(h) {}  ;
        T4 operator()(T4 x)  { return f_(g_(x), h_(x)); };

    private:
        function<T1(T2, T3)> f_;
        function<T2(T4)> g_;
        function<T3(T4)> h_;
};

int mul2(int x) {
    return 2*x;
}

int mul3(int x) {
    return 3*x;
}

int my_add(int x, int y) {
    return x + y;
}


int main() {
 compose_f_gx_hx<int, int, int, int> c(my_add, mul2, mul3);
    // cout << c(5) << endl;
    auto out = c(5);
    cout<< out<< endl;
}
