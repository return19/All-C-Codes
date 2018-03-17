#include<bits/stdc++.h>
using namespace std;

int arr[101000];
int n;

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int ans=0;
        for(i=0;i<=n-3;i++)
        {
            if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
                ans=1;
        }
        if(ans) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}










