#include<bits/stdc++.h>
using namespace std;

int arr[301000];


struct elem
{
    int x;
    int y;
};

elem q[110];

bool cmp(elem a,elem b)
{
    if ((a.y-a.x)==(b.y-b.x))
    {
        return a.x<b.x;
    }
    return (a.y-a.x)<(b.y-b.x);
}

void para(int x,int y)
{
    int i,j,k;
    int cur=1;

    for(i=x;i<=y;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=cur;

            if(cur==1)
                cur=-1;
            else
                cur=1;
        }
    }
}

int main()
{
    int test,i,j,k;
    int n;

    int x,y;

    int c1=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);

        for(j=0;j<n;j++)
            arr[j]=0;

        for(j=0;j<k;j++)
        {
            scanf("%d%d",&x,&y);
            q[j].x=x;
            q[j].y=y;
        }

        sort(q,q+k,cmp);

       // for(j=0;j<k;j++)
         //   cout<<q[j].x<<" "<<q[j].y<<endl;


        for(j=0;j<k;j++)
        {
            x=q[j].x;
            y=q[j].y;

            para(x,y);

        }
        para(0,n-1);

        for(j=0;j<n;j++)
        {
            if(arr[j]==1)
                printf("(");
            else if(arr[j]==-1)
            {
                printf(")");
            }

        }

        printf("\n");
    }

    return 0;
}







