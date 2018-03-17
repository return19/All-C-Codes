#include<bits/stdc++.h>
using namespace std;

char a[201000];
char b[201000];

long long arr1[201000];
long long arr2[201000];

long long sum[201000];

int main()
{
    long long i,j,k;

    scanf("%s",a);
    scanf("%s",b);

    long long n1=strlen(a);
    long long n2=strlen(b);
    long long ans=0;

    for(i=0;i<n1;i++)
    {
        if(a[i]=='0')
            arr1[i+1]=0;
        else
            arr1[i+1]=1;
    }

    for(i=0;i<n2;i++)
    {
        if(b[i]=='0')
            arr2[i+1]=0;
        else
            arr2[i+1]=1;
    }

    for(i=1;i<=n2;i++)
        sum[i]=sum[i-1] + arr2[i];

    for(i=1;i<=n1;i++)
    {
        if(arr1[i]==0)
        {
            ans =ans + sum[n2-(n1-i)] - sum[(i)-1];
            //cout<<ans<<endl;
        }
        else
        {
            ans =ans + (n2-(n1-i))-(i-1) -( sum[n2-(n1-i)] - sum[(i)-1]);
           // cout<<ans<<endl;
        }
    }


    printf("%lld\n",ans);

    return 0;
}











