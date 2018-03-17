#include<iostream>
#include<cmath>
using namespace std;

int a[100010];

int qsort(int lb,int ub)
{
    int pivot=lb;
    int i=lb,j=ub,t;
   while(i<j)
    {   while(a[i]<=a[pivot]&&i<ub)
            i++;
        while(a[j]>a[pivot]&&j>=lb)
            j--;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[j];
    a[j]=a[pivot];
    a[pivot]=t;
    return j;
}

void part(int lb,int ub)
{
    if(lb<ub)
    {
        int i;
        i=qsort(lb,ub);
        part(lb,i-1);
        part(i+1,ub);
    }
}


int main()
{
    int test,n,i,j,val;
    int great;
    cin>>test;

    for(i=0;i<test;i++)
    {
        cin>>n;
        val=pow(2,n);
        for(j=0;j<val;j++)
        {
            cin>>a[j];

        }
        part(0,val-1);
       /*for(j=0;j<val;j++)
            cout<<a[j]<<" ";*/
        great=a[val-1];
        for(j=val-2;j>=val-2-n+1;j--)
        {
            cout<<great-a[j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
