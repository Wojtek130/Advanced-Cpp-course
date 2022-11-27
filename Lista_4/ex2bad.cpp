#include <functional>
#include <iostream>

using namespace std;

class in_order {
    public:
        in_order(function<int(int)> f1, function<int(int)> f2) : f1_(f1), f2_(f2) {}  ;
        in_order(in_order io1, function<int(int)> f1) : f1_(f1), io1_(&io1) {}  ;
        in_order(function<int(int)> f1, in_order io1) : f1_(f1), io1_(&io1) {}  ;
        in_order(in_order io1, in_order io2) : io1_(&io1), io2_(&io2) {}  ;
        
        function<int(int)> f1_;
        function<int(int)> f2_;
        in_order* io1_;
        in_order* io2_;


        void operator()(int x)  { 
            if (f1_) f1_(x);
            if (f2_) f2_(x);
            if (io1_) (*io1_)(x);
            if (io2_) (*io2_)(x);
        };

    private:
};


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
    in_order e1(mul2, mul3);
    in_order e2(mul4, mul5);

    in_order e3(e1, e2);

    e2(5);
    // cout << c(5) << endl;
}
