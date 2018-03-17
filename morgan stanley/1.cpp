#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A,int x,int n)
{
    int i,j;
    int ans=0;
    if(x==n-1)
    {
        for(i=0,j=n-1;i<j;i++,j--)
        {
            ans+=abs(A[i]-A[j]);
        }

        return ans;
    }

    int l=solve(A,x+1,n);
    int r;

    if(A[x-1]%2==0&&A[x+1]%2==0)
    {
        A[x]=(A[x-1]+A[x+1])/2;
        r=solve(A,x+1,n);

        return max(l,r);
    }
    else
        return l;
}

int main()
{
    vector<int> v;
    int i,j,k;
    int t,test;
    int n;
    int x,y;
    int ans;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        v.resize(0);

        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }

        if(n==1)
            ans=0;
        else if(n==2)
            ans=abs(v[0]-v[1]);
        else
            ans=solve(v,1,v.size());

        printf("%d\n",ans);

    }

    return 0;
}
