#include<map>
using namespace std;
#include<stdio.h>

int a[200010];

int main()
{
    int test,n,i,j,k,sum=0;
    map<int,int> memo;

    cin>>test;

    for(i=0;i<test;i++)
    {
        sum=0;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }

        for(j=0;j<n-1;j++)
        {
            if(memo[a[j]]==1)
            {
                continue;
            }
            memo[a[j]]=1;
            for(k=j+1;k<n-1;k++)
            {
                if(a[j]>a[k])
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
