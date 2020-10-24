#include <iostream>
#include <vector>

using namespace std;

std::vector<int> tribonacci(std::vector<int> signature, int n);

int main()
{
    vector<int> vect = {1,1,1};

    vector<int> answ = tribonacci(vect, 8);
    int s = sizeof(answ)/sizeof(int);

    for(int i=0; i<answ.size(); i++)
    {
        cout << answ[i] << " " << flush;
    }

    return 0;
}

/*
*   A fibonacci numbers, commonly denoted Fn's form of a sequence
*   such tat each number is the som of the two preciding ones,
*   starting from 0 and 1.
*
*   Our tribonacci sequence instead, every new number is the
*   result of the sum of the three previus numbers of a given
*   signature.
*
*   Our method returns a vector wiht the first n tribonacci
*   elements (signature included) of the so seeded sequence
*   such that each number is the sum of the tree preceding
*   ones,starting from a seed of three numbers.
*
*
*/
std::vector<int> tribonacci(std::vector<int> signature, int n)
{

    std::vector<int> result;
    result=signature;
    if(n==0){
        result.pop_back();
        result.pop_back();
        result.pop_back();
        return result;
    }else if(n==1){
        result.pop_back();
        result.pop_back();
        return result;
    }else if(n==2){
        result.pop_back();
        return result;
    }else{
        for(int i=3;i<n;i++){
            result.push_back(result[i-3]+result[i-2]+result[i-1]);
        }
    }

    return result;
}
