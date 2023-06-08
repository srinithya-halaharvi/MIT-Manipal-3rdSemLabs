#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str1[100],str2[100],temp[100];
    int i=0,j=0,pos;
    cout<<"Enter the string 1:";
    cin.getline(str1,100);
    cout<<"Enter the string 2:";
    cin.getline(str1,100);
    cout<<"Enter the position:";
    cin>>pos;
    for(i=pos-1;i<strlen(str1);i++){
        temp[j]=str1[i];
        j++;
    }
    j=0;
    for(i=pos-1;i<(pos-1+strlen(str2));i++){
        str1[i]=str2[j];
        j++;
    }
    int index=i;
    j=0;
    for(i=index;i<(strlen(temp)+index);i++){
        str1[i]=temp[j];
        j++;
    }
    cout<<strlen(str1);
    return 0;
}
