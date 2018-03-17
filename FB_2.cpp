#include<bits/stdc++.h>
using namespace std;

map<int,int> memo;

int main()
{
    int test,i,j,k,n;
    int temp,max1=-9999;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        max1=-99999;
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            memo[temp]++;
            if(max1<memo[temp])
                max1=memo[temp];
        }

        printf("%d\n",n-max1);

    }

    return 0;
}
