#include<iostream>
#include<string.h>
using namespace std;

class student
{
  private:
  int roll,temp,i,j,n;
  char name[20],grade,temp1,temp2[20];

  public:
  void read();
  void display();
  void sort();
}s[10];

void student::read()
{
  cout<<"Enter the number of students:";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"Enter the roll number:";
    cin>>s[i].roll;
    cout<<"Enter name:";
    cin>>s[i].name;
    cout<<"Enter grade:";
    cin>>s[i].grade;
  }
  sort();
  display();
}
void student::sort()
{
  cout<<"Sorted list of students:"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(s[j].roll>s[j+1].roll){
          temp=s[j].roll;
	      s[j].roll=s[j+1].roll;
	      s[j+1].roll=temp;
	      temp1=s[j].grade;
	      s[j].grade=s[j+1].grade;
	      s[j+1].grade=temp1;
	      strcpy(temp2,s[j].name);
	      strcpy(s[j].name,s[j+1].name);
	      strcpy(s[j+1].name,temp2);
      }
    }
  }
}

void student::display()
{
  for(i=1;i<=n;i++)
  {
    cout<<"Roll no:"<<s[i].roll<<endl;
    cout<<"Name:";
    cout<<s[i].name<<endl;
    cout<<"Grade:"<<s[i].grade<<endl;
  }
}

int main()
{
  student a;
  a.read();
  return 0;
}
