#include <iostream>
#include <vector>

using namespace std;

int display_histograms();
int display_histograms2(vector<int> &v,int s);

int main()
{
    vector<int> histogram = {3,7,4,5,8,2};

    cout << " FIRST DISPLAY HISTOGRAM METHOD" << endl;
    cout << " ================================= " << endl;

    display_histograms();

    cout << endl << endl;

    cout << " FIRST DISPLAY HISTOGRAM METHOD" << endl;
    cout << " ================================= " << endl;

    display_histograms2(histogram, sizeof(histogram)/sizeof(int));

    return 0;
}


/* Draw an histogram to the given set of numbers*/
int display_histograms()
{
    int historgram[5] = {};
    int number_elements;
    int index = 0;

    for(int row=0; row<5; row++){
        cout<<"Enter a number of elements for this row: ";

        cin >> number_elements;

        historgram[row]=number_elements;
    }

    cout << endl;

    for(int i=0; i<5;i++){
        index = i;
        cout<< index + 1 <<": ";

        for(int j=0;j<historgram[i];j++){
            cout << "*";
        }
    cout << "\n";
    }

    return 0;

}

/* Draw an histogram to the given set of numbers*/
int display_histograms2(vector<int> &v,int s)
{
    int index;
    for(int i=0; i<s;i++){
        index = i;
        cout<< index + 1 <<": "<< v[i] << " ";

        for(int k=0;k<v[i];k++){
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
