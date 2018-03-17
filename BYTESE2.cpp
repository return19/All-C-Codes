#include<bits/stdc++.h>
using namespace std;

map<int,int> memo;
map<int,int>::iterator it;
int main()
{
    int test,n,i,j,k;
    int ans,max1;
    int temp;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();

        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            memo[temp]=1;
            scanf("%d",&temp);
            memo[temp]=2;
        }

        ans=0;
        max1=0;
        for(it=memo.begin();it!=memo.end();it++)
        {
            if(it->second==1)
                ans++;
            else
                ans--;

            if(max1<ans)
                max1=ans;
        }

        printf("%d\n",max1);
    }
}
