#include<bits/stdc++.h>
using namespace std;

int arr[1010];
// B
int main()
{
    int i,j,k;
    int n;

    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int ans=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
                if(arr[j]>arr[i])
                    ans++;
        }

        if(ans%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

