#include<bits/stdc++.h>
using namespace std;

long long d[101000];
stack<long long> s;

long long a[101000]; // closest to i to left such that d[j] >= d[i]
long long b[101000]; // closest to i to right such that d[j] > d[i]
int main()
{
    long long i,j,k;
    long long n,q;

    scanf("%lld%lld",&n,&q);

    scanf("%lld",&d[0]);

    for(i=1;i<n;i++)
    {
        scanf("%lld",&d[i]);
        d[i-1]=abs(d[i-1]-d[i]);
    }



    /*for(i=0;i<n-1;i++)
        cout<<b[i]<<"\t";
    cout<<endl;*/
    long long x,y;
    for(k=0;k<q;k++)
    {
        scanf("%lld%lld",&x,&y);
        x--;    y--;
        if(x==y)
        {
            printf("0\n");
            continue;
        }

        for(i=x;i<y;i++)
        {
            if(s.empty())
            {
                a[i]=x-1;
                s.push(i);
            }
            else
            {
                while( !s.empty() && d[s.top()]<d[i])
                {
                    s.pop();
                }

                if(s.empty()){
                    a[i]=x-1;
                    s.push(i);
                    continue;
                }

                a[i]=s.top();
                s.push(i);
            }
        }

        /*for(i=0;i<n-1;i++)
            cout<<d[i]<<"\t";
        cout<<endl;

        for(i=0;i<n-1;i++)
            cout<<a[i]<<"\t";
        cout<<endl;*/

        while(!s.empty())
            s.pop();

        for(i=y-1;i>=x;i--)
        {
            if(s.empty())
            {
                b[i]=y;
                s.push(i);
            }
            else
            {
                while( !s.empty() && d[s.top()]<=d[i])
                {
                    s.pop();
                }

                if(s.empty()){
                    b[i]=y;
                    s.push(i);
                    continue;
                }

                b[i]=s.top();
                s.push(i);
            }
        }

    while(!s.empty())
        s.pop();

        long long ans=0;
        for(j=x;j<y;j++)
        {
            ans += d[j]*(j-a[j])*(b[j]-j);
        }
        printf("%lld\n",ans);
    }

    return 0;
}













