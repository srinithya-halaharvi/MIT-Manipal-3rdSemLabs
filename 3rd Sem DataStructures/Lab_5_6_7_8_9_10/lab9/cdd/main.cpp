#include <iostream>
using namespace std;

class cdnode{
    int info;
    cdnode *prev,*next;
public:
    void insertele();
    void del();
    void display();
};

cdnode* head=NULL;

void cdnode::insertele(){
    cdnode *temp=new cdnode;
    cout<<"Enter element to be inserted:";
    cin>>temp->info;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else{
        cdnode *cur=head;
        while(cur->next!=head){
            cur=cur->next;
        }
        head->prev=temp;
        cur->next=temp;
        temp->prev=cur;
        temp->next=head;
    }
    cout<<"Inserted:"<<temp->info<<endl;
}

void cdnode::del(){
    int ele,flag=0;
    cout<<"Enter element to be deleted:";
    cin>>ele;
    cdnode *cur=head;
    if(cur->info==ele){
        flag=1;
        head=cur->next;
        (cur->prev)->next=cur->next;
        (cur->next)->prev=cur->prev;
        delete(cur);
        cout<<"Deleted:"<<ele<<endl;
    }
    else{
    while(cur->next!=head){
        if(cur->info==ele){
            flag=1;
            (cur->prev)->next=cur->next;
            (cur->next)->prev=cur->prev;
            delete(cur);
            cout<<"Deleted:"<<ele<<endl;
            break;
        }
        cur=cur->next;
    }
    if(cur->info==ele){
        flag=1;
        (cur->prev)->next=cur->next;
        (cur->next)->prev=cur->prev;
        delete(cur);
        cout<<"Deleted:"<<ele<<endl;
    }
    if(flag==0){
        cout<<"Element not found"<<endl;
    }
    }
}

void cdnode::display(){
    cdnode *cur=head;
    if(head==NULL){
        cout<<"Empty list";
    }
    else{
        while(cur->next!=head){
            cout<<cur->info<<" ";
            cur=cur->next;
        }
        cout<<cur->info<<endl;
    }
}

int main()
{
    cdnode cd1;
    int ch,ele;
    cout<<"Enter 1 to insert an element."<<endl;
    cout<<"Enter 2 to delete an element."<<endl;
    cout<<"Enter 3 to display."<<endl;
    cout<<"Enter 0 to exit."<<endl;
    do{
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            cd1.insertele();
            break;
        case 2:
            cd1.del();
            break;
        case 3:
            cd1.display();
            break;
        case 0:
            cout<<"Thank you"<<endl;
            break;
        default:
            cout<<"Invalid choice!!!"<<endl;
            break;
        }
    }while(ch!=0);
    return 0;
}
