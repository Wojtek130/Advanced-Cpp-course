#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class line_writer
{
private:
    ofstream file_stream_;
public:
    line_writer(string filename);
    ~line_writer();
    void write(string text);
};

line_writer::line_writer(string filename)
{
    file_stream_ = ofstream(filename, ios::binary);
}

line_writer::~line_writer()
{
    cout<<"closing\n";
    file_stream_.close();
}

void line_writer::write(string text) {
    file_stream_ << text << endl;
}


int main(){
    line_writer* lw = new line_writer("out.txt");
    shared_ptr<line_writer> sp1(lw);
    auto sp2 = sp1;
    auto sp3(sp1);
    sp1->write("sp1");
    sp2->write("sp2");
    sp3->write("sp3");

    {
        auto sp4(sp3);
        sp4->write("sp4");
    }


}