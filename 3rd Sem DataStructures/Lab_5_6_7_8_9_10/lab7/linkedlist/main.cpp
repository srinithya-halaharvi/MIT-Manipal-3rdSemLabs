#include <iostream>
using namespace std;
class node{
    int info;
    node *next;
public:
    node();
    void insertb(int ele);
    void insertend();
    void display();
};
node *head=NULL;
node::node(){
}
void node::insertend(){
    node*cur;
    cur=head;
    node *temp=new node;
    cout<<"Enter value:";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
    }
}
void node::display(){
    node *cur;
    cur=head;
    if(cur==NULL)
        cout<<"Empty";
    else{
        while(cur!=NULL){
            cout<<cur->info<<endl;
            cur=cur->next;
        }
        cout<<1;
    }
}
void node::insertb(int ele){
    node *temp=new node;
    node *cur;
    temp->next=NULL;
    cout<<"Enter value to be inserted:";
    cin>>temp->info;
    if(head==NULL){
        head=temp;
    }
    else{
        while(cur->next!=NULL){
            if((cur->next)->info==ele){
                temp->next=(cur->next)->next;
                cur->next=temp;
                break;
            }
            cur=cur->next;
        }
    }
}
int main()
{
    node n1;
    n1.insertend();
    n1.insertend();
    n1.insertend();
    n1.insertend();
    //n1.insertb(30);
    n1.display();
    return 0;
}
