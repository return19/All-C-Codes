#include<bits/stdc++.h>
using namespace std;

long long p1[601000],p2[601000];
long long m1=1000000009;
long long m2=1234567069;
long long X=43;
set< pair<long long,long long> > hs;

int main()
{
    long long i,j,k;
    long long n,m;
    long long l;
    string s;

    p1[0]=1;
    p2[0]=1;
    for(i=1;i<600100;i++){
        p1[i]=(p1[i-1]*X)%m1;
        p2[i]=(p2[i-1]*X)%m2;
    }

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
    {
        cin>>s;
        l=s.length();

        long long hs1=0,hs2=0;
        for(j=0;j<l;j++)
        {
            hs1=(hs1*X + s[j]-'a' + 1)%m1;
            hs2=(hs2*X + s[j]-'a' + 1)%m2;
        }

        for(j=0;j<l;j++)
        {
            for(k=1;k<=3;k++)
            {
                if(s[j]-'a'+1 !=k)
                {
                    long long v1=s[j]-'a'+1;
                    long long t1=hs1,t2=hs2;
                    t1 -= v1*p1[l-j-1];
                    t2 -= v1*p2[l-j-1];
                    t1 += k*p1[l-j-1];
                    t2 += k*p2[l-j-1];

                    t1=t1%m1;
                    t2=t2%m2;
                    if(t1<0)
                        t1+=m1;
                    if(t2<0)
                        t2+=m2;
                    hs.insert(make_pair(t1,t2));
                }
            }
        }
    }

    for(i=0;i<m;i++)
    {
        cin>>s;
        l=s.length();
        long long hs1=0,hs2=0;

        for(j=0;j<l;j++)
        {
            hs1 = (hs1*X + s[j]-'a'+1)%m1;
            hs2 = (hs2*X + s[j]-'a'+1)%m2;
        }

        if(hs.find(make_pair(hs1,hs2))==hs.end())
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}











