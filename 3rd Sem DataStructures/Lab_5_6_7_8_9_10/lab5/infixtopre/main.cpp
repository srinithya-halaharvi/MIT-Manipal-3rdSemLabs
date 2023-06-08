#include <iostream>
#include <string.h>
using namespace std;
int icp[]={10,9,6,6,7,7,7,8,0};
int isp[]={0,9,6,6,7,7,7,8,0};
enum precedence{lparen,rparen,add,sub,times,divide,mod,pow,operand};
class stack{
    int top,maxsize;
    char a[20];
public:
    stack(){
        top=-1;
        maxsize=20;
    }
    bool Isfull(){
        if(top==maxsize-1)
            return true;
        else
            return false;
    }
    bool Isempty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    char topele(){
        return a[top];
    }
    void push(char c){
        a[++top]=c;
    }
    char pop(){
        if(Isempty()){
            return 0;
        }
        else
            return(a[top--]);
    }
    void display(){
        if(Isempty()){
            cout<<"Empty";
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<a[i];
            }
        }
    }
    precedence get(char c){
        switch(c){
        case '(':
            return lparen;
        case ')':
            return rparen;
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return times;
        case '/':
            return divide;
        case '%':
            return mod;
        case '^':
            return pow;
        default:
            return operand;
        }
    }
    void func(char in[]){
        cout<<in<<endl;
        precedence temp;
        stack s;
        char pre[20];
        int i=0,k=0;
        while(in[i]!=0){
            temp=get(in[i]);
            if(temp==operand){
                pre[k++]=in[i];
            }
            else if(temp==rparen){
                while(get(s.topele())!=lparen)
                    pre[k++]=s.pop();
                char c=s.pop();
            }
            else{
                if(s.Isempty()){
                    s.push(in[i]);
                }
                else{
                    while(icp[temp]<=isp[get(s.topele())]&&(s.Isempty()==false))
                        pre[k++]=s.pop();
                    s.push(in[i]);
                }
            }
            i++;
        }
        while(!s.Isempty())
            pre[k++]=s.pop();
        pre[k]='\0';
        cout<<strrev(pre);
    }
};
int main()
{
    char infix[20],temp[20];
    stack s1;
    int i,j=0;
    cout<<"Enter infix expression:";
    cin>>infix;
    for(i=(strlen(infix)-1);i>=0;i--){
        if(infix[i]=='('){
            temp[j++]=')';
        }
        else if(infix[i]==')')
            temp[j++]='(';
        else{
            temp[j++]=infix[i];
        }
    }
    temp[j]='\0';
    s1.func(temp);
    return 0;
}
