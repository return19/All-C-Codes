#include<bits/stdc++.h>
using namespace std;

string a;
string b;

int n;

map<int,int> memo;

int solve()
{
    int i;

    int mx=INT_MIN;

    memo.clear();

    for(i=0;i<n;i++)
    {
        if(a[i]<=b[i])
        {
            memo[b[i]-a[i]-1]++;

           // cout<<b[i]-a[i]-1<<" ";

            mx=max(mx,memo[b[i]-a[i]-1]);
        }
        else
        {
            memo[25-(a[i]-b[i])]++;

            //cout<<25-(a[i]-b[i])<<" ";

            mx=max(mx,memo[25-(a[i]-b[i])]);
        }
    }

   // cout<<endl;

    return mx;
}

int main()
{
    int i,j,k;


    int mx=INT_MIN;

    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        cin>>a>>b;

        n=a.length();

        mx=INT_MIN;

        mx=max(mx,solve());

        swap(a,b);

        mx=max(mx,solve());

        printf("%d\n",n-mx);

    }

    return 0;
}
