#include<bits/stdc++.h>
using namespace std;

long long v[4100],d[4100],p[4100];
long long n;
vector<long long> ans;

int main()
{
    long long i,j,k;
    long long x,y,z;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        v[i]=x;
        d[i]=y;
        p[i]=z;
    }

    for(i=0;i<n;i++)
    {
        if(p[i]<0)
            continue;
        ans.push_back(i+1);
        long long vd=v[i];
        long long dd=0;

        for(j=i+1;j<n;j++)
        {
            if(p[j]<0)
                continue;
            p[j] =p[j] - vd - dd;
            vd--;
            if(p[j]<0)
                dd+=d[j];

            if(vd==0){
                j++;
                for(;j<n;j++)
                {
                    if(p[j]<0)
                        continue;
                    p[j]=p[j]-dd;
                    if(p[j]<0)
                        dd+=d[j];
                }
                break;
            }
        }
    }

    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)
        printf("%lld ",ans[i]);
    printf("\n");

    return 0;
}
