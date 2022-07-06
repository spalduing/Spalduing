#include <iostream>

using namespace std;

int revInfDiag();

int main()
{


    revInfDiag();

    return 0;
}

/* Reverse Inferior diagonal of a matrix */
int revInfDiag()
{
    //ENTERING THE DIMENSION OF THE ARRAY//
    int m_dimension, n_dimension, number;
    cout << "Enter the m dimension of the matrix: ";
    cin >> m_dimension;
    cout << "Enter the n dimension of the matrix: ";
    cin >> n_dimension;

    //INITIALIZING THE ARRAY WITH ZEROS//
    int matrix[m_dimension][n_dimension];
    for(int i=0; i<m_dimension;i++){
        for(int j=0; j<n_dimension; j++){
            matrix[i][j]=0;
            cout<<"\n";
        }
        cout<<"\n";
    }

    //ENTERING THE NUMBERS IN THE ARRAY//
    int column_cap = 0;
    for(int i=m_dimension-1; i>-1; i--){
        for(int j=column_cap; j<n_dimension; j++){
            cout << "Enter the number to put in the ["<<i<<"] "<<"["<<j<<"] position: ";
            cin>> number;
            matrix[i][j]=number;
            cout<<"\n";
        }
        column_cap++;
        cout<<"\n";
    }
    for(int k=0; k<m_dimension;k++){
        for(int l=0; l<n_dimension; l++){
            cout << "["<<matrix[k][l]<<"] ";
        }
        cout<<"\n";
    }
    return 0;
}
