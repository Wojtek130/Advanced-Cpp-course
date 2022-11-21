#include <iostream>
#include<limits>
#include<ratio>

using namespace std;

template<long long n>
auto hn() {
    if constexpr (n != 1) {
       	return ratio_add< decltype(hn<n-1>()), ratio<1,n> >();
    } else {
       	return ratio<1,1>();   
    }
}

int main() {
    auto a = hn<46>();
	cout<<decltype(a)::num<< " " <<decltype(a)::den<<endl;
}