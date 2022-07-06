#include <iostream>

using namespace std;

bool is_even(int n);
bool is_odd(int n);

int main()
{
    int number = 0;

    cout << "Enter a number: ";
    cin >> number;

    if(is_even(number)){cout << "Is Even!" << endl;}
    if(is_odd(number)){cout << "Is Odd!" << endl;}



    return 0;
}

bool is_even(int n)
{
    return ((n % 2) == 0);
}
bool is_odd(int n)
{
    return ((n&1)==1);
}
