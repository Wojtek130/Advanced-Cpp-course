#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <class T>
void print_range(const T& e, T a, T b) {
    if (e >= a && e <= b) cout<<e<<endl;
}

template <class T>
void print(const T& e) {
    cout<<e<<endl;
}



int main() {
    vector<double> v = {1.5, 2, 3, 4};
    list<string> l = {"a", "b", "c", "d"};
    set<int> s = {10, 20, 30, 40, 30};
    double av = 2;
    double bv = 3;
    string al = "b";
    string bl = "d";
    int p = 2;
    int k = 2;
    auto l2 = [idx = 0, p, k] (auto i) mutable {
        // your code...
        if (idx >= p && idx % k == 0)
        {
            print(i);
        }
        ++idx;
    };
    for_each(v.begin(), v.end(), bind(print_range<double>, placeholders::_1, av, bv));
    for_each(l.begin(), l.end(), bind(print_range<string>, placeholders::_1, al, bl));
    for_each(s.begin(), s.end(), bind(print_range<int>, placeholders::_1, 25, 35));
    cout<<"---------------"<<endl;
    for_each(v.begin(), v.end(), l2);
    for_each(l.begin(), l.end(), l2);
    for_each(s.begin(), s.end(), l2);
    cout<<"---------------"<<endl;
    auto mean = [] (auto col) {
        cout << reduce(col.begin(), col.end()) / col.size() <<endl;
    };
    mean(v);
    mean(s);
    int len = v.size();
    auto mean2 = [len, idx = 0, s = 0.0] (auto e) mutable {
        s += e;
        if ( idx == len - 1)
        {
            cout<<s/len<<endl;
        }
        ++idx;
    };
    for_each(v.begin(), v.end(), mean2);
    cout<<"---------------"<<endl;
    auto curr_min = *v.begin();
    auto curr_max = *v.begin();
    auto min_max = [&curr_min, &curr_max] (auto e) mutable {
        if (e > curr_max)
        {
            curr_max = e;
        }
        if (e < curr_min)
        {
            curr_max = e;
        }
    };
    for_each(v.begin(), v.end(), min_max);
    cout<<curr_min<<" "<<curr_max<<endl;
    auto lsum = [len, idx = 0, curr_sum = 0.0] (auto e) mutable {
        curr_sum += e;
        if ( idx == len - 1)
        {
            cout<<curr_sum<<endl;
        }
        ++idx;
    };
    string curr_str = "";
    auto lconcat = [len, curr_str, idx = 0 ] (auto e) mutable {
        curr_str = curr_str + e;
        if ( idx == len - 1)
        {
            cout<<curr_str<<endl;
        }
        ++idx;
    };
    for_each(v.begin(), v.end(), lsum);
    for_each(l.begin(), l.end(), lconcat);
    for_each(s.begin(), s.end(), lsum);








}
