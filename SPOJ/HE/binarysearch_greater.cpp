#include<iostream>
using namespace std;

int bSearch(int a[],int index,int search1)
{
    int lb=0,ub=index,mid,i;
    mid=(lb+ub)/2;
    if(search1<a[0])
    {
        return 0;
    }
    while(lb<=ub)
    {
        if(search1>a[mid])
        {
            lb=mid+1;
        }
        else if(search1<a[mid])
        {
            ub=mid-1;
        }
        else
        {

            break;
        }
        mid=(lb+ub)/2;
    }

   for(i=mid;a[i]==a[mid];i++)
    {

    }
    return i;
}

int main()
{
    int a[100],i,n,srch;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>srch;

    cout<<bSearch(a,n-1,srch);
    return 0;
}
