#include<iostream>
using namespace std;
class time
{
	int hour,minute,sec;
	float tot_min;
    public:
        void read(void);
        void display(void);
        void add(time a,time b);
        void diff(time a,time b);
};
void time::read()
{
    cout<<"Enter Hours:";
    cin>>hour;
    cout<<"Enter minutes:";
    cin>>minute;
    cout<<"Enter seconds:";
    cin>>sec;
}
void time::display()
{

    cout<<"Hours:"<<hour;
    cout<<"\nMinutes:"<<minute;
    cout<<"\nSeconds:"<<sec;
}
void time::add(time a,time b)
{
    time m;
    m.hour=a.hour+b.hour;
    m.minute=a.minute+b.minute;
    m.sec=a.sec+b.sec;
    m.display();
}
void time::diff(time a,time b)
{
    tot_min= hour*60 + minute + sec/60.0;
    time n;
    if(a.tot_min>b.tot_min){
        n.hour=a.hour-b.hour;
        n.minute=a.minute-b.minute;
        n.sec=a.sec-b.sec;
    }
    else{
        n.hour=b.hour-a.hour;
        n.minute=b.minute-a.minute;
        n.sec=b.sec-a.sec;
    }
    n.display();

}
int main()
{
    time x,y,m,n;
    x.read();
    y.read();
    cout<<"First time input:"<<endl;
    x.display();
    cout<<"\nSecond time input:"<<endl;
    y.display();
    cout<<"\nSum of two times:"<<endl;
    m.add(x,y);
    cout<<"\nDifference of two times:"<<endl;
    n.diff(x,y);
    return 0;
}
