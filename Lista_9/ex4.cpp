#include <iostream>
#include <regex>
#include <string>



using namespace std;

int main() {
    while (true)
    {
        string s;
        // cin>>s;
        getline(cin, s);
        bool found = regex_match(s, regex("^\\(([+-]?[0-9]+(\\.[0-9]+)?)[\\+|-]([0-9]+(\\.[0-9]+)?)[i|I]\\)$"));
        string mes = found ? "match" : "no match" ;
        cout<<mes<<endl; 
    }
    
}