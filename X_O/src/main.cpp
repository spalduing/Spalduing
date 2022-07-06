#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string>

using namespace std;

bool XO(const std::string& str);

int main()
{
    string phrase;
    cout << "Enter a word/phrase: ";
    cin >> phrase;
    if(XO(phrase)  ){
        cout << "The string: " << phrase << "   HAVE the same number of 'O's and 'X's. " << endl;
    }else{
        cout << "The string: " << phrase << "   DON'T have the same number of 'O's and 'X's. " << endl;
    }

    return 0;
}

/* Return true if a string have the same number of O's and X's */
bool XO(const std::string& str)
{

    int x_number = 0,o_number = 0;
    char c = ' ';
    //cout << x_number << "  " << o_number << endl;

    for(int i=0; i<str.size();i++){
        c = str[i];
        c = tolower(c);

        switch(c){
        case 'x':
           x_number++;
            break;

        case 'o':
            o_number++;
            break;
        //default:
          //  break;
        }
    }
    //cout << x_number << "  " << o_number << endl;

    return (x_number == o_number);

}
