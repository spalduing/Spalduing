#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool isEven(int n);
void dispChar(vector<char> &v );
bool isPalindrome(string word);
bool isPalindrome2(string word);



int main()
{
    if(isPalindrome("arenera")){
        cout << endl << "Es palindroma" << endl;
    }else{
        cout << endl <<"No es palindroma" << endl;
    }

    return 0;
}

//WHAT A SURPRICE, my code is actually faster than the//
/////////////easier form of implement this//////////////
/* Return true if a word is a palidrome word*/
bool isPalindrome(string word)
{
    vector<char> v1;
    vector<char> v2;
    double psize = 0;

    if(!isEven(word.size())){

        for(int i=0;i<word.size();i++)
        psize++;
        string s1=word.substr(0,ceil(psize/2)-1);
        string s2=word.substr(ceil(psize/2),word.size());

        for(int j=0; j<s1.size();j++){
            v1.push_back(s1[j]);
            v2.push_back(s2[j]);
        }

        reverse(v2.begin(),v2.end());

        dispChar(v1);
        cout<<"\t";
        dispChar(v2);
        return (v1==v2);
    }else{
        string s1=word.substr(0,word.size()/2);
        string s2=word.substr(word.size()/2,word.size());
        for(int k=0; k<s1.size();k++){
            v1.push_back(s1[k]);
            v2.push_back(s2[k]);
        }

    reverse(v2.begin(),v2.end());
    dispChar(v1);
    cout<<"\t";
    dispChar(v2);

    return (v1==v2);
    }

}

bool isPalindrome2(string word)
{
    vector<char> vector1, vector2;
    for(int i=0;i<word.size();i++){
        vector1.push_back(word[i]);
        vector2.push_back(word[i]);
    }
    reverse(vector2.begin(),vector2.end());
    dispChar(vector1);
    cout<<"\t";
    dispChar(vector2);
    return (vector1 == vector2);
}

void dispChar(vector<char> &v )
{
    int s=v.size();
    for(int i=0; i<s; i++){
        cout<<v[i];
    }
}

bool isEven(int n)
{
    return ((n % 2) == 0);
}
