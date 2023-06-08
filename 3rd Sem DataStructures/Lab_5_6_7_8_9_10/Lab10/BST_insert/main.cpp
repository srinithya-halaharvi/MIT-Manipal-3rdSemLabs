#include <iostream>
using namespace std;

class bst{
    int data;
    bst *rchild,*lchild;
public:
    bst *root=NULL;
    bst(int ele=0){
        lchild=NULL;
        rchild=NULL;
        data=ele;
    }
    void insertele(int ele);
    //void searchele(int ele);
    void display(bst *root);
    void del(int ele);
};
void bst::insertele(int ele){
    bst *temp=new bst(ele);
    if(root==NULL){
        root=temp;
    }
    else{
        bst *cur=root;
        bst *prev;
        while(cur!=NULL){
            prev=cur;
            if(temp->data<cur->data){
                cur=cur->lchild;
            }
            else if(temp->data>cur->data){
                cur=cur->rchild;
            }
            else{
                cout<<"Insertion not possible";
                return;
            }
        }
        if(temp->data>prev->data){
                prev->rchild=temp;
        }
        else if(temp->data<prev->data){
            prev->lchild=temp;
        }
    }
}

//void bst::del(int ele){

//}

void bst::display(bst *cur){
    if(root==NULL){
        cout<<"Empty BST"<<endl;
        return;
    }
    else if(cur!=NULL){
        display(cur->lchild);
        cout<<cur->data<<" ";
        display(cur->rchild);
    }

}

int main()
{
    bst t1;
    t1.insertele(30);
    t1.insertele(20);
    t1.insertele(25);
    t1.insertele(40);
    t1.insertele(35);
    t1.insertele(5);
    t1.insertele(90);
    t1.insertele(70);
    cout<<"Inorder Traversal:"<<endl;
    t1.display(t1.root);
}
