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


/*int bSearch(int a[],int index,int search1)
{
    int i;
    for(i=0;i<index;i++)
    {
        if(search1<a[i])
        {
            return i;
        }
    }
    return i;
}*/
int nxm[100][5000];
int main()
{
    int test,n,m,level=999999;
    cin>>n;
    cin>>m;
    cin>>test;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>nxm[i][j];
        }
    }
    int strength,temp;
    for(int i=0;i<test;i++)
    {   level=999999;
        for(int j=0;j<n;j++)
        {
            cin>>strength;
            temp=bSearch(nxm[j],m-1,strength);

            if(level>temp)
            {
                level=temp;
            }
        }
        cout<<level<<endl;
    }

    return 0;
}
