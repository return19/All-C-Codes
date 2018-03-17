#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f;

char arr[1010][1010];

int main()
{
    int i,j,k;
    int n;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);

    if(a>b)
        swap(a,b);

    int area= (a*b) + (c*d) + (e*f);

    n=sqrt(area);

    if(n*n != area)
    {
        printf("-1\n");
        return 0;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j]='-';


    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            arr[i][j]='A';

    if(b==n)
    {
        if(n-a==c || n-a==d)
        {
            if(n-a==d)
                swap(c,d);
            for(i=a;i<n;i++)
                for(j=0;j<d;j++)
                    arr[i][j]='B';
            for(i=a;i<n;i++)
                for(j=d;j<n;j++)
                    arr[i][j]='C';

        }else{
            if(c>d) swap(c,d);
            for(i=a;i<a+c;i++)
                for(j=0;j<n;j++)
                    arr[i][j]='B';
            for(i=a+c;i<n;i++)
                for(j=0;j<n;j++)
                    arr[i][j]='C';
        }
    }else{

        if(c>d) swap(c,d);
        if(e>f) swap(e,f);

        int x,y,p,q;

        x=n-a;  y=n;
        p=n-b;    q=a;

        if(x>y) swap(x,y);
        if(p>q) swap(p,q);

        if(x==c && y==d && e==p && f==q)
        {
            for(i=a;i<n;i++)
                for(j=0;j<n;j++)
                    arr[i][j]='B';
            for(i=0;i<a;i++)
                for(j=b;j<n;j++)
                    arr[i][j]='C';
        }else if(c==p && d==q && e==x && f==y)
        {
            for(i=a;i<n;i++)
                for(j=0;j<n;j++)
                    arr[i][j]='C';
            for(i=0;i<a;i++)
                for(j=b;j<n;j++)
                    arr[i][j]='B';
        }

        x=n-a;  y=b;
        p=n;    q=n-b;

        if(x>y) swap(x,y);
        if(p>q) swap(p,q);

        if(x==c && y==d && e==p && f==q)
        {
            for(i=a;i<n;i++)
                for(j=0;j<b;j++)
                    arr[i][j]='B';
            for(i=0;i<n;i++)
                for(j=b;j<n;j++)
                    arr[i][j]='C';
        }else if(c==p && d==q && e==x && f==y)
        {
           for(i=a;i<n;i++)
                for(j=0;j<b;j++)
                    arr[i][j]='C';
            for(i=0;i<n;i++)
                for(j=b;j<n;j++)
                    arr[i][j]='B';
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='-')
            {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n",n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j];
        cout<<endl;
    }

    return 0;
}




















