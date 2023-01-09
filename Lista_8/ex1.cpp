#include <cmath>
#include <complex>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    complex<double> z1( 4.0 , 5.0 );
    complex<double> z2( 1.0 , 00 );
    complex<double> z3( -5.0 , -5.0 );
    complex<double> z4( 0 , 3.0 );
    complex<double> x( 2.0 , -2.0 );
    complex<double> acc( 0 , 0 );
    vector<complex<double>> v = {z4, z3, z2, z1};
    auto value_in_root = [x, v, ind = -1] (auto acc, auto a) mutable {
    // your code...
    cout<<a<<endl;
    ++ind;
    return acc + (a * pow(x, ind));
    };
    complex<double> polynom_value = accumulate(v.begin(), v.end(), acc, value_in_root);
    cout<<polynom_value<<endl;
}