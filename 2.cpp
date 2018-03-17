#include<bits/stdc++.h>
using namespace std;

long long ma,md,mh;
long long ya,yd,yh;
long long ca,cd,ch;
long long mdec, ydec;

long long solve(long long ht,long long atk,long long def)
{
    double yt,mt;

     if(mh == 0 && yh + ht >0)
        return 1;

    if(yh+ht==0)
        return 0;

    if(ya + atk - md <= 0)
        return 0;

    if(ma - yd - def <=0)
        return 1;

    yt = ceil((yh + ht)/((double)(ma - yd - def)));
    mt = ceil((mh)/((double)(ya + atk - md)));

    if(yt > mt)
        return 1;
    return 0;
}


int main()
{
    cin>>yh>>ya>>yd;
    cin>>mh>>ma>>md;
    cin>>ch>>ca>>cd;

    mdec = ya - md;
    ydec = ma - yd;

    long long ans = LLONG_MAX;

    for(long long i=0;i<150;i++){
        for(long long j=0;j<150;j++){
            for(long long k=0;k<150;k++){

                if(solve(i,j,k)){
                    ans = min(ans, i*ch + j*ca + k*cd);
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
