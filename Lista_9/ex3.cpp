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
        bool found = regex_match(s, regex("^([A-Z][a-z]+)(((-|[[:space:]]*))([A-Z][a-z]+))?$"));
        string mes = found ? "match" : "no match" ;
        cout<<mes<<endl; 
    }
    
}