#include <iostream>

using namespace std;

int display_upper_diagonal();
int main()
{
    display_upper_diagonal();
    return 0;
}

/* Superior diagonal of a matrix */
int display_upper_diagonal()
{
    int m_dimension, n_dimension, number = 0;

    //ENTERING THE DIMENSION OF THE ARRAY//
    cout << "Enter the m dimension of the matrix: ";
    cin >> m_dimension;
    cout << "Enter the n dimension of the matrix: ";
    cin >> n_dimension;

    int matrix[m_dimension][n_dimension];

    //INITIALIZING THE ARRAY WITH ZEROS//
    for(int i=0; i<m_dimension;i++){
        for(int j=0; j<n_dimension; j++){
            matrix[i][j]=0;
            cout<<"\n";
        }
        cout<<"\n";
    }

    int column_cap = n_dimension;

    //ENTERING THE NUMBERS//
    for(int i=0; i<m_dimension;i++){
        for(int j=0; j<column_cap; j++){
            cout << "Enter the number to put in the ["<<i<<"] "<<"["<<j<<"] position: ";
            cin>> number;
            matrix[i][j] = number;
            cout<<"\n";
        }
        column_cap--;
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
