#include<bits/stdc++.h>
using namespace std;

map<string,int> memo;

char str[101000];

string s;

int n;

int main()
{
    int test,i,j,k,t;
    int ans=0;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",str);

        n=strlen(str);
        ans=0;

        for(i=0;i<n-1;i++)
        {
            s="";
            s.push_back(str[i]);
            s.push_back(str[i+1]);

            //cout<<s<<endl;

            memo[s]++;

            if(memo[s]==1)
                ans++;
        }

        printf("%d\n",ans);

        memo.clear();

    }

    return 0;
}








