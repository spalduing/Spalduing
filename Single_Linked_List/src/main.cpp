#include <iostream>

using namespace std;

template<class T>
class SingleLinkedList
{
public:
    class Node;
private:
    int l_size;
    Node *head;
    Node *tail;

public:
    SingleLinkedList(){
        l_size=0;
        head=NULL;
        tail=NULL;
    }
    SingleLinkedList(int _l_size): l_size(_l_size){
        head=tail=new Node(NULL,NULL);
        int c=1;
        while(c<_l_size){
            tail->setNex(new Node(NULL,NULL));
            c++;
        }
    }
    Node *getHead() const{return head;}
    Node *getTail() const{return tail;}
    int getSize() const{return l_size;}

    void setHead(Node *_head){head=_head;}
    void setTail(Node *_tail){tail=_tail;}

    bool isEmpty(){
        return getSize()==0;
    }
    void clear_(){
        Node *trv_1=head;
        while(trv_1!=NULL){
            Node *temp=trv_1->getNex();
            trv_1->setValue(NULL);
            trv_1->setNex(NULL);
            trv_1=temp;
        }
        setTail(NULL);
        setHead(NULL);
        trv_1=NULL;
        l_size=0;
    }
    bool isClear(){
        return (((tail&&head)==NULL) && l_size==0);
    }
    void push__front(T _value){
        Node *trv=head;
        if(isEmpty()){
            head=tail=new Node(_value,NULL);
            l_size++;
        }else{
            head=new Node(_value,trv);
            l_size++;
        }
    }
    void pop__front(){
        Node *trv=head->getNex();
        head->setValue(NULL);
        head->setNex(NULL);
        head=trv;
        trv=NULL;
        --l_size;
    }
    void push__back(T _value){
        if(isEmpty()){
            head=tail=new Node(_value,NULL);
            l_size++;
        }else if(head->getNex()==NULL){
            tail=new Node(_value,NULL);
            head->setNex(tail);
            l_size++;
        }else{
            Node *temp=new Node(_value,NULL);
            tail->setNex(temp);
            tail=temp;
            l_size++;
        }
    }
    void pop__back(){
        Node *trv_1=head;
        Node *trv_2=head->getNex();
        while(trv_2->getNex()!=NULL){
            trv_1=trv_1->getNex();
            trv_2=trv_2->getNex();
        }
        tail=trv_1;
        trv_1->setNex(NULL);
        trv_2->setValue(NULL);
        trv_2->setNex(NULL);
        trv_1==NULL;
        trv_2=NULL;
        --l_size;
    }
    void set__at(int position, T _value){
        int c=0;
        Node *trv=head;
        while(c<position){
            trv=trv->getNex();
            c++;
        }
        trv->setValue(_value);
    }
    void insert__at(int position, T _value){
        int c=0;
        if(position>getSize() || position < 0){
            throw "Position out of bound";
        }
        Node *trv_1=head;
        Node *trv_2=head->getNex();

        while(c<position){
            trv_1=trv_1->getNex();
            trv_2=trv_2->getNex();
            c++;
        }
        if(trv_1==head){
            head=new Node(_value,trv_1);
            l_size++;

        }else if(trv_2==NULL){
           push__back(_value);
        }else{
        T t= trv_1->getValue();
        trv_1->setValue(_value);
        trv_1->setNex(NULL);
        Node *temp2=new Node(t,trv_2);
        trv_1->setNex(temp2);
        temp2=NULL;
        l_size++;
        }
    }

    void add__at(int position, T _value){
        int c=0;
        Node *trv_1=head;
        Node *trv_2=head->getNex();
        while(c<position){
            trv_1=trv_1->getNex();
            trv_2=trv_2->getNex();
            c++;
        }
        if(trv_1==head){
            head=new Node(_value,trv_1);
        }else if(trv_2==NULL){
            push__back(_value);
        }else{
            Node *temp=new Node(_value,trv_2);
            trv_1->setNex(temp);
            temp=NULL;
            l_size++;
        }
    }
    void remove__at(int position){
        int c=0;
        Node *trv_0=NULL;
        Node *trv_1=head;
        Node *trv_2=head->getNex();
        while(c<position){
            trv_0=trv_1;
            trv_1=trv_1->getNex();
            trv_2=trv_2->getNex();
            c++;
        }
        if(trv_1==head){
            pop__front();
        }else if(trv_2==NULL){
            pop__back();
        }else{
            trv_0->setNex(trv_2);
            trv_1->setValue(NULL);
            trv_1->setNex(NULL);
            trv_0=NULL;
            trv_1=NULL;
            trv_2=NULL;
            --l_size;
        }

    }

    void display_list(){
    Node *trv=head;
    while(trv!=NULL){
        cout<<trv->getValue()<<" "<<flush;
        trv=trv->getNex();
    }
    trv=NULL;
    }

    T pick_front(){return head->getNex();}

class Node;
friend class Node;
 class Node
{
private:
    T value;
    Node *nex;
public:
    Node(T _value, Node *_nex):value(_value),nex(_nex){}

    T getValue()const{return value;}
    void setValue(T _value){value=_value;}

    Node *getNex()const{ return nex;}
    void setNex(Node *_nex){nex=_nex;}
};

class iterator;
friend class iterator;
class iterator
{
    SingleLinkedList l;
    int index;
    T current=l.head->getValue();
    Node *_nex=l.head->getNex();
public:
    iterator(SingleLinkedList &_l):l(_l),index(0){}
    iterator(SingleLinkedList &_l,bool):l(_l),index(l.l_size){}

    int getIndex() const{return index;}
    SingleLinkedList getL() const{return l;}

    void setNex(Node *nnex){ _nex=nnex;}
    void setCurrent(T _current){current=_current;}

    T operator*() const{return current;}

    T &operator++(){
        if(index==0){
            ++index;
            return current;
        }
        if( !(_nex!=l.tail->getNex()) ){
            throw "Index'l move out of range";
        }else{
            ++index;
            current=_nex->getValue();
            _nex=_nex->getNex();
            return current;
        }
    }

    T &operator++(int){
        if(index==0){
            ++index;
            return current;
        }
        if( !(_nex!=l.tail->getNex()) ){
            throw "Index'l move out of range";
        }else{
            ++index;
            current=_nex->getValue();
            _nex=_nex->getNex();
            return current;
        }
    }

    bool operator==(const iterator &other){
        return index==other.index;
    }
    bool operator!=(const iterator &other){
        return index!=other.index;
    }

    friend ostream &operator<<(ostream &out,const iterator &it){
        return out<< *it;
    }

};

    iterator begin(){return iterator(*this);}
    iterator end(){return iterator(*this,true);}

    T get(iterator it){
        SingleLinkedList l=it.l;
        return l.value;
    }

};


int main()
{

        ///////////////// THIS IS MY SECOND SUCCESED//////////////
        //////////////IMPLEMENTATION OF A DATA STRUCTURE//////////
    try{
        SingleLinkedList<int> l;
        l.push__back(2);
        l.push__back(3);
        l.push__back(4);
        l.push__back(5);
        l.insert__at(0,1);
        l.insert__at(1,8);
        //l.set_at(1,1);
        l.add__at(1,1);
        l.push__front(0);
        l.push__front(0);
        //l.pop__front();
        //l.pop__back();
        l.remove__at(3);
        SingleLinkedList<int>::iterator be=l.begin();
        SingleLinkedList<int>::iterator en=l.end();
        //++en;
        //be++;

        //auto a=be;

        cout<<"Begin: "<<be.getIndex()<<endl;
        cout<<"l_size: "<<l.getSize()<<endl;
        cout<<"End: "<<en.getIndex()<<endl;
        cout<<"This is the 1'st element of the list 2: "<<be<<endl<<endl;
        cout<<"This is the 1'st element of the list 2: "<<be<<endl<<endl;
        //be++;
        //cout<<"This is the last element of the list: "<<en<<endl<<endl;
        while(be != en){
            cout<<"This print an element of the list: "<<be++<<endl;
        }

        l.clear_();
        if(l.isClear()){cout<<"The list is clear!"<<endl;}

    }catch(const char *msg){
        cout<<msg<<endl;
    }

    return 0;
}
