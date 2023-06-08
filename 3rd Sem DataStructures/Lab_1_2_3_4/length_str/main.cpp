#include <iostream>

using namespace std;

int main()
{
    string str;
    int i,len=0;
    cout<<"Enter the string:";
    cin>>str;
    for(i=0;str[i]!='\0';i++){
        len++;
    }
    cout<<"Length of the string is:"<<len;
    return 0;
}
