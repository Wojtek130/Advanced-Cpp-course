#include <ctime>
#include <iostream>
#include <random>

using namespace std;

template <class T>
void random_permutation(T a[], int len ) {
    default_random_engine dre(time(NULL));
    for (int i = len - 1; i > 0; i--)
    {
        uniform_int_distribution<int> dr( 0, i );
        int random_ind = dr(dre);
        T temp = a[i];
        a[i] = a[random_ind];
        a[random_ind] = temp;
    }
}

int main() {
    int ARRAY_LEN = 5;
    int arr[ARRAY_LEN] = {1, 2, 3, 4, 5};
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    random_permutation<int>(arr, ARRAY_LEN);
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}