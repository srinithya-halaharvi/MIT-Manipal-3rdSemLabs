#include <iostream>

using namespace std;

int main()
{
    char str1[100],str2[100];
    int i,j=0,len1=0,len2=0;
    cout<<"Enter the string 1:";
    cin>>str1;
    cout<<"Enter the string 2:";
    cin>>str2;
    for(i=0;str1[i]!='\0';i++){
        len1++;
    }
    for(i=0;str2[i]!='\0';i++){
        len2++;
    }
    int tot_len=len1+len2;
    for(i=len1;i<tot_len;i++){
        str1[i]=str2[j];
        j++;
    }
    str1[i]='\0';
    cout<<"Concatenated string:"<<str1;
    return 0;
}
