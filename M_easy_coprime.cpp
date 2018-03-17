#include<bits/stdc++.h>
using namespace std;

int s[101000];

void sieve()
{
    int i,j,p;
    s[0]=s[1]=1;
    for(i=2;i<101000;i++)
    {
        if(s[i]==0)
        {
            p=2;

            for(j=i*p;j<101000;j=i*p)
            {
                s[j]=1;

                p++;
            }
        }
    }
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
    int test,n,i,j,k;
    int z;
    sieve();
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        z=0;
        scanf("%d",&n);

        for(j=1;j<n;j++)
        {
            if(gcd_algorithm(n,j)==1)
            {
                z++;
            }
        }
        //z=z+n-n/2-1;
        //cout<<z<<endl;
        if(!s[z])
        {
            printf("TRUE\n");
        }
        else
        {
            printf("FALSE\n");
        }
    }

    return 0;
}










