#include <iostream>

using namespace std;

class dnode{
    int info;
    dnode *head=NULL;
    dnode *prev,*next;
public:
    void insertrear();
    void display();
    void add(dnode d1,dnode d2);
};

void dnode::add(dnode d1,dnode d2){
    dnode *head1=d1.head;
    dnode *head2=d2.head;
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=head2;
    head2->prev=head1;
    cout<<"List 2 concatenated to List 1"<<endl;
}

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

void dnode::display(){
    dnode *cur;
    cur=head;
    if(head==NULL){
        cout<<"Empty list";
    }
    else{
    while(cur!=NULL){
        cout<<cur->info<<" ";
        cur=cur->next;
    }
    }
}

int main()
{
    dnode n1,n2;
    int ch,ele;
    cout<<"Enter 1 to insert element in doubly linked list 1."<<endl;
    cout<<"Enter 2 to insert element in doubly linked list 2."<<endl;
    cout<<"Enter 3 to add both lists."<<endl;
    cout<<"Enter 4 to display."<<endl;
    cout<<"Enter 0 to exit."<<endl;
    do{
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            n1.insertrear();
            break;
        case 2:
            n2.insertrear();
            break;
        case 3:
            n1.add(n1,n2);
            break;
        case 4:
            cout<<"Enter 1 to display list 1, 2 to display list 2:";
            cin>>ele;
            if(ele==1){
                n1.display();
            }
            else if(ele==2){
                n2.display();
            }
            else{
                cout<<"Invalid entry"<<endl;
            }
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
