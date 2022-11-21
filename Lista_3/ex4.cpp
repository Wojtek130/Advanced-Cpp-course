#include <iostream>
#include <type_traits>

using namespace std;

template<typename T1, typename T2> 
void move_value_impl (T1 source, T2 dest, true_type, true_type ) {
    dest = *source;
    cout<<"tt"<<endl;
    cout<<dest<<endl;
} 

template<typename T1, typename T2> 
void move_value_impl (T1 source, T2 & dest, false_type, true_type ) {
    dest = source;
    cout<<"ft"<<endl;
    cout<<dest<<endl;
} 

template<typename T1, typename T2> 
void move_value_impl (T1 source, T2 & dest, true_type, false_type ) {
    throw invalid_argument("inconvertable types"); 
} 

template<typename T1, typename T2> 
void move_value_impl (T1 source, T2 & dest, false_type, false_type ) {
    throw invalid_argument("inconvertable types"); 
} 

template<typename T1, typename T2> 
void move_value (T1 source, T2 & dest ) {
    move_value_impl (source, dest, is_pointer<T1>(), is_convertible<T1, T2>());
} 

int main() {
    int num1 = 5;
    long num2 = 10;
    cout << num1 << " " << num2 << endl;
    move_value(num1, num2);
    cout << num1 << " " << num2 << endl;

    float num3 = 2;
    int num4 = 10;
    cout << num3 << " " << num4 << endl;
    move_value(num3, num4);
    cout << num3 << " " << num4 << endl;
}