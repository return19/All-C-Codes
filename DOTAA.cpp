#include<bits/stdc++.h>
using namespace std;

long long arr[1010];

int main()
{
    long long test,i,j,k,n,m,d,count1=0;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        count1=0;
        scanf("%lld%lld%lld",&n,&m,&d);

        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }

        sort(arr,arr+n,greater<long long>());

        for(j=0;arr[j]>d;j++)
        {
            while(arr[j]>d)
            {
                arr[j]=arr[j]-d;
                count1++;
            }
        }
        //cout<<"count1 : "<<count1<<endl;
        if(count1>=m)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }


    }
    return 0;
}
