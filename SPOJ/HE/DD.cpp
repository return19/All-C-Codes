#include<stdio.h>

long long a[100005];
inline long long count(long long index)
{
    long long i;
    long long sum=0;
    for(i=0;i<index;i++)
    {
        sum+=a[i];
    }
    return sum;
}

inline long long sum1(long long index)
{
    return (index*(index+1))/2;
}
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(sum1(n)==count(n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
