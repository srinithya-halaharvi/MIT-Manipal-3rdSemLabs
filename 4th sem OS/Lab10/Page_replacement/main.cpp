#include <iostream>

using namespace std;
void fifo(int f, int p, int arr[]){
    int frame[f];
    for(int i=0;i<f;i++){
         frame[i]=-1;
    }
    int top=0;
    int i=0;
    int miss=0, hit=0;
    while(i!=p){
        cout<<"Inserting "<<arr[i]<<endl;
        if(frame[top]==-1){
            miss++;
            frame[top]=arr[i];
            top++;
            if (top==f){
                top=0;
            }
        }
        else{
            int flag=0;
            for(int j=0;j<f;j++){
                if(frame[j]==arr[i]){
                    flag=1;
                    hit++;
                    break;
                }
            }
            if(flag==0){
            miss++;
            frame[top]=arr[i];
            top++;
            if (top==f){
                top=0;
            }
            }
        }
        for(int i=0;i<f;i++){
            cout<<frame[i]<<" ";
        }
        cout<<endl;
        i++;
    }
}
void optimal(int f, int p, int arr[]){
    int frame[f];
    for(int i=0;i<f;i++){
         frame[i]=-1;
    }
    int top=0;
    int i=0;
    int miss=0, hit=0;
    int pos=0;
    while(i!=p){
        cout<<"Inserting "<<arr[i]<<endl;
        if(frame[top]==-1){
            miss++;
            frame[top]=arr[i];
            top++;
            if (top==f){
                top=0;
            }
        }
        else{
            int flag=0;
            for(int j=0;j<f;j++){
                if(frame[j]==arr[i]){
                    flag=1;
                    hit++;
                    break;
                }
            }
        }
    }
    i++;
    pos++;
}
int main()
{
    int f,p,ch;
    cout<<"Enter number of frame size and pages:";
    cin>>f>>p;
    cout<<"Enter "<<p<<" pages:";
    int arr[p];
    for(int i=0;i<p;i++){
        cin>>arr[i];
    }
    do{
        cout<<"1. FIFO"<<endl<<"2. Optimal"<<endl<<"3. LRU"<<endl<<"0. exit"<<endl;
        cout<<"Enter choice:"; cin>>ch;
        switch(ch){
        case 1:
            fifo(f,p,arr);
            break;
        case 2:
            int mat[p][p];
            for(int i=0;i<p;i++){
                if(i==0){
                    mat[0][0]=arr[0];
                }
                else{
                for(int j=0;j<p;j++){

                }
                }
            }
        }
    }while(ch!=0);

    return 0;
}
