#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("abc");
    do
    {
        cout << s << "\n";
    }
    while (next_permutation(s.begin(), s.end()) );
}