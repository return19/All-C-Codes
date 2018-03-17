
#include<bits/stdc++.h>
using namespace std;



unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long res = 0;
    unsigned long long temp_b;


    if (b >= m) {
            b %= m;
    }

    while (a != 0) {
        if (a & 1) {
            if (b >= m - res)
                res -= m;
            res += b;
        }
        a >>= 1;


        temp_b = b;
        if (b >= m - b)
            temp_b -= m;
        b += temp_b;
    }
    return res;
}
void multip(unsigned long long  a[][2],unsigned long long  b[][2],unsigned long long c[][2],unsigned long long  m)
{
    unsigned long long i,j,k,x,temp1;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                a[i][k]=a[i][k]%m;
                b[k][j]=b[k][j]%m;
                x=0;    temp1=a[i][k];
                while(temp1)
                {
                    temp1=temp1/10;
                    x++;
                }
                temp1=b[k][j];
                while(temp1)
                {
                    x++;
                    temp1=temp1/10;
                }

                if(x>=17)
                {
                    c[i][j]=(c[i][j]+mulmod(a[i][k],b[k][j],m))%m;
                    c[i][j]=c[i][j]%m;
                }
                else
                {
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%m)%m;
                    c[i][j]=c[i][j]%m;
                }
               /* if(a[i][k]<1000000000&&b[k][j]<1000000000)
                {
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%m)%m;
                    c[i][j]=c[i][j]%m;
                }
                else if(m<=a[i][k]&&m<=a[i][k])
                {
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%m)%m;
                    c[i][j]=c[i][j]%m;
                }
                else{
                    c[i][j]=(c[i][j]+mulmod(a[i][k],b[k][j],m))%m;
                    c[i][j]=c[i][j]%m;
                }*/


            }
        }
    }

}



void expo(unsigned long long A[][2],unsigned long long n,unsigned long long ans[][2],unsigned long long m)
{
    unsigned long long temp[2][2];
    unsigned long long i,j;
    memset(temp,0,sizeof(temp));
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;

    while(n>0)
    {
        if(n&1)
        {
            multip(ans,A,temp,m);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }


        multip(A,A,temp,m);


        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                A[i][j]=temp[i][j];


        n=n/2;
    }
    return;

}
unsigned long long find_fb(unsigned long long n,unsigned long long m)
{

    unsigned long long fib=0;

    if(n>2)
    {
        unsigned long long A[2][2]={{1,1},{1,0}},result[2][2];
        memset(result,0,sizeof(result));
        expo(A,n-2,result,m);
        fib=result[0][0];
    }
    else
        fib=n-1;

    return fib;
}

int main()
{
    unsigned long long test,i,j,k,n,m;
    test=4000;
    printf("%llu\n",test);
    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&n,&m);

        k=find_fb(n+1,m);
        printf("%llu\n",k%m);
    }
    return 0;
}
