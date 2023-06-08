#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100],str2[100],us[100];
    int i=0,j=0,len_1=0,len_2=0,c=0,p;
    cout<<"Enter the string:";
    cin.getline(str,100);
    cout<<"Enter the string to be deleted:";
    cin.getline(str2,100);
    for(i=0;str[i]!='\0';i++){
        len_1++;
    }
    for(i=0;str2[i]!='\0';i++){
        len_2++;
    }
    i=0;
    do{
        if(str[i]!=str2[j])
            i++;
        else{
            i++; j++; c++;
            if(str[i]!=str2[j]){
                j=0;
                c=0;
                i++;
            }
        }
        if(c==len_2-1)
            break;
    }while(i<len_1);
    p=i-len_2+1;
    i=0;
    while(i<p){
        us[i]=str[i];
        i++;
    }
    for(j=p+len_2;j<len_1;j++){
        us[i]=str[j];
        i++;
    }
    us[i]='\0';
    cout<<"String after deletion:"<<endl;
    cout<<us;
    return 0;
}
