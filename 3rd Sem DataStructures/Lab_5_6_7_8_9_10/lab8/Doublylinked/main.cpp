#include <iostream>
using namespace std;

class dnode{
    int info;
    dnode *prev,*next;
public:
    void insertrear();
    void deleterear();
    void insertpos(int pos);
    void display();
    void deletepos(int pos);
    void inserta(int ele);
    void insertb(int ele);
    void traverse();
    void rev();
};
dnode *head=NULL;

void dnode::insertrear(){
    dnode *temp=new dnode;
    dnode *cur;
    cout<<"Enter element to be inserted:";
    cin>>temp->info;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
    cout<<"Inserted "<<temp->info<<endl;;
}

void dnode::deleterear(){
    dnode *cur;
    if(head==NULL){
        cout<<"Empty";
    }
    else{
        cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        (cur->prev)->next=NULL;
        cout<<"Deleted "<<cur->info<<endl;
        delete cur;
    }
}

void dnode::insertpos(int pos){
    dnode *temp=new dnode;
    dnode *cur;
    cout<<"Enter element to be inserted:";
    cin>>temp->info;
    temp->prev=NULL;
    temp->next=NULL;
    cur=head;
    int p=0,flag=1;
    while(p!=pos){
        cur=cur->next;
        p++;
        if(cur==NULL){
            flag=0;
            cout<<"Position not found"<<endl;
            break;
        }
        //p++;
    }
    if(flag==1){
        (cur->prev)->next=temp;
        temp->prev=cur->prev;
        temp->next=cur;
        cur->prev=temp;
        cout<<"Inserted "<<temp->info<<" at position "<<pos<<endl;
    }
}

void dnode::deletepos(int pos){
    dnode *cur=head;
    int p=0,flag=1;
    while(p!=pos){
        cur=cur->next;p++;
        if(cur==NULL){
            flag=0;
            cout<<"Position not found"<<endl;
            break;
        }
        //p++;
    }
    if(flag==1){
        (cur->prev)->next=cur->next;
        cout<<"Deleted "<<cur->info<<endl;
        delete cur;
    }
}

void dnode::inserta(int ele){
    dnode *temp=new dnode;
    dnode *cur;
    int flag=0;
    cout<<"Enter value to be inserted:";
    cin>>temp->info;
    temp->prev=NULL;
    temp->next=NULL;
    cur=head;
    while(cur->next!=NULL){
        if(cur->info==ele){
            flag=1;
            temp->next=cur->next;
            temp->prev=cur;
            (cur->next)->prev=temp;
            cur->next=temp;
            break;
        }
        cur=cur->next;
    }
    if(flag==0){
        cout<<"Element not found"<<endl;
    }
}

void dnode::insertb(int ele){
    dnode *temp=new dnode;
    dnode *cur;
    int flag=0;
    cout<<"Enter value to be inserted:";
    cin>>temp->info;
    temp->prev=NULL;
    temp->next=NULL;
    cur=head;
    while(cur->next!=NULL){
        if(cur->info==ele){
                flag=1;
            temp->next=cur;
            temp->prev=cur->prev;
            (cur->prev)->next=temp;
            cur->prev=temp;
            break;
        }
        cur=cur->next;
    }
    if(flag==0){
        cout<<"Element not found"<<endl;
    }
}

void dnode::traverse(){
    cout<<"Displaying..."<<endl;
    display();
}

void dnode::rev(){
    dnode *cur=head;
    dnode *temp=NULL;
    if(cur==NULL)
        cout<<"Empty list"<<endl;
    else{
        while(cur!=NULL){
            temp=cur->next;
            if(temp==NULL){
                head=cur;
            }
            cur->next=cur->prev;
            cur->prev=temp;
            cur=temp;
        }
    }
    cout<<"List Reversed"<<endl;
}

void dnode::display(){
    dnode *cur;
    cur=head;
    if(head==NULL){
        cout<<"Empty list";
    }
    else{
    while(cur!=NULL){
        cout<<cur->info<<endl;
        cur=cur->next;
    }
    }
}

int main()
{
    dnode d1;
    int ch,ele,pos;
    cout<<"Enter 1 to insert an element at rare end."<<endl;
    cout<<"Enter 2 to delete an element at rare end."<<endl;
    cout<<"Enter 3 to insert an element at a given position."<<endl;
    cout<<"Enter 4 to delete an element from a given position."<<endl;
    cout<<"Enter 5 to insert an element after another element."<<endl;
    cout<<"Enter 6 to insert an element before another element."<<endl;
    cout<<"Enter 7 to Traverse/Display the list."<<endl;
    cout<<"Enter 8 to reverse the list."<<endl;
    cout<<"Enter 0 to exit."<<endl;
    do{
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            d1.insertrear();
            break;
        case 2:
            d1.deleterear();
            break;
        case 3:
            cout<<"Enter the position of the element to be inserted:";
            cin>>pos;
            d1.insertpos(pos);
            break;
        case 4:
            cout<<"Enter the position of the element to be deleted:";
            cin>>pos;
            d1.deletepos(pos);
            break;
        case 5:
            cout<<"Enter the element after which you want to insert:";
            cin>>ele;
            d1.inserta(ele);
            break;
        case 6:
            cout<<"Enter the element before which you want to insert:";
            cin>>ele;
            d1.insertb(ele);
            break;
        case 7:
            d1.traverse();
            break;
        case 8:
            d1.rev();
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
