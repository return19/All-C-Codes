#include<bits/stdc++.h>
using namespace std;

char str[1010];

long long check_pal1(long long x,long long y)
{
    long long i,j;
    long long flag=0;

   // cout<<"palcheck "<<x<<" "<<y<<endl;

    for(i=x,j=y ; i<j ; i++,j--)
    {
        //cout<<"here"<<endl;

        if(str[i]!=str[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==1){
        //cout<<0<<endl;
        return 0;

    }
    //cout<<1<<endl;
    return 1;
}

long long palness(long long x,long long y)
{

    long long i,j,k;
    long long cur=0;

    if(x>y)
        return 0;

    if(x==y)
        return 1;


    cur=check_pal1(x,y);

    if(cur==1)
    {
        cur=1+palness(x,x-1+(y-x+1)/2);
        return cur;
    }

    return 0;


}

int main()
{
    long long test,i,j,k;

    long long n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        n=strlen(str);

        long long sum=0;

       // cout<<"here "<<check_pal(0,n-1)<<endl;

        for(j=0;j<n;j++)
        {
            for(k=j;k<n;k++)
            {
                sum=sum+palness(j,k);

                //cout<<j<<" "<<k<<" "<<palness(j,k)<<endl;
            }
        }

        printf("%lld\n",sum);
    }

    return 0;
}
