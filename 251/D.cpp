#include<bits/stdc++.h>
using namespace std;

unsigned long long a[110000];
unsigned long long b[110000];

unsigned long long  min2(unsigned long long x,unsigned long long y)
{
    if(x<y)
        return x;
    else
        return y;
}


unsigned long long  max2(unsigned long long x,unsigned long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    unsigned long long i,j,k;
    unsigned long long n,m;

    scanf("%llu%llu",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%llu",&a[i]);
    }


    for(i=0;i<m;i++)
    {
        scanf("%llu",&b[i]);
    }

    sort(a,a+n);
    sort(b,b+m);

    unsigned long long sum=0;
    unsigned long long idx_a=0,idx_b=m-1;
    unsigned long long min_a,max_b;
    unsigned long long next_a,next_b;

    min_a=a[0];     max_b=b[m-1];

    if(min_a>=max_b)
    {
        printf("0");
        return 0;
    }

    for(i=0;;i++)
    {
        while(idx_a+1<n&&a[idx_a]==a[idx_a+1])
            idx_a++;

        while(idx_b-1>=0&&b[idx_b]==b[idx_b-1])
            idx_b--;

        if(idx_a!=n-1)
            next_a=min2(a[idx_a+1],max_b);
        else
            next_a=max_b;

        if(idx_b!=0)
            next_b=max2(b[idx_b-1],min_a);
        else
            next_b=min_a;

        if((idx_a+1)*(next_a-a[idx_a])<(m-idx_b)*(b[idx_b]-next_b))
        {
            sum+=(idx_a+1)*(next_a-a[idx_a]);

            a[idx_a]=next_a;

            if(idx_a+1<n){

                idx_a++;
            }

            min_a=next_a;
        }
        else
        {
            sum+=(m-idx_b)*(b[idx_b]-next_b);

            b[idx_b]=next_b;

            if(idx_b-1>=0){

                idx_b--;
            }
            max_b=next_b;
        }

        if(min_a>=max_b)
            break;

    }

    printf("%llu",sum);

    return 0;
}















