#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

int ARR_SIZE = 100;

int main() {
    int arr_u[ARR_SIZE] = {0};
    int arr_b[ARR_SIZE] = {0};
    int arr_n[ARR_SIZE] = {0};
    default_random_engine dre_u;
    default_random_engine dre_b;
    default_random_engine dre_n;

    int beg = 0;
    int end = beg + ARR_SIZE - 1;
    uniform_real_distribution<double> dr_u( beg, end);
    binomial_distribution<> dr_b( ARR_SIZE - 1, 0.5);
    normal_distribution<> dr_n( ARR_SIZE/2, 30);
    
    for (size_t i = 0; i < 1000; i++)
    {
        int r_u =  dr_u(dre_u);
        int r_b =  dr_b(dre_b);
        int r_n =  dr_n(dre_n);

        arr_u[r_u]++;
        arr_b[r_b]++;
        arr_n[r_n]++;
    }
    ofstream file_u;
    ofstream file_b;
    ofstream file_n;

    file_u.open ("uniform_distribution.csv");
    file_b.open ("binomial_distribution.csv");
    file_n.open ("normal_distribution.csv");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        file_u<<i<<", "<<arr_u[i]<<endl;
        file_b<<i<<", "<<arr_b[i]<<endl;
        file_n<<i<<", "<<arr_n[i]<<endl;
    }
    file_u.close();
    file_b.close();
    file_n.close();
    
    

}