#include<bits/stdc++.h>
using namespace std;

long long arr[1000100];
long long st[10000100];

long long tb[100000100];

long long max2(long long x, long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long min2(long long x, long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long midval(long long s, long long e)
{
    return (s+e)/2;
}

long long calval(long long *st,long long ss,long long se,long long qs,long long qe,long long index)
{
    if (qs<=ss&&qe>=se)
        return st[index];

    if (se<qs||ss>qe)
        return -1;

    long long mid=midval(ss, se);
    return max2(calval(st,ss,mid,qs,qe,2*index+1),
                  calval(st,mid+1,se,qs,qe,2*index+2));
}

long long qry(long long *st,long long n,long long qs,long long qe)
{
    if (qs<0||qe>n-1||qs>qe)
    {
        return -1;
    }

    return calval(st,0,n-1,qs,qe,0);
}

long long strtconstr(long long arr[],long long ss,long long se,long long *st,long long si)
{
    if (ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }

    long long mid=midval(ss, se);
    st[si]=max2(strtconstr(arr,ss,mid,st,si*2+1),strtconstr(arr, mid+1, se, st, si*2+2));
    return st[si];
}

void initconstr(long long arr[], long long n)
{
    strtconstr(arr, 0, n-1, st, 0);
}

int main()
{
    long long n,i,j,k,x,y,x1,y1,m;
    long long v1,v2,val;
    long long TB=-1,x_s,y_s;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    initconstr(arr,n);

    scanf("%lld%lld%lld",&m,&x,&y);

    long long sum=0;

    x_s=x;
    y_s=y;

   // cout<<"here : "<<qry(st,n,x,y)<<endl;
   // cout<<"here : "<<qry(st,n,x,y+1)<<endl;

        v1=(x+7)%(n-1);
        v2=(y+11)%(n);

    for(i=1;i<=m;i++)
    {
        x1=min2(x,y);
        y1=max2(x,y);

        val=qry(st,n,x1,y1);

            tb[++TB]=val;

        sum=sum+val;

        x=(x+7)%(n-1);
        y=(y+11)%(n);

        if(i!=1&&x==v1&&y==v2)
        {
            //cout<<"here"<<endl;
            for(j=i+1,k=0;j<=m;j++,k++)
            {
                sum=sum+tb[k%(TB+1)];
            }
            i=m+2;
        }
        else if(x==x_s&&y==y_s)
        {
            for(j=i+1,k=0;j<=m;j++,k++)
            {
                sum=sum+tb[1+k%(TB)];
            }
            i=m+2;
        }
    }

    printf("%lld\n",sum);


    return 0;
}


