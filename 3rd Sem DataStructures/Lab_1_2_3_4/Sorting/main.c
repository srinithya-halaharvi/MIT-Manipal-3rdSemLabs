#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,temp;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:");
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
/*void bubble_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]<arr[j-1]){
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}*/
