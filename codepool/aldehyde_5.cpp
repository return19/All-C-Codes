#include<bits/stdc++.h>
using namespace std;

long long num[110],den[110];
int vis[110];
int n;

int main()
{
    int i,j,k;
    int test,t,idx,idy;
    long long mx;
    long long cmn,cur;
    long long lcm;
    long long curn,curd,mxn,mxd;

    cin>>test;
    cout<<50<<endl;

    for(t=0;t<50;t++)
    {
        cin>>n;
        for(i=0;i<n;i++){
            vis[i]=0;
            cin>>num[i]>>den[i];
            cmn=__gcd(num[i],den[i]);
            num[i]/=cmn;
            den[i]/=cmn;
        }

        for(i=0;i<n-1;i++)
        {
            mx=0;

            for(j=0;j<n;j++)
            {
                if(vis[j])
                    continue;
                for(k=0;k<n;k++)
                {
                    if(vis[k] || j==k)
                        continue;

                    if(den[j]*den[k]>=0 && den[j]*den[k]<1000000000000)
                    {
                        mx=1;
                        idx=j;
                        idy=k;
                    }
                }
            }

            if(mx==0)
                break;

            vis[idy]=1;

            num[idx]=num[idx]*den[idy] + num[idy]*den[idx];
            den[idx]=den[idx]*den[idy];

            cmn=__gcd(num[idx],den[idx]);
            num[idx]/=cmn;
            den[idx]/=cmn;

        }
        long long ans_num,ans_den;

        for(i=0;i<n;i++)
            if(!vis[i])
            {
                ans_num=num[i];
                ans_den=den[i];
                break;
            }



        cout<<ans_num<<" "<<ans_den<<endl;
    }






    return 0;
}

















