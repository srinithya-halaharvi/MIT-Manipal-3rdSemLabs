#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
class Stack
{
    private:
        char arr[MAXSIZE];
        int top;
    public:
        Stack(){
             top=-1;
        }
        void push(char val){
            if(top==MAXSIZE-1)
                cout<<"Stack is full";
            else
                arr[++top]=val;
        }
        char pop(){
            if(top==-1){
                cout<<"Stack is empty";
                return 0;
            }
            else
                return arr[top--];
        }
};
int main()
{
    Stack s1;
    char str[MAXSIZE];
    int i,len,count=0;
    cout<<"Enter a string:";
    cin>>str;
    len=strlen(str);
    for(i=0;i<len;i++){
        s1.push(str[i]);
    }
    for(i=0;i<len;i++){
        if(str[i]==s1.pop())
            count++;
    }
    if(count==len)
        cout<<"Palindrome String";
    else
        cout<<"Not Palindrome String";
    return 0;
}
