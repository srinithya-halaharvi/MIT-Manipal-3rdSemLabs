#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(int c, char **arrc){
pid_t pid1=fork();
pid_t *status;
if(pid1==0){
printf("CHILD\n");
printf("Sorted strings:\n");
for(int i=0;i<c-1;i++){
for(int j=i+1;j<c;j++){
if(strcmp(arrc[i], arrc[j])>0){
char *temp;
temp= arrc[i];
arrc[i]= arrc[j];
arrc[j]=temp;
}
}
}
for(int i=0;i<c;i++){
printf("%s ", arrc[i]);
}
printf("\n");
}
else if(pid1>0){
wait(status);
printf("PARENT\n");
printf("Unsorted strings:\n");
for(int i=0;i<c;i++){
printf("%s ", arrc[i]);
}
printf("\n");
}
else{
printf("Fork failed");
}
return 0;
}
