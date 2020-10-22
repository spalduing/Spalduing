#include <iostream>

using namespace std;

int display_reverse_upper_diagonal();

int main()
{
    display_reverse_upper_diagonal();
    return 0;
}

/* Reverse Superior diagonal of a matrix */
int display_reverse_upper_diagonal()
{
    int m_dimension, n_dimension, number = 0;

    //ENTERING THE DIMENSIONS OF THE MATRIX//
    cout << "Enter the m dimension of the matrix: ";
    cin >> m_dimension;
    cout << "Enter the n dimension of the matrix: ";
    cin >> n_dimension;

    int matrix[m_dimension][n_dimension];

    //INITIALIZING THE ARRAY WIHT ZEROS//
    for(int i=0; i<m_dimension;i++){
        for(int j=0; j<n_dimension; j++){
            matrix[i][j]=0;
            cout<<"\n";
        }
        cout<<"\n";
    }

    int column_cap=-1;

    //ENTERING THE NUMBERS INTO THE ARRAY//
    for(int i=0; i<m_dimension;i++){
        for(int j=n_dimension-1; j>column_cap; j--){
            cout << "Enter the number to put in the ["<<i<<"] "<<"["<<j<<"] position: ";
            cin >> number;
            matrix[i][j] = number;
            cout<<"\n";
        }
        column_cap++;
        cout<<"\n";
    }

    //DISPLAYING THE MATRIX//
    for(int k=0; k<m_dimension;k++){
        for(int l=0; l<n_dimension; l++){
            cout << "["<<matrix[k][l]<<"] ";
        }
        cout<<"\n";
    }
    return 0;
}
