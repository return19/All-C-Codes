#include<bits/stdc++.h>
using namespace std;

long long arr[110][110];

int main()
{
    long long n,m,i,j,k,x,y;
    long long sum=0,count1=0;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);
        arr[x-1][y-1]=1;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                count1=0;
                for(k=0;k<n;k++)
                {
                    if(k!=i&&k!=j&&arr[i][k]&&arr[k][j])
                        count1++;
                }
                sum=sum+(count1*(count1-1))/2;
            }
        }
    }

    printf("%lld\n",sum);
}
