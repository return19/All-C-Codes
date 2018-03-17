#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> v;
string s;
int n,m;

int check(string s)
{
    if(v.find(s)!=v.end())
    {
        printf("YES\n");
        return 1;
    }
    return 0;
}

int main()
{
    int i,j,k;
    int l;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        cin>>s;
        v[s]++;
    }

    for(i=0;i<m;i++)
    {
        cin>>s;
        l=s.length();
        int f=0;

        for(j=0;j<l;j++)
        {
            if(s[j]=='a')
            {
                s[j]='b';
                f=check(s);
                if(f)   break;
                s[j]='c';
                f=check(s);
                if(f)   break;
                s[j]='a';

            }else if(s[j]=='b')
            {
                s[j]='a';
                f=check(s);
                if(f)   break;
                s[j]='c';
                f=check(s);
                if(f)   break;
                s[j]='b';
            }else // c
            {
                s[j]='a';
                f=check(s);
                if(f)   break;
                s[j]='b';
                f=check(s);
                if(f)   break;
                s[j]='c';
            }
        }

        if(f==0)
            printf("NO\n");
    }

    return 0;
}










