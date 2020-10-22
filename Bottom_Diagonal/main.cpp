#include <iostream>

using namespace std;

int main()
{
    int m_dimension, n_dimension = 0;

    cout << "Enter the m dimension of the matrix: ";
    cin >> m_dimension;

    cout << "Enter the n dimension of the matrix: ";
    cin >> n_dimension;

    int v[4] = {};

    int matrix[m_dimension][n_dimension];

    //INITIALIZING MATRIX//
    for(int i=0; i<m_dimension;i++){
        for(int j=0; j<n_dimension; j++){
            matrix[i][j]=0;
        }
    }

    //DISPLAYING THE BOTTON DIAGONAL OF THE MATRIX//
    int column_cap = 1;
    for(int i=0; i< m_dimension; i++)
    {
        for(int j=0; j<column_cap; j++)
        {
            if(column_cap > n_dimension){break;}
            cout << matrix[i][j] << "\t";
        }
        column_cap++;
        cout << endl;
    }

    column_cap = 1;

    return 0;
}


/* Inferior diagonal of a matrix */
void infDiag()
{
/*
    int o=1;
    for(int i=0; i<m;i++){
        for(int j=0; j<o; j++){
            cout << "Enter the number to put in the ["<<i<<"] "<<"["<<j<<"] position: ";
            cin>> v;
            matrix[i][j]=v;
            cout<<"\n";
        }
        o++;
        cout<<"\n";
    }
    for(int k=0; k<m;k++){
        for(int l=0; l<n; l++){
            cout << "["<<matrix[k][l]<<"] ";
        }
        cout<<"\n";
    }
*/
}
