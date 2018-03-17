#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

int s[1000100];
int p[1000100],P=-1;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void sieve()
{
    int i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<1100;i++)
    {
        k=2;
        p[++P]=i;
        for(j=k*i;j<1100;j=i*k)
        {
            s[j]=1;
            k++;
        }
    }
}

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int gcd_algorithm(int x, int y)
{
    if (y == 0) {
        return x;
    } else if (x >= y && y > 0) {
        return gcd_algorithm(y, (x % y));
    }
}

int main()
{
    int test,i,j,k;
    int a,b;
    int lim;
    int count1;
    int gcd_ans;
    sieve();

    //scanf("%d",&test);
    scanint(test);

    for(i=0;i<test;i++)
    {
        //scanf("%d%d",&a,&b);

        scanint(a);
        scanint(b);

        lim=min2(a,b);
        gcd_ans=gcd_algorithm(a,b);
        lim=sqrt(lim);

        int prod=1;

        for(j=0;p[j]<=lim;j++)
        {
            if(gcd_ans%p[j]==0)
            {
                count1=0;
                while(gcd_ans%p[j]==0)
                {
                    count1++;
                    gcd_ans=gcd_ans/p[j];
                }
                prod=prod*(count1+1);
            }
        }


        printf("%d\n",prod);

    }

    return 0;
}










