#include<bits/stdc++.h>
using namespace std;

long long lcs[1010][1010];
long long bt[1010][1010];

long long n,m;

char a[1010];
char b[1010];

vector<string> v;

map< string,long long > memo;
map< string,long long >::iterator it;

void str_reverse(string &str)
{
    int i,j,k;

    for(i=0,j=str.length()-1;i<j;i++,j--)
        swap(str[i],str[j]);
}

void solve(long long x,long long y,string str)
{
    if(x==0||y==0)
    {
        str_reverse(str);

        memo[str]=1;
        return;
    }

    if(bt[x][y]==2)
    {
        str.push_back(a[x-1]);
        solve(x-1,y-1,str);
    }
    else if(bt[x][y]==1)
    {
        solve(x,y-1,str);
    }
    else if(bt[x][y]==3)
    {
        solve(x-1,y,str);
    }
    else
    {
        solve(x-1,y,str);
        solve(x,y-1,str);
    }
}

int main()
{
    long long test,i,j,k,t;

    scanf("%lld%lld",&n,&k);

    scanf("%s",a);
    scanf("%s",b);

    m=n;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                bt[i][j]=2;
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else if(lcs[i-1][j]>lcs[i][j-1])
            {
                bt[i][j]=3;
                lcs[i][j]=lcs[i-1][j];
            }
            else if(lcs[i-1][j]<lcs[i][j-1])
            {
                bt[i][j]=1;
                lcs[i][j]=lcs[i][j-1];
            }
            else
            {
                lcs[i][j]=lcs[i-1][j];
                bt[i][j]=0;
            }
        }
    }

    if(lcs[n][n]==0)
    {
        printf("-1\n");
        return 0;
    }

    string s="";

    solve(n,m,s);

    j=0;

    for(it=memo.begin();it!=memo.end();it++)
    {
        //cout<<it->first<<endl;
        j++;
       if(j==k)
       {
           cout<<it->first<<endl;
           return 0;
       }
    }


    printf("-1\n");

    return 0;
}

