#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;

long long powof2(long long k)
{
	long long ret = 1;
	long long a = 2;
	while (k)
	{
		if (k & 1) ret *= a;
		a *= a;
		ret %= mod;
		a %= mod;
		k >>= 1;
	}
	return (ret);
}

class matrix
{
public:
	long long m[3][3];
	void tozero()
	{
		memset(m,0,sizeof(m));
	}
	void toone()
	{
		tozero();
		for (int i = 0; i < 3; i++) m[i][i] = 1;
	}
	long long* operator [] (int i)
	{
		return m[i];
	}
	matrix operator *(matrix& A) const
	{
		matrix D;
		D.tozero();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					D[i][j] =(D[i][j] + (m[i][k] * A[k][j]))%mod;
				}
			}
		}
		return D;
	}


};

long long solve(long long n)
{
    int i,j,k;
    long long ans;

    matrix T;
   // matrix F={{2},{4},{7}};

   T.tozero();

   T[0][1]=1;
   T[1][2]=1;
   T[2][0]=1;
   T[2][1]=1;
   T[2][2]=1;

    long long p=powof2(n);
    ans=p;

    matrix x;

    x.toone();

    n=n-3;

    while(n)
    {
        if(n & 1)
        {
            x = x*T;
        }
        T = T*T;
        n>>=1;
    }
    //cout<<"ans "<<ans<<endl;
    //cout<<x[0][0]<<" "<<x[1][0]<<" "<<x[2][0]<<endl;
    ans=ans-(7*x[2][2]+4*x[2][1]+2*x[2][0])%mod;

    if(ans>=0)
        return ans;

    return (ans+mod);


}

int main()
{
    long long n,i,j,ans,test;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        if(n<=2)
        {
            printf("0\n");
            continue;
        }

        ans=solve(n);

        printf("%lld\n",ans);
    }

    return 0;
}
