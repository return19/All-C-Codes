#include<bits/stdc++.h>
using namespace std;

void matmult(long long  a[][2],long long  b[][2],long long c[][2],long long  M)//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%M;
            }
        }
    }

}
void matpow(long long Z[][2],int n,long long ans[][2],long long M)
//find ( Z^n )% M and return result in ans
{

    long long temp[2][2];
    //assign ans= the identity matrix
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;
    int i,j;
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp,M);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp,M);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];


        n=n/2;
    }
    return;

}
long long findFibonacci(long long n,long long M)
{

    long long fib;
    if(n>2)
    {
        long long int Z[2][2]={{1,1},{1,0}},result[2][2];//modify matrix a[][] for other recurrence relations
        matpow(Z,n-2,result,M);
        fib=result[0][0]*1 + result[0][1]*0;    //final multiplication of Z^(n-2) with the initial terms of the series
    }
    else
        fib=n-1;

    return fib;
}

int n,m;
int org[101000];
int mone[101000];
int arr[101000];

int fib(int x){
    if(x==0 || x==1)
        return 1;
    int ans = findFibonacci(x+2,10000);
    return ans;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int ans=0;
    org[0] = fib(arr[0]);
    for(i=1;i<n;i++){
        org[i] = fib(arr[i]+1)*org[i-1] + fib(arr[i])*mone[i-1];
        mone[i] = fib(arr[i])*org[i-1] + fib(arr[i]-1)*mone[i-1];

        ans = ans + (org[i]*2 -1);
    }



    for(i=1;i<n;i++)
        ans = ans + (fib(arr[i])*2 -1);

    printf("%d\n",ans);

    return 0;
}












