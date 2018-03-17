#include<bits/stdc++.h>
using namespace std;

map<long long,long long> m1;
map<long long,long long> m2;

long long arr1[100010];
long long n1,n2,N1=-1,N2=-1;
//long long arr2[1010];

long long positive(long long x)
{
    if(x>0)
        return x;
    else
        return x*(-1);
}

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long bs(long long x)
{
    long long first=0,last=n1-1,mid;
    long long a,b,c,ans;

    mid=(first+last)/2;

    while(last-first>1)
    {
        mid=(first+last)/2;

        if(arr1[mid]==x||arr1[first]==x||arr1[last]==x)
            return 0;

        if(x<arr1[mid]){
            last=mid;
        }
        else if(x>arr1[mid])
        {
            first=mid;
        }

        mid=(first+last)/2;
    }
    a=positive(arr1[first]-x);
    b=positive(arr1[mid]-x);
    c=positive(arr1[last]-x);

    ans=min2(min2(a,b),c);
    return ans;

}

int main()
{
    long long test,i,j,k;
    long long temp1,temp2,min1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        N1=-1;
        N2=-1;
        m1.clear();
        m2.clear();
        min1=99999999;
        scanf("%lld",&n1);

        for(j=0;j<n1;j++)
        {
            scanf("%lld",&temp1);
            if(m1[temp1])
            {
                continue;
            }
            m1[temp1]++;
            arr1[++N1]=temp1;
        }
        n1=N1+1;

        sort(arr1,arr1+n1);

        scanf("%lld",&n2);

        for(j=0;j<n2;j++)
        {
            scanf("%lld",&temp1);
            if(m2[temp1])
                continue;
            m2[temp1]++;

            if(m1[temp1])
            {
                min1=0;
                j++;
                while(j<n2)
                {
                    scanf("%lld",&temp1);
                    j++;
                }
                break;
            }

            temp2=bs(temp1);
            if(min1>temp2)
                min1=temp2;

        }

        printf("%lld\n",min1);
    }

    return 0;
}
