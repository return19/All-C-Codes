#include<bits/stdc++.h>
using namespace std;

long long memo1[1000];
long long memo2[1000];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    long long test,i,j;
    long long n,m,k;
    long long temp;
    long long count1=0;
    long long count2=0;
    long long tr;
    long long max1;


    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        max1=-1;
        memset(memo1,0,sizeof(memo1));
        memset(memo2,0,sizeof(memo2));

        scanf("%lld%lld%lld",&n,&m,&k);

        for(j=0;j<m;j++)
        {
            scanf("%lld",&temp);


            memo1[temp]++;
        }

        for(j=0;j<k;j++)
        {
            scanf("%lld",&temp);

            memo2[temp]++;
        }

        count1=0;
        count2=0;


        for(j=1;j<=n;j++)
        {
            if(memo1[j]==0&&memo2[j]==0)
                count2++;

            if(memo1[j]==1&&memo2[j]==1)
                count1++;
        }

        printf("%lld %lld\n",count1,count2);
    }

    return 0;
}








