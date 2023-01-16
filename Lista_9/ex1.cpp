#include <iostream>
#include <regex>
#include <string>



using namespace std;

int main() {
    while (true)
    {
        string s;
        cin>>s;
        bool found = regex_match(s, regex("^(0[0-9]|[1][0-9]|[2][0-3]):(0[0-9]|[1-5][0-9])(:0[0-9]|[1-5][0-9])?$"));
        string mes = found ? "match" : "no match" ;
        cout<<mes<<endl; 
    }
    
}

// (0[0-9]|[1][0-9]|[2][0-3])   0-24
// (0[0-9]|[1-5][0-9])          0-59