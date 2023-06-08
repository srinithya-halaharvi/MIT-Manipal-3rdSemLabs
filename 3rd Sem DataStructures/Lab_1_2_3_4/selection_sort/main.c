#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,min,temp;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:");
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;

}
