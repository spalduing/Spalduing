#include <iostream>

using namespace std;

template<class T>
class DinamicArray
{
private:
    int leng;
    int capacity;
    T *arr;
    //int indexOfIt(iterator it);
public:
    DinamicArray(): leng(0),capacity(0),arr(NULL){
    }
    DinamicArray(int capacity){
        if(capacity<0){
            throw "Invalid capacity";
        }
        leng=0;
        this->capacity=capacity;
        arr=new T[capacity];

    }
    ~DinamicArray(){
        delete [] arr;
    }
    int getSize() const{
        return leng;
    }
    bool isEmpty(){
        return getSize()==0;
    }

    T get(int pos){ return arr[pos];}

    void clearD(){
    for(int i=0;i<capacity;i++)
        arr[i]==NULL;
    //The indentation is necessary!
    leng=0;
    }
    void setAt(int pos,T obj){
        arr[pos]=obj;
    }

    void add(T obj){
        if(leng+1>=capacity){
            if(capacity==0) capacity=1;
            else capacity *=2;
            T *new_arr=new T[capacity];
            for(int i=0;i<leng;i++){
                new_arr[i]=arr[i];
            }
            arr=new_arr;
        }
            arr[leng++]=obj;

    }

    void pop(){
       //int index=leng--;
        arr[leng--]=NULL;
    }
    void remmoveAt(int index){
        if(index<0 || index>leng){
            throw "Index out of range";
        }
        if(index==leng){
            pop();
        }else{
            T *new_arr=new T[capacity];
            for(int i=0;i<leng;i++)
                new_arr[i]==NULL;
            int a=0;
            for(int i=0;i<leng;){
                if(i==index||a==1){
                   new_arr[i]= arr[++i];
                   a=1;
                }else{
                new_arr[i]=arr[i];
                i++;
                }
            }
            --leng;
            arr=new_arr;
        }
    }
class iterator;
friend class iterator;
class iterator
{
    DinamicArray a;
    int index;
public:
    iterator(DinamicArray &arra):a(arra),index(0){
    }
    iterator(DinamicArray &arra,bool):a(arra),index(a.leng){
    }
    void print(){
        cout<<"Hello from iterator: "<<T()<<endl;
    }
    int getIndex() const{return index;}
    DinamicArray getA() const{return a;}
    void setIndex(int &ind){index=ind;}
    void setA(DinamicArray &arra){a=arra;}

    T operator*() const{return a.arr[index];}

    T &operator++(){
        if(++index > a.leng){
            throw "Index'l move out of range";
        }
        return a.arr[++index];
        //++index;
        //return *this;
    }

    T &operator--(){
    if(--index < 0){
            throw "Index'l move out of range";
        }
    return a.arr[--index];
    //--index;
    //return *this;
    }

    T &operator++(int){
        if(index == a.leng){
            throw "Index'l move out of range";
        }
        return a.arr[index++];
        //iterator dA=*this;
        //++*this;
        //return dA;
    }

    T &operator--(int){
    if(index-- < 0){
            throw "Index'l move out of range";
        }
    return a.arr[index--];
    //iterator dA=*this;
    //++*this;
    //return dA;
    }

    iterator &operator+=(int amount){
    //requires(index + amount < a.leng,"iterator moved out of range");
        index += amount;
        return *this;
    }
    iterator &operator-=(int amount){
        index -= amount;
        return *this;
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
    T get(iterator &it) const{
        int pos=it.getIndex();
            return arr[pos];

        }
};


int main()
{
        //////////////// THIS IS MY FIRST SUCCESED////////////////
    //////////////IMPLEMENTATION OF A DATA STRUCTURE//////////

    try{
    DinamicArray<int> d;
    //DinamicArray<int> da(-1);
    cout<<"Size: "<<d.getSize()<<endl;
    d.add(1);
    d.add(2);
    d.add(3);
    d.add(4);
    cout<<"Size: "<<d.getSize()<<endl<<endl;
    //d.pop();
    //d.remmoveAt(4);

    DinamicArray<int>::iterator it=d.begin();
    DinamicArray<int>::iterator itE=d.end();

    cout<< it <<endl<<endl;
    cout<< d.get(it) <<endl<<endl;
    cout<<it.getIndex()<<endl;
    cout<<itE.getIndex()<<endl<<endl;

     while(it!=itE){
        //cout<<d.get(it++)<<endl;
        //cout<<d.get(++it)<<endl;
        cout<<it++<<endl;
    }
    cout<<endl<<endl;

    for(int i=0;i<d.getSize();i++){
        cout<<d.get(i)<<endl;
    }
    cout<<endl;

    for(DinamicArray<int>::iterator it=d.begin();
    it!=itE;it++){
       cout<<it<<endl;
    }
    cout<<endl<<endl;

    }catch(const char *msg){
        cout<<msg<<endl;
    }


    return 0;
}
