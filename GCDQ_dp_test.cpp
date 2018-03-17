#include<bits/stdc++.h>
using namespace std;
long arr[10010];
long dp[10010][10010];
long n;
long gcd(long a,long b)
{

  long r, i,x;
  while(b!=0){
    x = a % b;
    a = b;
    b = x;
  }
  return a;

}

 void scanlong(long &x)
{
    register long c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

void construct()
{
    long i,j;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=i;j--)
        {

            if(i==0)
            {
                if(j==n-1)
                    continue;
                if(j==n-2)
                {
                    dp[i][j]=arr[n-1];
                }
                else
                {
                    dp[i][j]=gcd(dp[i][j+1],arr[j+1]);
                }
            }
            else
            {
                /*if(i==1&&j==n-1)
                {
                    dp[i][j]=arr[i-1];
                    continue;
                }
                else if()*/
                if(j==n-1)
                {
                    if(i==1)
                        dp[i][j]=arr[i-1];
                    else
                        dp[i][j]=gcd(arr[i-1],dp[i-1][j]);
                    continue;
                }
                dp[i][j]=gcd(dp[i-1][j],dp[i][j+1]);
            }
        }
    }

}

int main()
{
    long test,i,j,q,s,e,x,y,z;
    //cin>>test;
    scanlong(test);

    for(i=0;i<test;i++)
    {
        //cin>>n;
        //cin>>q;
        scanlong(n);
        scanlong(q);


        for(j=0;j<n;j++)
        {
            //cin>>arr[j];
            scanlong(arr[j]);
        }
        construct();
        for(x=0;x<n;x++)
        {
            //for(y=0;y<n;y++)
                //cout<<dp[x][y]<<" ";
           // cout<<endl;
        }
        for(j=0;j<q;j++)
        {
            //cin>>s;
            //cin>>e;
            scanlong(s);
            scanlong(e);
           // cout<<dp[s-1][e-1]<<endl;
           printf("%ld\n",dp[s-1][e-1]);
        }
    }
    return 0;
}
