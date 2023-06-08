#include <iostream>
#define MAXSIZE 100
using namespace std;

class multi
{
private:
    int s[MAXSIZE];
    int t1,t2;
public:
    multi(){
        t1=-1;
        t2=MAXSIZE;
    }
    void pop1(){
        if(t1==-1)
            cout<<"Stack 1 is empty";
        else
            cout<<"Popped from stack 1:"<<s[t1--]<<endl;
    }
    void pop2(){
        if(t2==MAXSIZE)
            cout<<"Stack 2 is empty"<<endl;
        else
            cout<<"Popped from stack 2:"<<s[t2++]<<endl;
    }
    void push1(int val){
        if(t1<t2-1)
            s[++t1]=val;
        else
            cout<<"Stack 1 is full";
    }
    void push2(int val){
        if(t1<t2-1)
            s[--t2]=val;
        else
            cout<<"Stack 1 is full";
    }
    void display1(){
        if(t1==-1)
            cout<<"Stack 1 is empty";
        else{
        int i;
        cout<<"Stack 1:"<<endl;
        for(i=0;i<=t1;i++){
            cout<<s[i]<<endl;
        }}
    }
    void display2(){
        if(t2==MAXSIZE)
            cout<<"Stack 2 is empty";
        else{
        int i;
        cout<<"Stack 2:"<<endl;
        for(i=MAXSIZE;i>=t2;i--){
            cout<<s[i]<<endl;
        }}
    }
};
int main()
{
    multi m1;
    m1.push1(10);
    m1.push1(20);
    m1.push2(100);
    m1.pop2();
    m1.pop2();
    m1.pop1();
    m1.push1(20);
    m1.push1(30);
    m1.push1(40);
    m1.push2(100);
    m1.push2(90);
    m1.push2(80);
    m1.push2(70);
    m1.display1();
    m1.display2();
    return 0;
}
