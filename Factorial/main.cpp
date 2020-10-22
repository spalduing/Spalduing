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
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;
    if(n == 0){
        cout << "El factorial de n es: 1";
    }else{
    int f[n];
    int r;
    for(int i=n; i>0; i--){
        f[i-1]=i;
    }
    for(int j=n; j>1; j--){
        r=n*f[j-2];
        n=r;
    }
    cout << "El factorial de n es: "<< r << endl;
    }
    return 0;
}

/*
Calculate the factorial of a number in a more efficient way
*/
int factorial2()
{
    int n,f;
    cout << "Enter a number: ";
    cin >> n;
    f=1;
    for(int i=n; i>= 1; --i){
        f *= i;
        cout << f<<"\n";
    }
    cout << n << "! equals to: "<< f <<endl;
    f = 1;
    return 0;
}
