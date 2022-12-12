#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2)
    {
        throw new invalid_argument("");
    }
    
    ifstream t(argv[1]);
    stringstream buffer;
    buffer << t.rdbuf();
    string s = buffer.str();
    remove_if(s.begin(), s.end(), [](unsigned char c){ return c < 'A' || (c > 'Z' && c < 'a') || c > 'z' || c == '\t' || c == '\n';});
    cout<<s<<endl;
    if (s == "")
    {
        throw new invalid_argument("");
    }
    vector<pair<char, double>> v;
    char character='A';
    int all_c = 0;
	do
	{
        char character_low = character+32;
        int c = count(s.begin(), s.end(), character);
        c += count(s.begin(), s.end(), character_low);
        all_c += c;
        if (c != 0)
        {
            v.push_back(make_pair(character_low, c));
        }
		character++;
	}
	while(character<='Z');
    for_each(v.begin(), v.end(),[&all_c](auto& p)
    {
        p.second = p.second/all_c;
    });
    for (const auto & e : v) {
        cout<<e.first<<" : "<<e.second<<endl;
    }
}