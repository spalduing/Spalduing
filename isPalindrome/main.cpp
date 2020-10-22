#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool isEven(int n);
void dispChar(vector<char> &v );
bool isPalindrome2(string w);
bool isPalindrome(string p);


int main()
{
    if(isPalindrome("arenera")){
        cout << endl << "Es palindroma" << endl;
    }else{
        cout << endl <<"No es palindroma" << endl;
    }

    return 0;
}

/* Return true if a word is a palidrome word*/
bool isPalindrome(string p)
{
    vector<char> v1;
    vector<char> v2;
    double psize;

    if(!isEven(p.size())){

        for(int i=0;i<p.size();i++)
        psize++;
        string s1=p.substr(0,ceil(psize/2)-1);
        string s2=p.substr(ceil(psize/2),p.size());

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
        string s1=p.substr(0,p.size()/2);
        string s2=p.substr(p.size()/2,p.size());
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

bool isPalindrome2(string w)
{
    vector<char> v1,v2;
    for(int i=0;i<w.size();i++){
        v1.push_back(w[i]);
        v2.push_back(w[i]);
    }
    reverse(v2.begin(),v2.end());
    dispChar(v1);
    cout<<"\t";
    dispChar(v2);
    return (v1==v2);
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
