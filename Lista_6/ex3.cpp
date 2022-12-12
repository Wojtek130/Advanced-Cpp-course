#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

vector<pair<int, int>> count_max_occurrence(const vector<int> & v, const int interval_beg, const int interval_end) {
    int global_max = 0;
    vector<pair<int, int>> v_out {};
    for (int i = interval_beg; i <= interval_end; i++)
    {
        int curr = count(v.cbegin(), v.cend(), i);
        if (curr > global_max)
        {
            global_max = curr;
            v_out.clear();
            v_out.push_back(make_pair(i, global_max));
        }
        else if (curr == global_max)
        {
            v_out.push_back(make_pair(i, global_max));
        }
    }
    return v_out;
} 

int main() {
    auto v1 = count_max_occurrence({1, 1, 3, 5, 8, 9, 5, 8, 8, 5} , 1, 10);
    for (const auto & e : v1)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    
}