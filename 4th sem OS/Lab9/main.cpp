#include <iostream>

using namespace std;
void sort(int arr[], int n, int pos[]){
for(int i=0;i<n-1;i++){
   for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
          int t=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=t;
          t=pos[j];
          pos[j]=pos[j+1];
          pos[j+1]=t;
      }
   }
}
}
void firstfit(int hsize[], int psize[], int h,int n){
    int tsize[h];
    for(int i=0;i<h;i++){
         tsize[i]=hsize[i];
    }
    int allocated[n];
    for(int i=0;i<n;i++){
        allocated[i]=-1;
    }
    int p=0;
    while(p!=n){
         for(int i=0;i<h;i++){
              if(tsize[i]>=psize[p]){
                  allocated[p]=i;
                  tsize[i]=tsize[i]-psize[p];
                  break;
              }
         }
         p++;
    }
    cout<<endl;
    cout<<"PROCESS ALLOCATION INFORMATION:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Process P"<<i<<":";
        if(allocated[i]!=-1)
            cout<<" Allocated to hole "<<allocated[i]<<endl;
        else
            cout<<" Not allocated"<<endl;
    }
    cout<<"HOLE INFORMATION:"<<endl;
    for(int i=0;i<h;i++){
        cout<<"Hole "<<i<<":"<<endl;
        cout<<"Original size:"<<hsize[i]<<endl;
        cout<<"Allocating space for Processes(s): ";
        for(int j=0;j<n;j++){
            if(allocated[j]==i)
                cout<<j<<" ";
        }
        cout<<endl;
        cout<<"Remaining Size/Current Availability:"<<tsize[i]<<endl;
    }
}
void bestfit(int hsize[], int psize[], int h,int n){
    int tsize[h];
    for(int i=0;i<h;i++){
         tsize[i]=hsize[i];
    }
    int allocated[n];
    for(int i=0;i<n;i++){
        allocated[i]=-1;
    }
    int p=0;
    int pos[h];
    for(int i=0;i<h;i++){
         pos[i]=i;
    }
    sort(tsize,h,pos);
    while(p!=n){
         for(int i=0;i<h;i++){
              if(tsize[i]>=psize[p]){
                  allocated[p]=pos[i];
                  tsize[i]=tsize[i]-psize[p];
                  break;
              }
         }
         p++;
    }
    cout<<"PROCESS ALLOCATION INFORMATION:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Process P"<<i<<":";
        if(allocated[i]!=-1)
            cout<<" Allocated to hole "<<allocated[i]<<endl;
        else
            cout<<" Not allocated"<<endl;
    }
    cout<<endl;
    cout<<"HOLE INFORMATION:"<<endl;
    for(int i=0;i<h;i++){
        cout<<"Hole "<<i<<":"<<endl;
        cout<<"Original size:"<<hsize[i]<<endl;
        cout<<"Allocating space for Processes(s): ";
        for(int j=0;j<n;j++){
            if(allocated[j]==i)
                cout<<j<<" ";
        }
        cout<<endl;
        cout<<"Remaining Size/Current Availability:"<<tsize[pos[i]]<<endl;
    }
}
void worstfit(int hsize[], int psize[], int h,int n){
    int tsize[h];
    for(int i=0;i<h;i++){
         tsize[i]=hsize[i];
    }
    int allocated[n];
    for(int i=0;i<n;i++){
        allocated[i]=-1;
    }
    int p=0;
    while(p!=n){
        int maxx=0;
        int hole=0;
        for(int i=0;i<h;i++){
            if(tsize[i]>maxx){
                maxx=tsize[i];
                hole=i;
            }
        }
        if(psize[p]<=tsize[hole]){
            allocated[p]=hole;
            tsize[hole]=tsize[hole]-psize[p];
        }
        p++;
    }
    cout<<endl;
    cout<<"PROCESS ALLOCATION INFORMATION:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Process P"<<i<<":";
        if(allocated[i]!=-1)
            cout<<" Allocated to hole "<<allocated[i]<<endl;
        else
            cout<<" Not allocated"<<endl;
    }
    cout<<"HOLE INFORMATION:"<<endl;
    for(int i=0;i<h;i++){
        cout<<"Hole "<<i<<":"<<endl;
        cout<<"Original size:"<<hsize[i]<<endl;
        cout<<"Allocating space for Processes(s): ";
        for(int j=0;j<n;j++){
            if(allocated[j]==i)
                cout<<j<<" ";
        }
        cout<<endl;
        cout<<"Remaining Size/Current Availability:"<<tsize[i]<<endl;
    }
}
int main()
{
    int h,n;
    cout<<"Enter number of holes:"; cin>>h;
    cout<<"Enter number of processes:"; cin>>n;
    int hsize[h], psize[n];
    for(int i=0;i<h;i++){
         cout<<"Enter size of hole "<<i<<":";
         cin>>hsize[i];
    }
    for(int i=0;i<n;i++){
         cout<<"Enter memory requirement size of process P"<<i<<":";
         cin>>psize[i];
    }
    cout<<"FIRST FIT"<<endl;
    firstfit(hsize,psize,h,n);
    cout<<endl;
    cout<<endl<<"BEST FIT"<<endl;
    bestfit(hsize,psize,h,n);
    cout<<endl<<"WORST FIT"<<endl;
    worstfit(hsize,psize,h,n);
    return 0;
}
//5 4 200 500 300 250 600 210 420 110 230
