#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


bool isReverse(char c){
        switch(c){
        case ')':
        case '}':
        case ']':
            return true;
            break;
        default:
            return false;
            break;
            }
}
bool isReverseOfTop(char c,char t){
        switch(c){
        case ')':
            if(t=='('){return true;}
        case '}':
            if(t=='{'){return true;}
        case ']':
            if(t=='['){return true;}
            break;
        default:
            return false;
            break;
            }
}

//DUDE YOU MUST REMEMBER CREATE PUT YOUR STACK CLASS IN A LIBRIRY//
            //IF YOU WANT TO USE THE CLASS PROPERLY//
bool bracketMatch(Stack<char> &pile, string sentence )
{
    for(int i=0; i<sentence.size();i++){
        char c=sentence[i];
        if(pile.isEmpty()){
            if(isReverse(c)){
                return false;
            }else{
                pile.push(c);
            }
            }else if(isReverseOfTop(c,pile.pick_up())){
                pile.pop();
            }else if(!(isReverse(c))){
                pile.push(c);
            }else{
                return false;
            }
        }
        return pile.getSize() == 0;
}
