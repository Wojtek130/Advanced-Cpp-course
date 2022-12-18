#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

double shifted_square(double x, double shift) {
    return pow(x - shift, 2) + 1;
}


int my_random(int beg, int end, double random_n) {
    int len = end - beg;
    double mid = beg + len/2.0;
    vector<pair<int, double>> v;
    double s = 0;
    for (int i = beg; i < end; i++)
    {
        // cout<<shifted_square(i, mid)<<endl;
        double curr = shifted_square(i, mid);
        v.push_back(make_pair(i, curr));
        s += curr;
    }
    for (auto & p : v) {
        p.second = p.second / s;
    }

    for (auto i = 0; i < (int) v.size(); i++)
    {
        if (i == 0)
        {
            continue;
        }
        v[i].second = v[i].second + v[i-1].second; 
    }

    int n;
    if (random_n <= v[0].second)
    {
        return v[0].first;
    }
    

    for (const auto & p : v) {
        if (random_n > p.second)
        {
          n = p.first;  
        }
    }
    return n;
    
}


int main() {
    default_random_engine dre;
    uniform_real_distribution<double> dr( 0, 1 );
    for (size_t i = 0; i < 30; i++)
    {
        double rn = dr(dre);
        int res = my_random(0, 100, rn); 
        cout<<res<<endl;
    }
}