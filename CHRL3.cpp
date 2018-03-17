#include<bits/stdc++.h>
using namespace std;
//map<long long,long long> memo;
char str[100010];
//long long arr[100010];
long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    long long i,j,k,n,sum=0;
    scanf("%s",str);
    n=strlen(str);
    /*for(i=0;str[i];i++)
    {
        n++;
        if(str[i]=='C')
            arr[i]=1;
        else if(str[i]=='H')
            arr[i]=2;
        else if(str[i]=='E')
            arr[i]=3;
        else if(str[i]=='F')
            arr[i]=4;
        else
            arr[i]=-1;
    }*/
    //long long x;
    sum=0;
    long long h=0,e=0,f=0;
    for(i=0;i<n;i++)
    {
        if(str[i]=='C')
        {
            h=max2(h,i+1);
            while(h<n&&str[h]!='H')
                h++;
            if(h==n)    break;

            e=max2(e,h+1);
            while(e<n&&str[e]!='E')
                e++;
            if(e==n)    break;

            f=max2(f,e+1);
            while(f<n&&str[f]!='F')
                f++;
            if(f==n)    break;
            h++;
            e++;
            f++;
            sum++;
        }
    }
    printf("%lld\n",sum);
    return 0;
}

