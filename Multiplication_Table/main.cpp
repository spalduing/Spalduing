#include <iostream>

using namespace std;

int mulTable();

int main()
{
    mulTable();

    return 0;
}


/* Displays every multiplication table until the 9th table. */
int mulTable()
{
    for(int i=0; i<10;i++){
        for(int j=0; j<10; j++){
            cout<< j <<" X "<< i << "= ";

            cout<< i*j <<"\t";
        }
        cout << endl;
    }

    return 0;
}
