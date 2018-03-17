#include<bits/stdc++.h>
using namespace std;

#define MAX 99999999

int arr[1010];
int cost[210][210];
int n,l;

int memo[1010][210][210];

int solve(int idx,int one,int two)
{
    if(idx>n)
    {
        return 0;
    }

    if(memo[idx][one][two]!=-1)
        return memo[idx][one][two];

    int x,y,z;
    x = cost[arr[idx-1]][arr[idx]] + solve(idx+1,one,two);
    y = cost[one][arr[idx]] + solve(idx+1,two,arr[idx-1]);
    z = cost[two][arr[idx]] + solve(idx+1,one,arr[idx-1]);

    return memo[idx][one][two]=min(x,min(y,z));
}

int solve1(int idx,int one,int two)
{
    return memo[idx][one][two];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int i,j,k;
    int test,t;

    //scanf("%d",&test);
    cin>>test;

    for(t=0;t<test;t++)
    {
        //scanf("%d%d",&l,&n);
        cin>>l>>n;

        for(i=0;i<=n;i++)
            for(j=0;j<=l;j++)
                for(k=0;k<=l;k++)
                    memo[i][j][k]=-1;

        for(i=0;i<l;i++)
            for(j=0;j<l;j++)
                cin>>cost[i][j];
                //scanf("%d",&cost[i][j]);
        for(i=1;i<=n;i++){
            cin>>arr[i];
            //scanf("%d",&arr[i]);
            arr[i]--;
        }
        arr[0]=2;

       for(int idx=n+1;idx>=1;idx--)
        {
            for(int one=0;one<=l;one++)
            {
                for(int two=0;two<=l;two++)
                {
                    if(idx>n)
                    {
                        memo[idx][one][two] = 0;
                        continue;
                    }

                    if(arr[idx-1]==one || arr[idx-1]==two || one==two)
                    {
                        memo[idx][one][two]=MAX;
                        continue;
                    }

                    int x,y,z;
                    x = cost[arr[idx-1]][arr[idx]] + solve1(idx+1,one,two);
                    y = cost[one][arr[idx]] + solve1(idx+1,two,arr[idx-1]);
                    z = cost[two][arr[idx]] + solve1(idx+1,one,arr[idx-1]);
                    memo[idx][one][two]=min(x,min(y,z));
                }
            }
        }

        int ans=solve1(1,0,1);
        printf("%d\n",ans);
    }
    return 0;
}
