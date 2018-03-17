#include<iostream>
using namespace std;
typedef struct marr
{
    unsigned long  a;
    unsigned long  b;
}arr;
marr fm[100010];
long long inters,i,j;

void trav(long long index)
{
    for(i=0;i<index;i++)
    {
        for(j=0;j<i;j++)
        {
            if(fm[j].b>fm[i].b)
            {
                inters++;
            }
        }
    }
}

long long qsort(long long lb,long long ub)
{long long piv=lb,t;
    i=lb;j=ub;
    while(i<j)
    {
    while(fm[i].a<=fm[piv].a&&i<=ub)
        i++;
    while(fm[j].a>fm[piv].a&&j>=lb)
        j--;
        if(i<j)
        {
            t=fm[i].a;
            fm[i].a=fm[j].a;
            fm[j].a=t;
            t=fm[i].b;
            fm[i].b=fm[j].b;
            fm[j].b=t;
        }
    }
            t=fm[piv].a;
            fm[piv].a=fm[j].a;
            fm[j].a=t;
            t=fm[piv].b;
            fm[piv].b=fm[j].b;
            fm[j].b=t;

            return j;
}

void part(long long lb,long long ub)
{
    if(lb<ub)
    {
       long long piv=qsort(lb,ub);
       part(lb,piv-1);
       part(piv+1,ub);

    }
}



int main()
{
    long long n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>fm[i].a;
        cin>>fm[i].b;
    }
    part(0,n-1);
    trav(n);
    cout<<inters;

    return 0;
}
