#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
struct process{
    int pid;
    int bt;
    int arrt;
    int pri;
};
//5 10 4 3 1 2 1 2 1 4 1 0 5 5 3 2
void sort(int arr[], int n, int pos[]){
for(int i=0;i<n;i++){
   for(int j=1;j<n;j++){
      if(arr[i]>arr[j]){
          int t=arr[i];
          arr[i]=arr[j];
          arr[j]=t;
          t=pos[i];
          pos[i]=pos[j];
          pos[j]=t;
      }
   }
}
}
void rr(struct process p[],int n){
int q;
queue<int> q1;
cout<<"Enter quantum time:"; cin>>q;
int id=MAX;
int burst[n], wait_time[n],tat[n];
for(int i=0;i<n;i++){
    burst[i]=p[i].bt;
}
int time=0, job=0, comp_time=0, completed=0,j;

while(completed!=n){
int arr[n]={MAX};
int pos[n];
for(int i=0;i<n;i++){
pos[i]=i;
}
    for(int i=0;i<n;i++){
        if(p[i].arrt<=time && burst[i]>0){
            //id=p[i].pid;
            arr[i]=p[i].arrt;
        }
    }
    sort(arr,n,pos);
    for(int i=0;i<n;i++){
        if(arr[i]==MAX)
             break;
        else{
            q1.push(pos[i]);
        }
    }
    if(q1.empty()){
         time++;
         continue;
    }
    else{
         job=q1.front();
         q1.pop();
         if(q>=burst[job]){
             time=time+burst[job];
             burst[job]=0;
             completed++;
             comp_time=time;
             cout<<"Process "<<job<<" Completed at time:"<<comp_time<<endl;
             wait_time[job]=comp_time- p[job].arrt- p[job].bt;
             if(wait_time[job]<0){
                 wait_time[job]=0;
             }
         }
         else if(q<burst[job]){
             time=time+q;
             burst[job]=burst[job]-q;
             q1.push(job);
         }
         id=MAX;
    }
}
}
void priority_nonPreemp(struct process p[], int n){
int priority=MAX;
int id=MAX;
int burst[n], wait_time[n],tat[n];
for(int i=0;i<n;i++){
    burst[i]=p[i].bt;
}
int time=0, job=0, comp_time=0, completed=0;
bool flag=false;
while(completed!=n){
     for(int i=0;i<n;i++){
          if(p[i].arrt<=time && burst[i]>0 && p[i].pri<priority){
               job=i;
               flag=true;
               id=p[i].pid;
               priority=p[i].pri;
          }
     }
     if(flag==false){
     time++;
     continue;
     }
     else{
          time=time+burst[job];
          completed++;
          comp_time=time;
          id=MAX;
          priority=MAX;
          cout<<"Process "<<job<<" Completed at time:"<<comp_time<<endl;
          wait_time[job]=comp_time- p[job].arrt- p[job].bt;
          flag=false;
          if(wait_time[job]<0){
               wait_time[job]=0;
          }
          burst[job]=0;
     }
}
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wait_time[i];
    cout<<"Process_id\t Burst time\t Waiting time\t Turn_Around_Time\t"<<endl;
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=(float)total_wt/n;
    float avgtat=(float)total_tat/n;
    cout<<"Average waiting time:"<<avgwt<<endl;
    cout<<"Average turn around time:"<<avgtat<<endl;
}
void priority_preemp(struct process p[], int n){
int priority=MAX;
int id=MAX;
int burst[n], wait_time[n],tat[n];
for(int i=0;i<n;i++){
    burst[i]=p[i].bt;
}
int time=0, job=0, comp_time=0, completed=0;
bool flag=false;
while(completed!=n){
     for(int i=0;i<n;i++){
          if(p[i].arrt<=time && burst[i]>0 && p[i].pri<priority){
               job=i;
               flag=true;
               id=p[i].pid;
               priority=p[i].pri;
          }
     }
     if(flag==false){
     time++;
     continue;
     }
     else{
     burst[job]--;
     if(burst[job]==0){
          completed++;
          comp_time=time+1;
          cout<<"Process "<<job<<" Completed at time:"<<comp_time<<endl;
          wait_time[job]=comp_time- p[job].arrt- p[job].bt;
          flag=false;
          if(wait_time[job]<0){
               wait_time[job]=0;
          }
     }
     priority=MAX;
     id=MAX;
     time++;
     }
}
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wait_time[i];
    cout<<"Process_id\t Burst time\t Waiting time\t Turn_Around_Time\t"<<endl;
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=(float)total_wt/n;
    float avgtat=(float)total_tat/n;
    cout<<"Average waiting time:"<<avgwt<<endl;
    cout<<"Average turn around time:"<<avgtat<<endl;
}
void fcfs(struct process p[], int n){
int id=MAX;
int burst[n], wait_time[n],tat[n];
for(int i=0;i<n;i++){
    burst[i]=p[i].bt;
}
int time=0, job=0, comp_time=0, completed=0;
bool flag=false;
while(completed!=n){
for(int i=0;i<n;i++){
    if(p[i].arrt<=time && p[i].pid<id && burst[i]>0){
         job=i;
         id=p[i].pid;
         flag=true;
    }
}
if(flag==false){
    time++;
    continue;
}
else{
completed++;
flag=false;
comp_time= time+ burst[job];
time=time+burst[job];
wait_time[job]=comp_time- p[job].arrt - p[job].bt;
cout<<"Process "<<job<<" Completed at time:"<<comp_time<<endl;
wait_time[job]=comp_time- p[job].arrt - p[job].bt;
    if(wait_time[job]<0){
        wait_time[job]=0;
    }
burst[job]=0;
id=MAX;
}
}
for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wait_time[i];
    cout<<"Process_id\t Burst time\t Waiting time\t Turn_Around_Time\t"<<endl;
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=(float)total_wt/n;
    float avgtat=(float)total_tat/n;
    cout<<"Average waiting time:"<<avgwt<<endl;
    cout<<"Average turn around time:"<<avgtat<<endl;
}
void sjf_nonpreepm(struct process p[], int n){
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
        if(p[i].arrt<=time && burst[i]<min && burst[i]>0){
             min=burst[i];
             shortest=i;
             flag=true;
        }
    }
    if(flag==false){
        time++;
        continue;
    }
    else{
    time=time+burst[shortest];
    completed++;
    flag=false;
    min=MAX;
    comp_time=time;
    cout<<"Process "<<shortest<<" Completed at time:"<<comp_time<<endl;
    wait_time[shortest]=comp_time- p[shortest].arrt - p[shortest].bt;
    if(wait_time[shortest]<0){
        wait_time[shortest]=0;
    }
    burst[shortest]=0;
    }
    }
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wait_time[i];
    cout<<"Process_id\t Burst time\t Waiting time\t Turn_Around_Time\t"<<endl;
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=(float)total_wt/n;
    float avgtat=(float)total_tat/n;
    cout<<"Average waiting time:"<<avgwt<<endl;
    cout<<"Average turn around time:"<<avgtat<<endl;
}
void sjf_preemp(struct process p[], int n){
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
            if(p[i].arrt<=time && burst[i]<min && burst[i]>0){
                min=burst[i];
                shortest=i;
                flag=true;
            }
        }
        if(flag==false){
            time++;
            continue;
        }
        burst[shortest]--;
        min = burst[shortest];
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
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
    }
    float avgwt=total_wt/n;
    float avgtat=total_tat/n;
    cout<<"Average waiting time:"<<avgwt<<endl;
    cout<<"Average turn around time:"<<avgtat<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of processes:"; cin>>n;
    struct process plist[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Burst time, Arrival time, Priority of process "<<i<<" :";
        plist[i].pid=i;
        cin>>plist[i].bt;
        cin>>plist[i].arrt;
        cin>>plist[i].pri;
    }
    int ch;
    do{
        cout<<"1. SJF-Preemptive"<<endl<<"2. Round robin"<<endl<<"3. Priority-Preemptive"<<endl<<"4. FCFS"<<endl<<"5. Priority-Non_preemptive"<<endl;
        cout<<"Enter choice:"; cin>>ch;
        switch(ch){
        case 1:
            sjf_nonpreepm(plist,n);
            break;
        case 2:
            rr(plist,n);
            break;
        case 3:
            priority_preemp(plist,n);
            break;
        case 4:
            fcfs(plist,n);
            break;
        case 5:
            priority_nonPreemp(plist,n);
            break;
        default:
            break;
        }

    }while(ch!=0);
}
