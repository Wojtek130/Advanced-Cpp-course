#include <algorithm>
#include <iostream>
#include <list>
#include <string>


using namespace std;

class Point
{
private:
    string name_;
    double x_;
    double y_;
    int r_;
    int g_;
    int b_;
public:
    Point(string name, double x, double y, int r, int g, int b);
    ~Point();
    string get_name() const;
    double get_x() const;
    double get_y() const;
    double luminance() const;
    friend ostream& operator<<(ostream& os, const Point& p);

};

Point::Point(string name, double x, double y, int r, int g, int b) : name_(name), x_(x), y_(y), r_(r), g_(g), b_(b)
{
}

Point::~Point()
{
}

string Point::get_name() const
{
    return name_;
}

double Point::get_x() const
{
    return x_;
}

double Point::get_y() const
{
    return y_;
}

double Point::luminance() const
{
    return 0.3 * r_ + 0.59 * g_ + 0.11 * b_;
}

ostream& operator<<(ostream& os, const Point& p) 
{
    os << "Point("<< p.name_ << ", " << p.r_ << ", " << p.g_ << ", " << p.b_ << ")"<<endl;
    return os;
}

int main() {
    Point p1("black", 5, 5, 0, 0, 0);
    Point p2("white", 10, 5, 255, 255, 255);
    Point p3("red", -5, 15, 255, 0, 0);
    Point p4("lime", -5, 55, 0, 255, 0);
    Point p5("blue", -45, -45, 0, 0, 255);
    Point p6("yellow", -10, -5, 255, 255, 0);
    Point p7("aqua", 105, 15, 0, 255, 255);
    Point p8("magenta", -5, -25, 255, 0, 255);
    Point p9("silver", -5, 75, 192, 192, 192);
    Point p10("gray", 0, 0, 128, 128, 128);
    Point p11("maroon", -15, 5, 128, 0, 0);
    Point p12("green", 25, -35, 0, 128, 0);
    Point p13("olive", 100, 5, 128, 128, 0);
    Point p14("purple", 555, 155, 128, 0, 128);
    Point p15("teal", -10, 95, 0, 128, 128);
    Point p16("navy", 80, -85, 0, 0, 128);
    Point p17("coral", 70, 70, 255, 127, 80);
    list<Point> lst = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17};
    // copy_if (lst.begin(), lst.end(), back_inserter(lst), []( const Point & p){return p.get_name().length() <= 5;} );
    lst.remove_if([](auto p){ return p.get_name().length() > 5; });
    for (const auto & p : lst) {
        cout<<p;
    }
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int q4 = 0;
    auto quadrants = [&q1, &q2, &q3, &q4](Point & p) -> void
    { 
        double x = p.get_x();
        double y = p.get_y();
        if (x >= 0 && y >= 0)
        {
            q1++;
        }
        else if (x < 0 && y >= 0)
        {
            q2++;
        }
        else if (x < 0 && y < 0)
        {
            q3++;
        }
        else
        {
            q4++;
        }
    };
    for_each(lst.begin(), lst.end(), quadrants);
    cout<<endl;
    cout<<"Quadrants: "<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<endl;
    cout<<endl;

    lst.sort([](auto a, auto b) -> bool
    { 
        return a.luminance() < b.luminance(); 
    });

    for (const auto & p : lst) {
        cout<<p;
    }
    cout<<endl;
    list<Point> dlst;
    copy_if(lst.begin(), lst.end(),
                std::back_inserter(dlst),
                [](const Point & p) { return p.luminance() < 64; });
    for (const auto & p : dlst) {
        cout<<p;
    }
}