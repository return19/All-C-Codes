#include<bits/stdc++.h>
using namespace std;

long long h(long long x)
{
    long long ans=0;

    while(x!=1)
    {
        ans++;
        x/=2;
    }
    return ans;
}

string path(long long x,long long lca)
{
    long long i,j,k;
    string s="";

    while(x!=lca)
    {
        if(x%2==0)
            s.push_back('l');
        else
            s.push_back('r');
        x/=2;
    }
    long long n=s.length();
    for(i=0,j=n-1;i<j;i++,j--)
        swap(s[i],s[j]);

    return s;
}

long long down(long long root,string s)
{
    long long i,j,k;
    long long n=s.length();

    for(i=0;i<n;i++)
    {
        if(s[i]=='l')
            root*=2;
        else
            root=root*2 + 1;
    }
    return root;
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long l,r;
    long long n;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld",&n,&l,&r);

        /*if(l==r)
        {
            printf("%lld\n",n);
            continue;
        }*/

        if(l>r)
            swap(l,r);

        long long hl=h(l),hr=h(r);
        //cout<<hl<<" "<<hr<<endl;
        string sl,sr;
        long long lca;
        long long tl=l,tr=r;

        while(hl>hr){
            tl/=2;
            hl--;
        }
        while(hl<hr){// hl<hr
            tr/=2;
            hr--;
        }
        //cout<<tl<<" "<<tr<<endl;
        while(tl!=tr)
        {
            tl=tl/2;
            tr=tr/2;
        }
        //cout<<tl<<" "<<tr<<endl;
        lca=tl;

        sl=path(l,lca);
        sr=path(r,lca);

        long long sz=max(sl.length(),sr.length());
        sz=pow(2,sz);

       // cout<<lca<<endl;
       // cout<<sl<<" "<<sr<<endl;

        long long tp=0;
        long long st=down(1,sr),ed=-1;

        if(st>n)
        {
            printf("0\n");
            continue;
        }

        n=n-st;

        printf("%lld\n",(n)/sz + 1);
    }
    return 0;
}















