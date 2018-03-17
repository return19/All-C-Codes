#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,n,count1,sum,num;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        sum=0;
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&num);
            if(num!=0)
                count1++;
            sum=sum+num;
        }
        if(sum<100){
            printf("NO\n");
        }
        else
        {
            if(sum-100<count1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
