#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ele, low, high, mid, n, i;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integers:");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter a number to search:");
    scanf("%d", &ele);
    low=0;
    high=n-1;
    do{
        mid=(low+high)/2;
        if(ele<arr[mid])
            high=mid-1;
        else if(ele>arr[mid])
            low=mid+1;
    }while((ele!=arr[mid])&&(low<=high));
    if(ele==arr[mid])
        printf("Element found at position %d",mid+1);
    else
        printf("Element not found");
    return 0;
}
