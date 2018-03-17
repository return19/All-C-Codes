#include<bits/stdc++.h>
using namespace std;

int arr[1010000];
int cnt[1010000];

int solve(int x,int y,int z)
{
    int c=0;
    if(x==1)
        c++;
    if(y==1)
        c++;
    if(z==1)
        c++;
    if(c>=2)
        return 1;
    return 0;
}

int main()
{
    int i,j,k;
    int n;
    int shb1,shb2;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int in=0;
    int ans=0;


    cnt[0]=1;
    for(i=0;i<n;i++)
    {
        cnt[i]=1;
        if(arr[i]!=arr[i-1])
            cnt[i]=cnt[i-1]+1;

        ans=max(ans,cnt[i]);
    }

    if(ans%2==0)
        ans=(ans/2)-1;
    else
        ans=ans/2;

    for(i=1,j=n-2;i<=j;i++,j--)
    {
        shb1=solve(arr[i-1],arr[i],arr[i+1]);
        shb2=solve(arr[j+1],arr[j],arr[j-1]);

        arr[i]=shb1;
        arr[j]=shb2;
    }
    cout<<ans<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
