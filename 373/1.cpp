#include<bits/stdc++.h>
using namespace std;

int arr[1010];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[n-1]==0){
        printf("UP\n");
        return 0;
    } else if(arr[n-1]==15){
        printf("DOWN\n");
        return 0;
    }

    if(n==1){
        printf("-1\n");
        return 0;
    }

    if(arr[n-1] > arr[n-2]){
        printf("UP\n");
    } else {
        printf("DOWN\n");
    }
    return 0;
}
