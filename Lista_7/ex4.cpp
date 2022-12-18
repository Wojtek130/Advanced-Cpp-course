#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

double shifted_square(double x, double shift) {
    return pow(x - shift, 2) + 1;
}


int my_random(int beg, int end, double random_n) {
    int len = end - beg;
    double mid = beg + len/2.0;
    vector<pair<int, double>> v;
    double s = 0;
    for (int i = beg; i < end; i++)
    {
        // cout<<shifted_square(i, mid)<<endl;
        double curr = shifted_square(i, mid);
        v.push_back(make_pair(i, curr));
        s += curr;
    }
    for (auto & p : v) {
        p.second = p.second / s;
    }

    for (auto i = 0; i < (int) v.size(); i++)
    {
        if (i == 0)
        {
            continue;
        }
        v[i].second = v[i].second + v[i-1].second; 
    }

    int n;
    if (random_n <= v[0].second)
    {
        return v[0].first;
    }
    

    for (const auto & p : v) {
        if (random_n > p.second)
        {
          n = p.first;  
        }
    }
    return n;
    
}


int main(int argc, char** argv) {
    if (argc != 3)
    {
        throw new invalid_argument("");
    }
    cout<<argc<<endl;
    pair<char, double> p1 = make_pair('e', 0.1202);
    pair<char, double> p2 = make_pair('t', 0.091);
    pair<char, double> p3 = make_pair('a', 0.0812);
    pair<char, double> p4 = make_pair('o', 0.0768);
    pair<char, double> p5 = make_pair('i', 0.0731);
    pair<char, double> p6 = make_pair('n', 0.0695);
    pair<char, double> p7 = make_pair('s', 0.0628);
    pair<char, double> p8 = make_pair('r', 0.0602);
    pair<char, double> p9 = make_pair('h', 0.0592);
    pair<char, double> p10 = make_pair('d', 0.0432);
    pair<char, double> p11 = make_pair('l', 0.0398);
    pair<char, double> p12 = make_pair('u', 0.0288);
    pair<char, double> p13 = make_pair('c', 0.0271);
    pair<char, double> p14 = make_pair('m', 0.0261);
    pair<char, double> p15 = make_pair('f', 0.023);
    pair<char, double> p16 = make_pair('y', 0.0211);
    pair<char, double> p17 = make_pair('w', 0.0209);
    pair<char, double> p18 = make_pair('g', 0.0203);
    pair<char, double> p19 = make_pair('p', 0.0182);
    pair<char, double> p20 = make_pair('b', 0.0149);
    pair<char, double> p21 = make_pair('v', 0.0111);
    pair<char, double> p22 = make_pair('k', 0.0069);
    pair<char, double> p23 = make_pair('x', 0.0017);
    pair<char, double> p24 = make_pair('q', 0.0011);
    pair<char, double> p25 = make_pair('j', 0.001);
    pair<char, double> p26 = make_pair('z', 0.0007);
    vector<pair<char, double>> v = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26};
    for (auto i = 0; i < (int) v.size(); i++)
    {
        if (i == 0)
        {
            continue;
        }
        v[i].second = v[i].second + v[i-1].second; 
    }
    // for (const auto & p : v) {
    //     // cout<<p.first<<" "<<p.second<<endl;
    // }
    ofstream file_out;
    file_out.open (argv[2]);
    int total_length = atoi(argv[1]);
    int curr_length = 0;
    default_random_engine dre_b;
    binomial_distribution<> dr_b( 12, 0.5);
    default_random_engine dre_u;
    uniform_real_distribution<double> dr_u( 0, 1 );
    while (curr_length < total_length)
    {
        int word_length = 0;
        while (word_length == 0 || curr_length + word_length > total_length)
        {
            if (total_length - curr_length < 4)
            {
                word_length = total_length - curr_length;
                break;
            }
            
            word_length = dr_b(dre_b);
        };
        curr_length += word_length;
        for (int i = 0; i < word_length; i++)
        {
            double random_n = dr_u(dre_u);
            // cout<<random_n <= v[0].second<<endl;
            char c = '!';
            // if (random_n <= v[0].second)
            // {
            //     c = v[0].first;
            // }
            for (const auto & p : v) {
                if (random_n < p.second)
                {
                    c = p.first; 
                    // cout<<c<<" "<<random_n<<endl;
                    break;
                }
            }
            file_out<<c;
            c = '!';
        }
        file_out<<" ";
    }
    file_out.close();
}