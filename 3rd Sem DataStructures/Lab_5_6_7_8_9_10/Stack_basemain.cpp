#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100
class stack {
    public:
        int top;
        int a[MAXSIZE];

        stack(){
            top=-1;
        }
        int peep(){
            return a[top];
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
             return (top==MAXSIZE-1);
        }
        void push(int ele) {
            if (isFull())
                cout<<"Stack is full"<<endl;
            else
                a[++top]=ele;
        }
        int pop(){
            if (isEmpty()){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            else
                return a[top--];
        }
        void display(){
            if(isEmpty())
                cout <<"Stack is empty"<< endl;
            else{
                for(int i=top;i>=0;i--){
                    cout<<a[i]<<" ";
                }
            }
            cout << endl;
        }
};
int main(){
    int num,n,base,rem;
    cout<<"Enter decimal number:";
    cin>>num;
    n=num;
    cout<<"Enter base:";
    cin>>base;
    stack s1;
    while(n!=0){
        rem=n%base;
        s1.push(rem);
        n/= base;
    }
    s1.display();
    cout<<num<<" in base "<<base<<" is:"<<endl;
    while(!s1.isEmpty()){
        if(s1.peep()>=10){
            cout<<char(55+int(s1.peep()));
        }
        else
            cout<<s1.peep();
        s1.pop();
    }
}
