#include<bits/stdc++.h>
using namespace std;

char str[501000];
long long offs=1000010;

long long xsum[2010000],ysum[2010000];

int main()
{
    long long i,j,k;
    long long n,m;
    long long x,y;
    long long mxx=LLONG_MIN,mxy=LLONG_MIN;
    long long ans=0;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);

        ans += abs(x) + abs(y);

        xsum[x+offs]++;
        ysum[y+offs]++;

        mxx=max(mxx,x+offs);
        mxy=max(mxy,y+offs);
    }

    for(i=1;i<=mxx;i++)
        xsum[i]+=xsum[i-1];

    for(i=1;i<=mxy;i++)
        ysum[i]+=ysum[i-1];

    scanf("%s",str);
    long long l=strlen(str);

    for(i=0;i<l;i++)
    {
        if(str[i]=='D')
            str[i]='L';
        else if(str[i]=='U')
            str[i]='R';
        else if(str[i]=='L')
            str[i]='U';
        else
            str[i]='D';
    }

    long long cx=offs,cy=offs;

    //cout<<str<<endl;

    for(i=0;i<l;i++)
    {
        if(str[i]=='L')
        {
            ans = ans - ysum[cy-1] + (n-ysum[cy-1]);
            cy--;
        }
        else if(str[i]=='U')
        {
            ans = ans -xsum[cx-1] + (n- xsum[cx-1]);
            cx--;
        }else if(str[i]=='D')
        {
            ans = ans +xsum[cx] - (n- xsum[cx]);
            cx++;
        }else if(str[i]=='R')
        {
            ans = ans + ysum[cy] - (n-ysum[cy]);
            cy++;
        }

        printf("%lld\n",ans);
    }

    return 0;
}











