#include <iostream>
#include <regex>
#include <string>
#include <fstream>  
#include<sstream>



using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++)
    {
        cout<<"--- file: "<<argv[i]<<endl;
        ifstream f(argv[i]); 
        ostringstream ss;
        ss << f.rdbuf(); 
        if (!f)
        {
            cout<<"--- cannot read the file"<<endl;
            continue;
        }
        
        string data = ss.str();
        regex reg("<a.*href\\s?=['\"]*([^'\"]*)[^>]*>(.*)?<\\/a>");
        sregex_iterator beg(data.cbegin(), data.cend(), reg);
        sregex_iterator end;
        for_each(beg, end, [] (const smatch &m) {
        cout<<m.str(1)<<endl;
    });
        cout<<"--- file end"<<endl;

    }
    

}