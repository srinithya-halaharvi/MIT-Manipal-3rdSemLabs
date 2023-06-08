#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define LEN 10
int main(){
int i;
char buffer[LEN+1];
pid_t pid;
pid=fork();
if(pid==0){
strncpy(buffer,"Child\n",LEN);
buffer[LEN]='\0';
}
else if(pid>0){
strncpy(buffer,"Parent\n",LEN);
buffer[LEN]='\0';
}
else if(pid==-1){
printf("Error occurred");
switch(errno){
case EAGAIN:
printf("Cannot fork process:Process limit reached");
break;
case ENOMEM:
printf("Cannot fork process: Out of memory");
}
return 1;
}
for(i=0;i<5;i++){
sleep(1);
printf("%s\n",buffer);
//write(1,buffer,LEN+1);
}

return 0;
}

