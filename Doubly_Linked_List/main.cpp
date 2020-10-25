#include <iostream>

using namespace std;

template<class T>
class DoublyLinkedList
{
public:
    class Node;
private:
    int l_size;
    Node *head;
    Node *tail;
public:
    DoublyLinkedList(): l_size(0),head(NULL),tail(NULL){}
    DoublyLinkedList(int _l_size): l_size(_l_size),head(NULL),tail(NULL){}

    int getSize()const{return l_size;}
    Node *getHead()const{return head;}
    Node *getTail()const{return tail;}

    void setHead(Node *_head){head=_head;}
    void setTail(Node *_tail){tail=_tail;}

    bool isEmpty(){return getSize()==0;}

    void clear_(){
        Node *trv=head;
        while(trv!=NULL){
            Node *temp=trv->getNex();
            trv->setValue(NULL);
            trv->setPrev(NULL);
            trv->setNex(NULL);
            trv=temp;
        }
        setHead(NULL);
        setTail(NULL);
        trv=NULL;
        l_size=0;
    }

    bool isClear(){
        return (((tail&&head)==NULL) && l_size==0);
    }

    void push__front(T _value){
        if(isEmpty()){
            head=tail=new Node(_value,NULL,NULL);
            l_size++;
        }else{
            Node *temp=new Node(_value,NULL,head);
            head->setPrev(temp);
            head=temp;
            temp=NULL;
            l_size++;

        }
    }
    void pop__front(){
        if(isEmpty()){
                return;
        }else{
        Node *temp=head->getNex();
        temp->setPrev(NULL);
        head->setValue(NULL);
        head->setNex(NULL);
        head=temp;
        temp=NULL;
        --l_size;
        }
    }
    void push__back(T _value){
        if(isEmpty()){
            head=tail=new Node(_value,NULL,NULL);
            l_size++;
        }else if(head->getNex()==NULL){
            tail=new Node(_value,head,NULL);
            head->setNex(tail);
            l_size++;
        }else{
            Node *temp=new Node(_value,tail,NULL);
            tail->setNex(temp);
            tail=temp;
            temp=NULL;
            l_size++;
        }
    }
    void pop__back(){
        if(isEmpty()){
                return;
        }else{
        Node *temp=tail->getPrev();
        temp->setNex(NULL);
        tail->setValue(NULL);
        tail->setPrev(NULL);
        tail=temp;
        temp=NULL;
        --l_size;
        }
    }
    void insert__at(int position, T _value){
        int c=0;
        Node *trv=head;
        while(c<position){
            trv=trv->getNex();
            c++;
        }
        if(trv==head){
            push__front(_value);
        }else if(trv->getNex()==NULL){
            push__back(_value);
        }else{
        Node *new_node=new Node(_value,trv->getPrev(),trv);
        trv->getPrev()->setNex(new_node);
        trv->setPrev(new_node);
        trv=NULL;
        new_node=NULL;
        l_size++;
        }
    }
    void add__at(int position, T _value){
        int c=0;
        Node *trv=head;
        while(c<position){
            trv=trv->getNex();
            c++;
        }
        if(trv==head){
            push__front(_value);
        }else if(trv->getNex()==NULL){
            push__back(_value);
        }else{
        Node *new_node=new Node(_value,trv,trv->getNex());
        trv->getNex()->setPrev(new_node);
        trv->setNex(new_node);
        trv=NULL;
        new_node=NULL;
        l_size++;
        }
    }

    void remove__at(int position){
        int c=0;
        Node *trv=head;
        while(c<position){
            trv=trv->getNex();
            c++;
        }
        if(trv==head){
            pop__front();
        }else if(trv->getNex()==NULL){
            pop__back();
        }else{
            trv->getPrev()->setNex(trv->getNex());
            trv->getNex()->setPrev(trv->getPrev());
            trv->setValue(NULL);
            trv->setPrev(NULL);
            trv->setNex(NULL);
            trv=NULL;
            l_size--;
        }
    }

    void display_list(){
    Node *trv=head;
    while(trv!=NULL){
        cout<<trv->getValue()<< " " << flush;
        trv=trv->getNex();
    }
    trv=NULL;
    }
    T pick_last(){return tail->getValue();}
    T pick_front(){return head->getValue();}

class Node;
friend class Node;
class Node
{
private:
    T value;
    Node *prev;
    Node *nex;
public:
    Node(T _value, Node *_prev, Node *_nex): value(_value),prev(_prev),nex(_nex){}

    T getValue()const{return value;}
    Node *getPrev()const{return prev;}
    Node *getNex()const{return nex;}

    void setValue(T _value){value=_value;}
    void setPrev(Node *_prev){prev=_prev;}
    void setNex(Node *_nex){nex=_nex;}

};

class iterator;
friend class iterator;
class iterator
{
private:
    DoublyLinkedList l;
    int index;
    T current_head=l.head->getValue();
    T current_tail=l.tail->getValue();
    Node *_prev=l.tail->getPrev();
    Node *_nex=l.head->getNex();
public:
    iterator(DoublyLinkedList &_l): l(_l),index(0){}
    iterator(DoublyLinkedList &_l,bool): l(_l),index(l.l_size){}

    DoublyLinkedList getList()const{return l;}
    int getIndex()const{return index;}

    T operator*()const{
        if(index==0){
            return current_head;
        }
        if(index==l.l_size-1){
            return current_tail;
        }
    }

    T &operator++(){
        if(index==0){
            ++index;
            return current_head;
        }
        if(_nex==l.tail->getNex()){
            throw "Index'l move out of range.";
        }else{
            ++index;
            current_head=_nex->getValue();
            _nex=_nex->getNex();
            return current_head;
        }
    }
    T &operator++(int){
        if(index==0){
            ++index;
            return current_head;
        }
        if(_nex==l.tail->getNex()){
            throw "Index'l move out of range.";
        }else{
            ++index;
            current_head=_nex->getValue();
            _nex=_nex->getNex();
            return current_head;
        }
    }
    T &operator--(){
        if(index==l.l_size){
            --index;
            return current_tail;
        }
        if(_prev==l.head->getPrev()){
            throw "Index'l move out of range.";
        }else{
            --index;
            current_tail=_prev->getValue();
            _prev=_prev->getPrev();
            return current_tail;
        }
    }
    T &operator--(int){
        if(index==l.l_size){
            --index;
            return current_tail;
        }
        if(_prev==l.head->getPrev()){
            throw "Index'l move out of range.";
        }else{
            --index;
            current_tail=_prev->getValue();
            _prev=_prev->getPrev();
            return current_tail;
        }
    }

    bool operator==(const iterator &other){return index==other.index;}
    bool operator!=(const iterator &other){return index!=other.index;}

    friend ostream &operator<<(ostream &out,const iterator &it){
        return out<< *it;
    }
};
    iterator begin(){return iterator(*this);}
    iterator end(){return iterator(*this,true);}
};

int main()
{
    //////////////////THIS IS MY THIRD SUCCESED////////////////
    /////////////IMPLEMENTATION OF A DATA STRUCTURE////////////
        try{
        DoublyLinkedList<int> d;
        //d.push__front(0);
        //d.push__front(0);
        d.push__back(2);
        d.push__back(3);
        d.push__back(4);
        d.push__back(5);
        //d.insert__at(0,1);
        d.insert__at(1,8);
        //l.set_at(1,1);
        d.add__at(1,7);

        //d.pop__front();
        //d.pop__back();
        d.remove__at(3);
        DoublyLinkedList<int>::iterator be=d.begin();
        DoublyLinkedList<int>::iterator en=d.end();
        //++en;
        //be++;

        //auto a=be;

        cout<<"Begin: "<<be.getIndex()<<endl;
        cout<<"l_size: "<<d.getSize()<<endl;
        cout<<"End: "<<en.getIndex()<<endl;
        cout<<"This is the 1'st element of the list 2: "<<be<<endl<<endl;
        cout<<"This is the 1'st element of the list 2: "<<be<<endl<<endl;
        //be++;
        //cout<<"This is the last element of the list: "<<en<<endl<<endl;
        while(be != en){
            cout<<"This print an element of the list: "<<be++<<endl;
        }

        d.clear_();
        if(d.isClear()){cout<<"The list is clear!"<<endl;}

    }catch(const char *msg){
        cout<<msg<<endl;
    }

    return 0;
}
