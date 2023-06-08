#include <iostream>

using namespace std;
struct bank{
    int *alloc;
    int *maxx;
    int *need;
};
bool check(struct bank b[],int i,int r, int work[]){
    int c=0;
    for(int j=0;j<r;j++){
        if(b[i].need[j]<=work[j]){
            c++;
        }
    }
    if(c==r)
        return true;
    else
        return false;
}
void addwork(struct bank b[],int i,int r, int work[]){
    for(int j=0;j<r;j++){
        work[j]=work[j]+b[i].alloc[j];
    }
}
void bankers(struct bank b[], int p,int r, int work[]){
    bool finish[p]={false};
    cout<<endl<<"Sequence:"<<endl;
    while(true){
    int flag=0;
    for(int i=0;i<p;i++){
        if(finish[i]==false && check(b,i,r,work)==true){
            finish[i]=true;
            addwork(b,i,r,work);
            flag=1;
            cout<<"P"<<i<<" ";
        }
    }
    if(flag==0)
        break;
    }
    cout<<endl;
    for(int i=0;i<p;i++){
        if(finish[i]==false){
            cout<<"Unsafe State"<<endl;
            return;
        }
    }
    cout<<"Safe state"<<endl;
}
bool check2(int r, int work[], int req[]){
    int c=0;
    for(int j=0;j<r;j++){
        if(req[j]<=work[j]){
            c++;
        }
    }
    if(c==r)
        return true;
    else
        return false;
}
void req_res_alloc(struct bank b[], int p,int r, int work[]){
    int req[r],i;
    cout<<"Enter Process No. :";
    cin>>i;
    cout<<"Enter additional request for "<<r<<" resources of process P"<<i<<":";
    for(int j=0;j<r;j++){
        cin>>req[j];
    }
    if(check2(r,work,req)==true){
    for(int j=0;j<r;j++){
        b[i].alloc[j]=b[i].alloc[j]+req[j];
        b[i].need[j]=b[i].maxx[j]-b[i].alloc[j];
        work[j]=work[j]-req[j];
        if(b[i].need[j]<0){
            cout<<"Allocated > Max for Process P"<<i<<", Resource R"<<j<<endl;
            cout<<"Unsafe state";
            return;
        }
    }
    for(int j=0;j<r;j++){
        cout<<work[j]<<" ";
    }
    bankers(b,p,r,work);
    }
    else{
        cout<<"Request > Available for Process P"<<i<<endl;
        cout<<"Unsafe state";
        return;
    }
}
int main()
{
    cout<<"Enter number of processes and resources:";
    int p,r; cin>>p>>r;
    struct bank b1[p];
    int work[r],work1[r];
    cout<<"Enter available work for each resource:";
    for(int i=0;i<r;i++){
        cin>>work[i];
        work1[i]=work[i];
    }
    for(int i=0;i<p;i++){
        b1[i].alloc = new int[r];
        b1[i].maxx = new int[r];
        b1[i].need = new int[r];
    }
    for(int i=0;i<p;i++){
        cout<<"Enter Allocated resources of process P"<<i<<":";
        for(int j=0;j<r;j++){
            cin>>b1[i].alloc[j];
        }
        cout<<"Enter Max resources for "<<r<<" resources of process P"<<i<<":";
        for(int j=0;j<r;j++){
            cin>>b1[i].maxx[j];
            b1[i].need[j]=b1[i].maxx[j]-b1[i].alloc[j];
            if(b1[i].need[j]<0){
                cout<<"Allocated > Max for Process P"<<i<<", Resource R"<<j<<endl;
                cout<<"Unsafe state";
                return 0;
            }
        }
    }
    for(int i=0;i<p;i++){
        cout<<"Process P"<<i<<":"<<endl;
        for(int j=0;j<r;j++){
            cout<<"R"<<j<<":"<<endl;
            cout<<"Allocated "<<b1[i].alloc[j]<<" ";
            cout<<"Maximum "<<b1[i].maxx[j]<<" ";
            cout<<"Need "<<b1[i].need[j]<<" "<<endl;
        }
        cout<<endl;
    }
    bankers(b1,p,r,work);
    int ch;
    cout<<"Enter 1. Additional Request"<<endl<<"Enter 0. Exit"<<endl<<"Enter choice:";
    cin>>ch;
    if(ch==1){
        req_res_alloc(b1,p,r,work1);
    }
    for(int i=0;i<p;i++){
        delete[] b1[i].alloc;
        delete[] b1[i].maxx;
        delete[] b1[i].need;
    }
    return 0;
}
//5 4 4 0 0 3 5 0 1 3 15 1 2 4 3 0 2 0 5 4 3 9 2 0 1 1 2 2 2 9 6 1 1 0 8 1 1 0 0 3 1 2 5 3 3 6
