#include<bits/stdc++.h>
using namespace std;

int arr[110000];

int main()
{
    int test,i,j,k;
    int n;
    int l,r;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }

        int rm=0,lm=0;

        l=0;

        r=0;

        for(j=0;j<n;j++)
        {
            if(r==0&&arr[j]==1)
            {
                lm=j;
            }

            if(arr[j]==-1)
                rm=j;

            if(arr[j]==1)
            {
                r++;
            }
            else
            {
                l++;
            }
        }

        lm++;

        rm++;

        rm=n-rm;

        int ans;

        if(lm<=rm)
        {
            ans=l+1;
        }
        else
            ans=l;

        printf("%d\n",ans);


    }

    return 0;
}
