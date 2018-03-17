#include<bits/stdc++.h>
using namespace std;

int row[105000];
int col[105000];


int main()
{
    long long t,m,n,q;
    long long x,y;
    long long tl;
    scanf("%lld",&t);

    while(t--){

        scanf("%lld%lld%lld",&m,&n,&q);
        tl = 0;
        long long tr=0,tc=0;
        for(int i=1;i<=m;i++)
            row[i] = 0;

        for(int i=1;i<=n;i++)
            col[i] = 0;

        row[1]=1;
        col[1]=1;

        row[m]=1;
        col[n]=1;

        for(int i=0;i<q;i++){
            scanf("%lld%lld",&x,&y);
            row[x] = 1;
            col[y] = 1;
        }

        for(int i=2;i<m;i++)
            if(row[i]==1)
                tr++;

        for(int i=2;i<n;i++)
            if(col[i]==1)
                tc++;

        long long ta;

        ta = (tr+1)*(tc+1);

        long long s = 1;
        long long rmx = 0,cmx = 0;
        long long rmn = m*n,cmn = m*n;

        for(int i=2;i<=m;i++){
            if(row[i]==1){
                if(i-s>rmx)
                    rmx = i-s;

                if(i-s<rmn)
                    rmn = i-s;

                s = i;
            }
        }

        s = 1;
        for(int i=2;i<=n;i++){
            if(col[i]==1){
                if(i-s>cmx)
                    cmx = i-s;

                if(i-s<cmn)
                    cmn = i-s;

                s = i;
            }
        }

        long long amn,amx;

        amn = rmn*cmn;
        amx = rmx*cmx;

        printf("%lld %lld %lld\n",ta,amn,amx);


    }
}

