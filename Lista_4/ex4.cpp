#include <functional>
#include <iostream>

using namespace std;

int main() {
    function<int(int)> fibb;
    fibb = [&fibb] (int n) {
        if (n < 0) {
            throw new invalid_argument();
        }
        if (n < 2) {
            return 1;
        }
        return fibb(n-1) + fibb(n-2);
    };
    cout<<fibb(5)<<endl;
    vector<int> v = {1, 2, 3, 4, 5, -1 };
    auto print_fibb = [fibb] (auto e) {
        cout << fibb(e) <<endl;
    };
    for_each(v.begin(), v.end(), print_fibb);

}