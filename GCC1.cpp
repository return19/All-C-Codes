#include<bits/stdc++.h>
using namespace std;
#define MIN -999999999999999
long long arr[50010],n;
long long st[500010];
long long qry(long long ss,long long se,long long qs,long long qe,long long index);
long long construct(long long ss,long long se,long long index);

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long qry(long long ss,long long se,long long qs,long long qe,long long index)
{
    if(qs>se||qe<ss)
        return MIN;
    if(ss>=qs&&se<=qe)
        return st[index];
    long long mid=(ss+se)/2;
    long long temp;
    temp=max2(qry(ss,mid,qs,qe,2*index+1),qry(mid+1,se,qs,qe,2*index+2));

    return max2(qry(ss,mid,qs,qe,2*index+1)+qry(mid+1,se,qs,qe,2*index+2),temp);
}

long long construct(long long ss,long long se,long long index)
{
    if(ss==se)
    {
        st[index]=arr[ss];
        return st[index];
    }
    else
    {
        long long mid=(ss+se)/2,temp;
        temp=max2(construct(ss,mid,2*index+1),construct(mid+1,se,2*index+2));
        st[index]=max2(temp,construct(ss,mid,2*index+1)+construct(mid+1,se,2*index+2));
        return st[index];
    }

}

int main()
{
    long long test,i,j,k,q,n;
    long long a,b;
    //scanf("%d",&test);
    //for(i=0;i<test;i++)

        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        construct(0,n-1,0);

       /* for(j=0;j<2*pow(2,(ceil(log2(n))))-1;j++)
            cout<<st[j]<<" ";
        cout<<endl;*/

        scanf("%lld",&q);


        for(j=0;j<q;j++)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",qry(0,n-1,a-1,b-1,0));
        }
    //}

    return 0;
}
