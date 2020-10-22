#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void initialize_vector_rng(vector<int> &v,int amount);
void initialize_array_rng(int a[],int amount);

int main()
{
    vector<int> numbers;
    int numbers2[5];

    initialize_vector_rng(numbers, 5);
    initialize_array_rng(numbers2, 5);

    int s_vector = sizeof(numbers)/sizeof(int);
    int s_array = sizeof(numbers2)/sizeof(int);

    for(int i=0; i<s_vector; i++)
    {
        cout << numbers[i] << " " << flush;
    }

    cout << endl;

    for(int i=0; i<s_array; i++)
    {
        cout << numbers2[i] << " " <<  flush;
    }

    return 0;
}

void initialize_vector_rng(vector<int> &v,int amount)
{
    srand(time(NULL));
    for(int i=0; i<amount; i++){
        v.push_back(rand() % 100 + 0);
    }
}

void initialize_array_rng(int a[],int amount)
{
    srand(time(NULL));
    for(int i=0; i<amount; i++){
        a[i]= rand() % 100 + 0;
    }
}
