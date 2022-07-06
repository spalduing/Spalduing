#include <iostream>

using namespace std;

void swapNum(int *a, int *b);

int main()
{
    int number_a = 8;
    int number_b = 7;

    int *pNumber_a = &number_a;
    int *pNumber_b = &number_b;

    cout << "number_a = " << number_a << endl;
    cout << "number_b = " << number_b << endl << endl;

    swapNum(pNumber_a, pNumber_b);

    cout << "NOW THE VALUES ARE SWAPED" << endl;
    cout << "=========================" << endl;

    cout << "number_a = " << number_a << endl;
    cout << "number_b = " << number_b << endl << endl;

    return 0;
}

void swapNum(int *a_pointer, int *b_pointer )
{
    int temp= *a_pointer;
    *a_pointer = *b_pointer;
    *b_pointer = temp;
}
