#include <bits/stdc++.h>
#include<ratio>
#include<limits>
using namespace std;
using ll = long long;

template<ll N>
auto harmony() {
    if constexpr (N == 1) {
       	return ratio<1,1>();   
    } else {
		auto ret = ratio_add< decltype(harmony<N-1>()), ratio<1,N> >();
       	return ret;
    }
}

int main()
{
	cout << decltype(harmony<46>())::num << " " << decltype(harmony<46>())::den << endl;
}