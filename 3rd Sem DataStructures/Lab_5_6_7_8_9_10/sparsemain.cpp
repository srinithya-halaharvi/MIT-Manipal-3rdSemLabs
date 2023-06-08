#include <iostream>
#define SIZE 50
using namespace std;

class sparse{
public:
    int row;
    int col;
    int val;
    void read();
    void FastTranspose();
}spa[SIZE];
void sparse::read(){
    int i,j,r,c,count;
    cout<<"Enter number of rows:";
    cin>>r;
    cout<<"Enter number of columns:";
    cin>>c;
    int mat[r][c];
    cout<<"Enter matrix elements:";
    for (i=0;i<r;i++){
      for(j=0;j<c;j++){
          cin>>mat[i][j];
      }
    }
    for (i=0;i<r;i++){
      for(j=0;j<c;j++){
         if(mat[i][j]==0)
            count++;
      }
   }
   if(count<(r*c)/2){
        cout<<"Not a sparse matrix";
        exit(0);
   }
   else{
        int num=(r*c)-count;
        spa[0].row=r;
        spa[0].col=c;
        spa[0].val=num;
        int k=1;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(mat[i][j]!=0){
                    spa[k].row=i;
                    spa[k].col=j;
                    spa[k].val=mat[i][j];
                    k++;
                }
            }                                         //0 5 3 4 0 7 0 0 0 6 0 0 8 7 9 0
        }
        cout<<"Sparse Matrix:"<<endl;
        for(i=0;i<=spa[0].val;i++){
            cout<<spa[i].row<<" "<<spa[i].col<<" "<<spa[i].val;
            cout<<endl;
        }
        FastTranspose();
   }
}
void sparse::FastTranspose(){
   sparse trans[SIZE];
   int i,j,len=spa[0].col;
   int total[len],index[len+1];
   for(i=0;i<=spa[0].col;i++){
        total[i]=0;
   }
    for(i=0;i<spa[0].col;i++){
        for(j=0;j<=spa[0].val;j++){
            if(spa[j].col==i)
                total[i]=total[i]+1;
        }
    }
    index[0]=1;
    for(i=1;i<len+1;i++)
        index[i]=index[i-1]+total[i-1];

    trans[0].row=spa[0].col;
    trans[0].col=spa[0].row;
    trans[0].val=spa[0].val;

    for(i=1;i<=spa[0].val;i++){
        j=index[spa[i].col];
        trans[j].row=spa[i].col;
        trans[j].col=spa[i].row;
        trans[j].val=spa[i].val;
        index[spa[i].col]++;
    }
    cout<<"Transposed Matrix:"<<endl;
    for(i=0;i<=trans[0].val;i++){
        cout<<trans[i].row<<" "<<trans[i].col<<" "<<trans[i].val;
        cout<<endl;
    }
}

int main(){
    sparse s;
    s.read();
    return 0;
}
