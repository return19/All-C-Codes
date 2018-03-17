#include<bits/stdc++.h>
using namespace std;
// D

long long x,y;
long long x11[2];
long long y11[2];

long long solve(long long idx,vector< pair< long long,pair<long long,long long> > > xp,vector< pair< long long,pair<long long,long long> > > yp)
{
    if(idx==2)
    {
        //cout<<"here"<<endl;
        sort(xp.begin(),xp.end());
        sort(yp.begin(),yp.end());

        //cout<<xp.size()<<" "<<yp.size()<<endl;


        long long ans=0;
        long long i,j,k;

        if(xp.size()>=1){
            ans++;
            long long p_y=xp[0].second.second;
            for(i=0;i<xp.size()-1;i++)
            {
                if(xp[i].first == xp[i+1].first){
                    if(xp[i+1].second.first<=p_y)
                        return INT_MAX;
                    else
                    {
                        p_y=xp[i+1].second.second;
                        ans++;
                    }
                }
                else
                {
                    p_y=xp[i+1].second.second;
                    ans++;
                }
            }
        }
        if(yp.size()==1)
            return ans+1;

        if(yp.size()==0)
            return ans;
        ans++;
        long long p_x=yp[0].second.second;
        for(i=0;i<yp.size()-1;i++)
        {
            if(yp[i].first==yp[i+1].first)
            {
                if(yp[i+1].second.first<=p_x)
                    p_x=max(p_x,yp[i+1].second.second);
                else
                {
                    p_x=yp[i+1].second.second;
                    ans++;
                }
            }
            else
            {
                p_x=yp[i+1].second.second;
                    ans++;
            }
        }
       // cout<<"here"<<endl;

        return ans;
    }

        if(x11[idx]==x){
            xp.push_back(make_pair(x,make_pair(min(y,y11[idx]),max(y,y11[idx]))));
            return solve(idx+1,xp,yp);
        }
        else if(y11[idx]==y){
            yp.push_back(make_pair(y,make_pair(min(x,x11[idx]),max(x,x11[idx]))));
            return solve(idx+1,xp,yp);
        }
        else
        {
            xp.push_back(make_pair(x11[idx],make_pair(min(y,y11[idx]),max(y,y11[idx]))));
            yp.push_back(make_pair(y,make_pair(min(x,x11[idx]),max(x,x11[idx]))));
            long long one=solve(idx+1,xp,yp);

            xp.pop_back();
            yp.pop_back();

            xp.push_back(make_pair(x,make_pair(min(y,y11[idx]),max(y,y11[idx]))));
            yp.push_back(make_pair(y11[idx],make_pair(min(x,x11[idx]),max(x,x11[idx]))));
            long long two=solve(idx+1,xp,yp);
            return min(one,two);
        }
}

int main()
{
    long long i,j,k;

    scanf("%lld%lld",&x,&y);
    scanf("%lld%lld",&x11[0],&y11[0]);
    scanf("%lld%lld",&x11[1],&y11[1]);

    vector< pair< long long,pair<long long,long long> > > xp;
    vector< pair< long long,pair<long long,long long> > > yp;

    long long ans=solve(0,xp,yp);
    printf("%lld\n",ans);

    return 0;
}

