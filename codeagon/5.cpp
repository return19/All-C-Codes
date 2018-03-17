#include<bits/stdc++.h>
using namespace std;

struct elem
{
    int x,y,z;
};

elem a[100100];

bool cmp(elem a,elem b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
        {
            return a.z<b.z;
        }
        else
            return a.y<b.y;
    }
    else
        return a.x<b.x;
}

bool cmp1(elem a,int b)
{
    return a.x<b;
}

bool cmp2(int a,elem b)
{
    return a<b.x;
}

bool cmp3(elem a,int b)
{
    return a.y<b;
}

bool cmp4(int a,elem b)
{
    return a<b.y;
}

bool cmp5(elem a,int b)
{
    return a.z<b;
}

bool cmp6(int a,elem b)
{
    return a<b.z;
}

int main()
{
    int i,j,k;

    int n,m;


    int x,y,z;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        a[i].x=x;   a[i].y=y;   a[i].z=z;
    }

    sort(a,a+n,cmp);

    /*for(i=0;i<n;i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    }*/

    scanf("%d",&k);
    int x1,y1,z1;
    for(i=0;i<k;i++)
    {
        scanf("%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1);

        int c=0;

        int low1=lower_bound(a,a+n,x,cmp1)-a-6;
        int high1=upper_bound(a,a+n,x1,cmp2)-a+6;



        int low2=lower_bound(a+max(0,low1),a+min(n,high1),y,cmp3)-a-6;
        int high2=upper_bound(a+max(0,low1),a+min(n,high1),y1,cmp4)-a+6;



        int low3=lower_bound(a+max(0,low2),a+min(n,high2),z,cmp5)-a-6;
        int high3=upper_bound(a+max(0,low2),a+min(n,high2),z1,cmp6)-a+6;




        for(j=max(0,low3);j<=high3&&j<n;j++)
        {
            if(a[j].x>=x&&a[j].x<=x1&&
               a[j].y>=y&&a[j].y<=y1&&
               a[j].z>=z&&a[j].z<=z1&&
                a[j].x-4>=x&&a[j].x-4<=x1&&
               a[j].y-4>=y&&a[j].y-4<=y1&&
               a[j].z-4>=z&&a[j].z-4<=z1)
               {
                   c++;
               }
        }
        printf("%d\n",c);
    }


    return 0;
}





