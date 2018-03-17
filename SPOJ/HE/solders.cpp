#include<iostream>
using namespace std;
int min_l(int lb,int ub)
{
    int mid=(lb+ub)/2;
    if(lb<mid&&mid<ub)
    {
        return (ub-lb+min_l(lb,mid)+min_l(mid,ub));
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,m,t,i,j,max_lth,min_lth;
    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        max_lth=0;
        for(j=2;j<=n+1;j++)
        {
            max_lth+=j;

        }
        min_lth=min_l(0,n+1);

        if(m<min_lth)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(m>=min_lth&&m<=max_lth)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            cout<<m-max_lth<<endl;
            continue;
        }


    }
    return 0;
}

