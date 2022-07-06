#include <iostream>

using namespace std;

int factorial();
int factorial2();

int main()
{
    factorial();
    factorial2();

    return 0;
}

int factorial()
{
    int number;
    cout << "Enter a number to calculate its factorial: ";
    cin >> number;
    if(number == 0){
        cout << "El factorial de n es: 1";
        return 0;
    }else{
    int factorial_array[number];

    int answer;
    for(int i=number; i>0; i--){
        factorial_array[i-1]=i;
    }
    for(int j=number; j>1; j--){
        answer=number*factorial_array[j-2];
        number=answer;
    }
    cout << "El factorial de n es: "<< answer << endl;
    }
    return 0;
}

/*
Calculate the factorial of a number in a more efficient way
*/
int factorial2()
{
    int number,factorial;

    cout << "Enter a number: ";
    cin >> number;

    factorial=1;

    for(int i=number; i>= 1; --i){
        factorial *= i;
        cout << "Current factorial: " << i << " = " << factorial <<"\n";
    }

    cout << number << "! equals to: "<< factorial <<endl;
    factorial = 1;

    return 0;
}
