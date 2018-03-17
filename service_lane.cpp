#include<bits/stdc++.h>
using namespace std;

int arr[110000];
int a[110000];
int b[110000];
int c[110000];


int main()
{
    int t,n;
    int i,j,k;

    scanf("%d%d",&n,&t);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    a[0]=0;
    b[0]=0;
    c[0]=0;

    for(i=1;i<=n;i++)
    {
        if(arr[i]==1)
        {
            a[i]=a[i-1]+1;
            b[i]=b[i-1]+0;
            c[i]=c[i-1]+0;
        }
        else if(arr[i]==2)
        {

            a[i]=a[i-1]+0;
            b[i]=b[i-1]+1;
            c[i]=c[i-1]+0;
        }
        else
        {

            a[i]=a[i-1]+0;
            b[i]=b[i-1]+0;
            c[i]=c[i-1]+1;
        }
    }

    int x,y;
    int a1,b1,c1;

    for(i=0;i<t;i++)
    {
        scanf("%d%d",&x,&y);

        x++;
        y++;

        a1=a[y]-a[x-1];
        b1=b[y]-b[x-1];
        c1=c[y]-c[x-1];

        if(a1!=0)
        {
            printf("1\n");
            continue;
        }

        if(b1!=0)
        {
            printf("2\n");
            continue;
        }

        printf("3\n");

    }

    return 0;
}
