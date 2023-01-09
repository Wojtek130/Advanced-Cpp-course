#include <cmath>
#include <complex>
#include <fstream>
#include <functional>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
complex<T> gamma(const complex<T> z, const int prec) {
    complex<T> prod(1,0);
    complex<T> one(1, 0);
    complex<T> i(0,0);
    for (int j = 1; j < prec; j++)
    {
        i += one;
        // cout<<i<<endl;
        prod *= (pow(one + (one/i), z)/(one + (z/i)));
    }
    return prod / z;
}

template <class T>
complex<T> inverse_gamma(const complex<T> z, const int prec) {
    complex<T> prod(1,0);
    complex<T> one(1, 0);
    complex<T> mone(-1, 0);
    complex<T> i(0,0);
    complex<T> em(0.5772156649,0);
    for (int j = 1; j < prec; j++)
    {
        i += one;
        // cout<<i<<endl;
        prod *= (one + (z/i)) * exp(mone * z / i);
    }
    return z * exp(em*z)* prod;
}

template <class T>
complex<T> zeta1(const complex<T> z, const int prec) {
    complex<T> s(0,0);
    complex<T> one(1, 0);
    complex<T> i(0,0);
    for (int j = 1; j < prec; j++)
    {
        i += one;
        // cout<<i<<endl;
        s += one / pow(i, z);
    }
    return s;
}

template <class T>
complex<T> zeta2_formula(const complex<T> z, const int prec) {
    const complex<T> one(1, 0);
    const complex<T> two(1, 0);
    const complex<T> pi(3.14,0);
    return pow(two, z) * pow(pi, z - one) * sin(pi * z / two) * gamma<T>(one - z, prec);
}

template <class T>
complex<T> zeta2(const complex<T> z, const int prec) {
    const complex<T> one(1, 0);
    complex<T> z2(one - z);
    complex<T> value = zeta2_formula<T>(z, prec);
    // for (int i = 0; i < prec; i++)
    // {
    //     value *= zeta2_formula<T>(z2, prec);
    //     cout<<z2<<" bef "<<endl;
        
    //     z2 = one - z2;
    //     cout<<z2<<" aft "<<endl;

    // }
    
    return value;
}

template <class T>
complex<T> zeta3(complex<T> z, const int prec) {
    const complex<T> one(1, 0);
    const complex<T> two(2, 0);
    complex<T> s(1, 0);
    for(int i = 1; i <= prec; i++) {
        complex<T> exponent(i, 0);
        s += pow(-one, exponent + one) / pow(exponent, z);
    }
    return one / (one - pow(two, one - z)) * s;
}

template <class T>
complex<T> zeta(const complex<T> z, const int prec) {
    // cout<<z.real()<<"!!!"<<endl;
    // exit(0);
    if (z.real() == 1) {
        return complex<T>(1,0);
    };
    if (z.real() == 0) {
        return complex<T>(-0.5,0);
    };
    if (z.real() > 1) {
        cout<<"si";
        return zeta1<T>(z, prec);
    };
    return zeta3<T>(z, prec);
}


int main() {
    complex<long double> one(2,0);

    complex<long double> z1(1,0);
    complex<long double> z2(2,0);
    complex<long double> z3(3,0);
    complex<long double> z4(4,0);
    complex<long double> z5(5,0);
    complex<long double> z6(0,1);

    cout<<gamma<long double>(z1,1000)<<one/gamma<long double>(z1,1000)<<" "<<inverse_gamma<long double>(z1,1000)<<endl;
    cout<<gamma<long double>(z2,1000)<<one/gamma<long double>(z2,1000)<<" "<<inverse_gamma<long double>(z2,1000)<<endl;
    cout<<gamma<long double>(z3,1000)<<one/gamma<long double>(z3,1000)<<" "<<inverse_gamma<long double>(z3,1000)<<endl;
    cout<<gamma<long double>(z4,1000)<<one/gamma<long double>(z4,1000)<<" "<<inverse_gamma<long double>(z4,1000)<<endl;
    cout<<gamma<long double>(z5,1000)<<one/gamma<long double>(z5,1000)<<" "<<inverse_gamma<long double>(z5,1000)<<endl;
    cout<<gamma<long double>(z6,1000)<<one/gamma<long double>(z6,1000)<<" "<<inverse_gamma<long double>(z6,1000)<<endl;
    cout<<zeta<long double>(complex<long double>(0.5, 0.1), 10)<<endl;
    // cout<<zeta<long double>(-1, 100)<<endl;
    // cout<<zeta<long double>(0, 100)<<endl;
    // cout<<zeta<long double>(2, 100)<<endl;
    ofstream file;
    file.open ("riemann2.csv");
    double beg = -25;
    double end = -beg;
    file<<"Arg,Real,Imag\n";
    for (long double t = beg; t <= end; t += 0.1)
    {
        complex<long double> s (0.5, t);
        complex<long double> res = zeta(s, 10);
        cout<<t<<"; "<<res.real()<<", "<<res.imag()<<endl;
        file<< t<<","<<fixed << setprecision(2) <<res.real() <<","<<fixed << setprecision(2) <<res.imag()<<endl;
        cout<<t<<endl;
    }
    
}