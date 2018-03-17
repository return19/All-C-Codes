#include<bits/stdc++.h>
using namespace std;

char str[30];

long long n;

long long solve(long long start,long long psum)
{
    long long i,j,k;
    long long sum=0;
    long long count1=0;

    if(start==n)
        return 1;

    if(start==n-1)
    {
        if(str[start]-'0'>=psum)
            return 1;
        else
            return 0;
    }

    for(i=start;i<n;i++)
    {
        sum=sum+str[i]-'0';

        if(sum>=psum)
        {
            count1+=solve(i+1,sum);
        }
    }
    //cout<<"here"<<endl;

    return count1;

}


int main()
{
    long long i,j,k;
    long long ans;
    long long c1=0;

    scanf("%s",str);

    while(strcmp(str,"bye"))
    {
        n=strlen(str);
        ans=solve(0,0);

        printf("%lld. %lld\n",++c1,ans);

        scanf("%s",str);
    }
}
