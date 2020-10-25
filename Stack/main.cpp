#include <iostream>

using namespace std;

template<class T>
class Stack
{
public:
    class Node;
private:
    int l_size;
    Node *top;

public:
    Stack():l_size(0),top(NULL){}

    int getSize()const{return l_size;}
    Node *getTop()const{return top;}

    void setSize(int _l_size){l_size=_l_size;}
    void setTop(Node *_top){top=_top;}

    bool isEmpty(){return getSize()==0;}

    void clear_(){
        Node *trv=top;
        while(trv!=NULL){
            Node *temp=trv->getPrev();
            trv->setValue(NULL);
            trv->setPrev(NULL);
            trv=temp;
            temp=NULL;
        }
        trv=NULL;
        top=NULL;
        l_size=0;
    }
    bool isClear(){return (top==NULL && l_size==0);}

    void push(T _value){
        if(isEmpty()){
            top=new Node(_value,NULL);
            l_size++;
        }else{
            Node *temp=new Node(_value,top);
            top=temp;
            temp=NULL;
            l_size++;
        }
    }
    void pop(){
        if(isEmpty()){
            return;
        }else{
            Node *temp=top->getPrev();
            top->setValue(NULL);
            top->setPrev(NULL);
            top=temp;
            temp=NULL;
            l_size--;
        }
    }
    T pick_up(){return top->getValue();}
class Node;
friend class Node;
class Node
{
private:
    T value;
    Node *prev;
public:
    Node(T _value,Node *_prev): value(_value),prev(_prev){}

    T getValue()const{return value;}
    Node *getPrev()const{return prev;}

    void setValue(T _value){value=_value;}
    void setPrev(Node *_prev){prev=_prev;}
};
class iterator;
friend class iterator;
class iterator
{
private:
    Stack s;
    int index;
    T current=s.top->getValue();
    Node *_prev=s.top->getPrev();
public:
    iterator(Stack &_s): s(_s),index(0){}
    iterator(Stack &_s,bool): s(_s),index(s.l_size){}

    Stack getStack()const{return s;}
    int getIndex()const{return index;}

    T operator*()const{
        //if(index==l.l_size-1){
            return current;
        //}
    }

    T &operator--(){
        if(index==s.l_size){
            --index;
            return current;
        }
        if(_prev==NULL){
            throw "Index'l move out of range.";
        }else{
            --index;
            current=_prev->getValue();
            _prev=_prev->getPrev();
            return current;
        }
    }
    T &operator--(int){
        if(index==s.l_size){
            --index;
            return current;
        }
        if(_prev==NULL){
            throw "Index'l move out of range.";
        }else{
            --index;
            current=_prev->getValue();
            _prev=_prev->getPrev();
            return current;
        }
    }

    bool operator==(const iterator &other){return index==other.index;}
    bool operator!=(const iterator &other){return index!=other.index;}

    friend ostream &operator<<(ostream &out,const iterator &it){
        return out<< *it;
    }
};
    iterator bottom(){return iterator(*this);}
    iterator top_(){return iterator(*this,true);}
};

bool isReverse(char c);
bool isReverseOfTop(char c,char t);
bool bracketMatch(Stack<char> &pile, string sentence );


int main()
{
    /////////////// THIS IS MY FORTH SUCCESED////////////////
    ///////////IMPLEMENTATION OF A DATA STRUCTURE////////////

    Stack<char> c;
    if(bracketMatch(c,"([]{})[]{}()")){
        cout<<"The sentence of brackets matches"<<endl;
    }else{
        cout<<"Not funny, DIDN'T match"<<endl;
    }

    try{

        Stack<int> s;
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        //s.pop();
        //cout<<s.pick_up()<<endl<<endl;

        while(!(s.isEmpty())){
            cout<<s.pick_up()<<endl;
            s.pop();
        }

    }catch(const char *msg){
        cout<<msg<<endl;
    }

    return 0;
}


bool isReverse(char c)
{
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

bool isReverseOfTop(char c,char t)
{
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
