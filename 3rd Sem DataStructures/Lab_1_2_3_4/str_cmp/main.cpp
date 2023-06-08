#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str1[100],str2[100];
    int i=0,j=0,temp=1,diff;
    cout<<"Enter the string 1:";
    cin>>str1;
    cout<<"Enter the string 2:";
    cin>>str2;
    while((str1[i]!='\0')||(str2[i]!='\0')){
        if(str1[i]!=str2[j]){
            temp=0;
            break;
        }
        i++;
        j++;
    }
    if(temp==0){
        diff=str1[i]-str2[i];
        cout<<"Not equal strings\n";
        cout<<"Differ in ASCII value by:"<<diff;
    }
    else if(temp==1){
        cout<<"Strings are equal";
    }
    return 0;
}
