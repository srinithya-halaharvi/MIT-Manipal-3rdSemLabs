#include <iostream>
#define MAX 1000
using namespace std;
struct process{
    int pid;
    int bt;
    int arrt;
    int pri;
};
void sjf(process p, int n){
    int burst[n];
    for(int i=0;i<n;i++){
        burst[i]=p[i].bt;
    }
    int wait_time[n], tat[n];
    int time=0;
    int min=MAX;
    int shortest=0, completed=0, comp_time;
    bool flag=false;
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(p[i].arrt<=time && burst[j]<min && burst[j]>0){
                min=burst[j];
                shortest=i;
                flag=true;
            }
        }
        if(flag==false){
            time++;
            continue;
        }
        burst[shortest]--;
        if(min==0){
            min=MAX;
        }
        if(burst[shortest]==0){
            cout<<"Process "<<shortest<<" Completed at time:"<<time+1;
            completed++;
            flag=false;
            comp_time=time+1;
            wait_time[shortest]=comp_time - p[shortest].bt - p[shortest].arrt;
            if(wait_time[shortest]<0){
                wait_time[shortest]=0;
            }
        }
        time++;
    }
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wait_time[i];
    cout<<"Process_id\t Burst time\t Waiting time\t Turn_Around_Time\t"<<endl;
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){

        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=
}
int main()
{
    int n;
    cout<<"Enter number of processes:"; cin>>n;
    process plist[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Burst time, Arrival time, Priority of process "<<i<<" :";
        process[i]->pid=i;
        cin>>process[i]->bt;
        cin>>process[i]->arrt;
        cin>>process[i]->pri;
    }
    do{
        cout<<"1. SJF-Preemptive"<<endl<<"2. Round robin"<<endl<<"3. Priority-Non Preemptive"<<endl<<"0 exit"<<endl;
        int ch;
        cout<<"Enter choice:"; cin>>ch;
        switch(ch){
        case 1:

        }

    }while(ch!=0);
}
