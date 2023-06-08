#include <iostream>

using namespace std;

class cdnode{
    int coeff,expo;
    cdnode *head=NULL;
    cdnode *prev,*next;
public:
    void insertele(int co,int e);
    void sortlist();
    void display();
    void addpoly(cdnode d1,cdnode d2);
};

void cdnode::insertele(int co,int e){
    cdnode *temp=new cdnode;
    temp->coeff=co;
    temp->expo=e;
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
}

void cdnode::sortlist(){
    cdnode *cur1,*cur2;
    cur1=head;
    int temp;
    while(cur1->next!=head){
        cur2=cur1->next;
        while(cur2->next!=head->next){
            if(cur2->expo>cur1->expo){
                temp=cur1->coeff;
                cur1->coeff=cur2->coeff;
                cur2->coeff=temp;
                temp=cur1->expo;
                cur1->expo=cur2->expo;
                cur2->expo=temp;
            }
            cur2=cur2->next;
        }
        cur1=cur1->next;
    }
}

void cdnode::display(){
    cdnode *cur=head;
    while(cur->next!=head){
        cout<<cur->coeff<<"x^"<<cur->expo<<"+";
        cur=cur->next;
    }
    cout<<cur->coeff<<"x^"<<cur->expo<<endl;
}

void cdnode::addpoly(cdnode d1,cdnode d2){
    cdnode *cur1=d1.head;
    cdnode *cur2=d2.head;
    cdnode add;
    int count=0;
    int c=0,s=0;
    while((cur1!=d1.head)||(c==0)){
        c=1;
        s=0;
        count=0;
        cur2=d2.head;
        while((cur2!=d2.head)||(s==0)){
            s=1;
            if(cur1->expo==cur2->expo){
                count++;
                add.insertele((cur1->coeff+cur2->coeff),cur1->expo);
            }
            cur2=cur2->next;
        }
        if(count==0){
            add.insertele(cur1->coeff,cur1->expo);
        }
        cur1=cur1->next;
    }
    cur2=d2.head;
    s=0;
    cdnode *cur3;
    while((cur2!=d2.head)||(s==0)){
        s=1;c=0;
        cur3=add.head;
        count=0;
        while((cur3!=add.head)||(c==0)){
            c=1;
            if(cur3->expo==cur2->expo){
                count++;
            }
            cur3=cur3->next;
        }
        if(count==0)
            add.insertele(cur2->coeff,cur2->expo);
        cur2=cur2->next;
    }
    add.sortlist();
    cout<<"Polynomial addition:"<<endl;
    add.display();
}

int main()
{
    cdnode cd1,cd2;
    int n1,n2,i,c,e;
	cout<<"Enter the number of terms in polynomial-1:";
	cin>>n1;
	for(i=0;i<n1;i++){
		cout<<"Enter coefficient and power of x:";
		cin>>c;
		cin>>e;
		cd1.insertele(c,e);
	}
	cd1.display();
	cout<<"Enter the number of terms in polynomial-2:";
	cin>>n2;
	for(i=0;i<n2;i++){
		cout<<"Enter coefficient and power of x:";
		cin>>c;
		cin>>e;
		cd2.insertele(c,e);
	}
	cd2.display();
	cd1.addpoly(cd1,cd2);
	return 0;
}
