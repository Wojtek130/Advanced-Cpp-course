#include <algorithm>    
#include <cmath>
// #include <compare>
#include <ctime>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector> 


std::vector<int>::iterator bin_search(int v_size, const std::vector<int>::iterator & beg, const std::vector<int>::iterator & end, int value) {
    auto mid = beg + (v_size/2);
    // auto ans =  value <= > *mid;
    // auto ans = 5 <= > 3;

    // if (ans == 0)
    // {
    //     return mid;
    // }
    // if (ans > 0)
    // {
    //     return bin_search(v_size/2, mid+1, end, value);
    // }
    // return bin_search(v_size/2, beg, mid-1, value);
        // auto ans = 5 <= > 3;
    if (value == *mid)
    {
        return mid;
    }
    if (value > *mid)
    {
        return bin_search(v_size/2, mid+1, end, value);
    }
    return bin_search(v_size/2, beg, mid-1, value);
}


std::pair<std::vector<int>::iterator, std::vector<int>::iterator> find_beg_end_iters(std::vector<int>::iterator found, std::vector<int>::iterator v_begin, std::vector<int>::iterator v_end)
{
    int v = *found;
    std::vector<int>::iterator beg = found;
    std::vector<int>::iterator end = found;
    while (*beg == v && std::prev(beg) == found && beg != v_begin) {
        beg = std::prev(beg);
    }
    while (*end == v && *(std::next(end)) == v && end != v_end) {
        end = std::next(end);
    }
    if (*beg != v) {
        beg = std::prev(beg);
    }
    if (*end != v) {
        end = std::next(end);
    }
    return std::make_pair(beg, end);
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> ex9(std::vector<int> v, int value)
{
    return find_beg_end_iters(bin_search(v.size(), v.begin(), v.end(), value), v.begin(), v.end());
}

int main() {
        std::vector<int> v1 {1, 1, 2, 2, 2, 3, 3, 4, 4, 7, 7, 8, 9, 9};
    auto res = bin_search(v1.size(), v1.begin(), v1.end(), 1);
    std::cout<<*res<<" <- bin search\n";
    auto [b1, e1] = ex9(v1, 7);
    std::cout<<*b1<<" "<<*e1<<" out\n";
}