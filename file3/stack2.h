#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class AbstractStack{
public:
    virtual void push(T value)=0;
    virtual T pop()=0;
    virtual T top() const=0;
    virtual bool isEmpty() const=0;
    virtual bool isFull() const=0;
    virtual ~AbstractStack(){}
};
template <typename T>
class myStack : public AbstractStack<T>{
    T* arr;
    T* minArr;
    int topIndex;
    int minTop;
    int size;
public:
    myStack(int s){
        size=s;
        arr=new T[size];
        minArr=new T[size];
        topIndex=-1;
        minTop=-1;
    }
 void push(T value){
        if(isFull()){
            cout<<"Stack Full\n";
            return;
        }

        arr[++topIndex]=value;

        if(minTop==-1 || value<=minArr[minTop])
            minArr[++minTop]=value;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack Empty\n";
            return T();
        }

        T removed=arr[topIndex--];

        if(removed==minArr[minTop])
            minTop--;

        return removed;
    }
 T top() const{
        if(isEmpty()) return T();
        return arr[topIndex];
    }

    bool isEmpty() const{
        return topIndex==-1;
    }

    bool isFull() const{
        return topIndex==size-1;
    }

    T getMin() const{
        if(minTop==-1) return T();
        return minArr[minTop];
    }

    void display() const{
        if(isEmpty()){
            cout<<"Stack Empty\n";
            return;
        }

        for(int i=topIndex;i>=0;i--)
            cout<<arr[i]<<" ";

        cout<<endl;
    }
  ~myStack(){
        delete[] arr;
        delete[] minArr;
    }
};

#endif
