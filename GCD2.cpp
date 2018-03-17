#include<bits/stdc++.h>
using namespace std;

char b[310];

long long rmdr(long long a)
{
    long long i,j,p=0;

    for(i=0;b[i]!='\0';i++)
    {
        p=((p*10)%a+(b[i]-48))%a;
    }

    return p;

}

long long gcd(long long a, long long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}


int main()
{
    long long test,a,i,j,k,p;
    long long ans;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%s",&a,b);

        if(a==0)
        {
            printf("%s\n",b);
            continue;
        }

        p=rmdr(a);
        ans=gcd(a,p);

        printf("%lld\n",ans);

    }

    return 0;
}
