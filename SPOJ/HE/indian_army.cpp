#include<iostream>
using namespace std;

typedef struct co
{
    long x;
    long p;
}loc;
loc a[100010];
long s,e;

int unprtcd(loc x1,loc x2)
{
    if(x1.p+x2.p>=x2.x-x1.x)
    {
        return 0;
    }
    else
    {
        return (x2.x-x1.x-x2.p-x1.p);
    }
}

int start_un(loc x2,loc x1)
{
    if(x2.x-x1.x<=x1.p+x2.p)
    {
        return (x2.x-s);
    }
    else if(s<=x1.x+x1.p)
    {
        return (x2.x-x1.x-x1.p-x2.p);
    }
    else if(s<=x2.x-x2.p)
    {
        return (x2.x-x2.p-s);
    }
    else
    {
        return 0;
    }
}

int bSearch(int index,long search1)
{
    int lb=0,ub=index,mid,i;
    mid=(lb+ub)/2;
    if(search1<a[0].x)
    {
        return 0;
    }
    while(lb<=ub)
    {
        if(search1>a[mid].x)
        {
            lb=mid+1;
        }
        else if(search1<a[mid].x)
        {
            ub=mid-1;
        }
        else
        {

            break;
        }
        mid=(lb+ub)/2;
    }

   for(i=mid;a[i].x==a[mid].x;i++)
    {

    }
    return i;
}


