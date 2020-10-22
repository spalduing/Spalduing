#include <iostream>

using namespace std;

int histogram();
int histogram2(vector<int> &v,int s);

int main()
{

    return 0;
}


/* Draw an histogram to the given set of numbers*/
int histogram()
{
    int n[5];
    int v;
    for(int j=0; j<5; j++){
    cout<<"Enter a number: ";
    cin>>v;
    n[j]=v;
    }
    for(int i=0; i<5;i++){
            cout<<n[i]<<" ";
            for(int k=0;k<n[i];k++){
        cout << "*";
        }
        cout << "\n";
    }
        return 0;

}

/* Draw an histogram to the given set of numbers*/
int histogram2(vector<int> &v,int s)
{
    for(int i=0; i<s;i++){
            cout<<i<<": "<< v[i] << " ";
            for(int k=0;k<v[i];k++){
        cout << "*";
        }
        cout << "\n";
    }
        return 0;

}
