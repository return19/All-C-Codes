#include<bits/stdc++.h>
using namespace std;

//map<long long,long long> memo;
//map<long long,long long> sqrs;

/*void init()
{
    long long i;

    for(i=0;i<1000010;i++)
    {
        //memo[i]=i*i;
        sqrs[i*i]=1;
    }
}*/

int main()
{
    long long test,i,j,k,n,flag=0,temp;

    scanf("%lld",&test);

    //init();

    for(i=0;i<test;i++)
    {
        flag=0;
        scanf("%lld",&n);

        for(j=0;j*j<=n;j++)
        {
            temp=(long long)sqrt(n-j*j);
            if(temp*temp==(n-j*j))
            {
                printf("Yes\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;

        printf("No\n");
    }

    return 0;
}
