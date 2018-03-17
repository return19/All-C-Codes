#include<bits/stdc++.h>
using namespace std;

double arr[10];

int main()
{
    int i,j,k;

    for(i=0;i<4;i++)
        scanf("%llu",&arr[i]);
    sort(arr,arr+4);

    if(arr[3]/arr[2] == arr[1]/arr[0]){
        printf("Possible\n");
    }else{
        printf("Impossible\n");
    }

    return 0;
}
