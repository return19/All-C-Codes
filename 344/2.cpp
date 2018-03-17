#include<bits/stdc++.h>
using namespace std;

long long n,m;

pair<long long,long long> row[101000];
pair<long long,long long> col[101000];

int main()
{
    long long i,j,k;
    long long x,y,z;

    scanf("%lld%lld%lld",&n,&m,&k);

    for(i=0;i<n;i++){
        row[i].second=INT_MIN;
    }

    for(i=0;i<m;i++)
        col[i].second=INT_MIN;


    for(i=0;i<k;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);

        y--;

        if(x==1)
        {
            row[y].first=z;
            row[y].second=i;
        }
        else
        {
            col[y].first=z;
            col[y].second=i;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(row[i].second>col[j].second)
            {
                printf("%lld ",row[i].first);
            }
            else
                printf("%lld ",col[j].first);
        }
        printf("\n");
    }

    return 0;
}

