#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;
int p,q,r,s;

int mx_xx1,mn_xx2;
int mx_yy1,mn_yy2;

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d",&p,&q,&r,&s);

        mx_xx1=max(a,p);
        mn_xx2=min(c,r);

        mx_yy1=max(b,q);
        mn_yy2=min(d,s);

        int ans=0;

        if(mx_xx1>mn_xx2)
            ans=0;
        else if(mx_yy1>mn_yy2)
            ans=0;
        else
            ans=(mn_xx2-mx_xx1)*(mn_yy2-mx_yy1);
        //cout<<ans<<endl;
        ans=(c-a)*(d-b) + (r-p)*(s-q) -ans;
        //cout<<ans;
        printf("%d\n",ans);
    }


    return 0;
}
