#include <iostream>
#include <climits>
#include <cmath>
#include <chrono>


using namespace std;

template<long long n>
void square(double mat[][n])
{
    double rslt[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < n; k++) {
                rslt[i][j] += mat[i][k] * mat[k][j];
            }
 
            // cout << rslt[i][j] << "\t";
        }
    }
}

int main() {
    constexpr int n1 = 100;
    double m1[n1][n1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            m1[i][j] = (double) rand()/((double)RAND_MAX/ 2.0 - 0) ;
        }
    }
    auto b1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 300; i++)
    {
        square<n1>(m1);
    }
    auto e1 = chrono::high_resolution_clock::now();
    auto diff = e1 - b1;
    auto diff_sec = chrono::duration_cast<chrono::seconds>(diff);
    cout << diff_sec.count() << endl;

    // constexpr long long n2 = 1000;
    // double m2[n2][n2];
    // for (long long i = 0; i < n2; i++)
    // {
    //     for (long long j = 0; j < n2; j++)
    //     {
    //         m2[i][j] = (double) rand()/((double)RAND_MAX/ 2.0 - 0) ;
    //         // m2[i][j] = 1.0 ;
        
    //     }
    // }
    // auto b2 = chrono::high_resolution_clock::now();
    // square<n2>(m2);
    // exit(0);
    // auto e2 = chrono::high_resolution_clock::now();
    // auto diff_2 = e2 - b2;
    // auto diff_sec_2 = chrono::duration_cast<chrono::seconds>(diff_2);
    // cout << diff_sec_2.count() << endl;

    // constexpr long long n3 =  10000;
    // double m3[n3][n3];
    // for (long long i = 0; i < n3; i++)
    // {
    //     for (long long j = 0; j < n3; j++)
    //     {
    //         m3[i][j] = (double) rand()/((double)RAND_MAX/ 2.0 - 0) ;
    //         // m2[i][j] = 1.0 ;
        
    //     }
    // }
    // auto b3 = chrono::high_resolution_clock::now();
    // square<n3>(m3);
    // auto e3 = chrono::high_resolution_clock::now();
    // auto diff_3 = e3 - b3;
    // auto diff_sec_3 = chrono::duration_cast<chrono::seconds>(diff_3);
    // cout << diff_sec_3.count() << endl;
}