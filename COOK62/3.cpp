#include<bits/stdc++.h>
using namespace std;

typedef struct st
{
    int a;
    int b;

}elem;

elem arr[5100];

int cmp(elem &x,elem &y)
{
    if(x.i<=y.i)
    {
        if(x.a+x.b*y.i>y.a+y.b*y.i)
        {

            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(x.a+x.b*x.i>=y.a+y.b*x.i)
        {
            return 1;
        }
        else
        {
            swap(x.i,y.i);
            return 0;
        }
    }
}


int main()
{
    int test,i,j,k;
    int t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].a);
        }

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].b);
            arr[i].i=i;
        }

        sort(arr,arr+n,cmp);

        for(i=0;i<n;i++)
        {
            cout<<arr[i].a<<" ";
        }

        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<arr[i].b<<" ";
        }

        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<arr[i].i<<" ";
        }

        cout<<endl;
    }

    return 0;
}

