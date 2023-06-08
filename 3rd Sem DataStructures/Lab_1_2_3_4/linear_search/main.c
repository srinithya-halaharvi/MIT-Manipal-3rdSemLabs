#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ele, i, n;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integers:");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter a number to search:");
    scanf("%d", &ele);
    for (i = 0; i < n; i++){
        if (arr[i] == ele){
            printf("%d is present at location %d", ele, i+1);
            break;
        }
    }
    if (i == n)
        printf("%d is not in the array", ele);

    return 0;
}
