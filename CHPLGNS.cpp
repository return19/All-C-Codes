#include<bits/stdc++.h>
using namespace std;



struct occ
{
    long long val;
    long long num;
};

occ arr[110000];

long long abs1(long long x)
{
    if(x<0)
        return (-1)*x;
    return x;
}

bool cmp(occ x,occ y)
{
    return x.val<y.val;
}

long long ans[110000];

int main()
{
    long long test,i,j,k;
    long long n,m;
    long long x,y,min1,max1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {


        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            arr[j].val=0;
            min1=99999999999999;
            max1=-99999999999999;

            scanf("%lld",&m);

            for(k=0;k<m;k++){
                scanf("%lld%lld",&x,&y);

                max1=max(max1,x);
                min1=min(min1,x);
            }

            if(max1>=0&&min1>=0)
            {
                arr[j].val=abs1(max1-min1);
            }
            else if(max1>=0&&min1<=0)
            {
                arr[j].val=abs1(max1)+abs1(min1);
            }
            else
            {
                arr[j].val=abs1(abs1(max1)-abs1(min1));
            }
        }

        for(j=0;j<n;j++)
        {
            arr[j].num=j;
        }

        sort(arr,arr+n,cmp);

        for(j=0;j<n;j++)
        {
            ans[arr[j].num]=j;
        }

        for(j=0;j<n;j++)
            printf("%lld\n",ans[j]);

    }

    return 0;
}
