#include<bits/stdc++.h>
using namespace std;

int memo[1010][110];

int power(int a,int b,int m)
{
    if(a<=0)
        return 1;
    if(b==0)
        return 1;
    if(b==1)
        return a%m;

    int hf=power(a,b/2,m)%m;

    if(b&1)
    {
        return (((hf*hf)%m)*a)%m;
    }
    return (hf*hf)%m;
}

int solve(int x,int sum,int k,int m,int n)
{
    //cout<<x<<" "<<sum<<endl;

    int i,j;

    int s=0;
    int ans=0;

    if(x==1)
    {
        for(i=1;i<=9;i++)
        {
            if((sum+i)%k==0)
            {
                //cout<<sum+i<<endl;
                ans++;
            }
        }
        return ans;
    }


    for(i=0;i<=9;i++)
    {

        s=((i*(power(10,n-x,k)))%k+sum)%k;

        if(s==0 && sum!=0)
        {
            ans= (ans + (power(x-2,10,k)*9))%m;
        }
        else
            ans=(ans+solve(x-1,s,k,m,n))%m;
    }

    return ans;
}

int FunWithMath(int N, int K, int M) {

    int ans= solve(N,0,K,M,N);
    //printf("%d\n",ans);
    return ans;
}


int main()
{
    int i,j;

    printf("%d\n",FunWithMath(5,3,9999999)%1103);

    return 0;
}
