#include <iostream>
#include <string>
#include <memory>

using namespace std;

unique_ptr<string> demo(const char * s) {
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main() {
    unique_ptr<string> ps1, ps2;
    ps1 = demo("hah");
    ps2 = move(ps1);
    ps1 = demo("nan");
    cout<<*ps1<<*ps2<<endl;
}
