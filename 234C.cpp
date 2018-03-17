#include<bits/stdc++.h>
using namespace std;

long long n;
//wa
long long arr[101000];

// 0---> -
// 1---> +

int memo1[101000][2];
int memo2[101000][2];
int base[101000][2];

pair<long long,long long> solve(long long idx,long long prev)
{
    if(idx==n)
    {
        return make_pair(0,0);
    }

    if(base[idx][prev]==1)
        return make_pair(memo1[idx][prev],memo2[idx][prev]);
    base[idx][prev]=1;

    pair<long long,long long> tk,nt,ans;

    if(arr[idx]>0)
    {
        if(prev==0)
        {
            tk=solve(idx+1,1);
            nt=solve(idx+1,0);

            if(tk.first<nt.first+1)
                ans= make_pair(tk.first,tk.second + 1);
            else
                ans= make_pair(1+nt.first,nt.second);
        }
        else
            {
                    tk=solve(idx+1,1);

                    ans= make_pair(tk.first,tk.second+1);
            }
    }
    else if(arr[idx]<0)
    {
        if(prev==0){
            tk=solve(idx+1,0);
            nt=solve(idx+1,1);

            if(tk.first>nt.first+1)
                ans= make_pair(nt.first+1,nt.second+1);
            else
                ans= make_pair(tk.first,tk.second);
        }
        else{

            tk= solve(idx+1,1);
            ans= make_pair(1+tk.first,tk.second+1);
        }
    }
    else
    {
        if(prev==0)
        {
            tk=solve(idx+1,0);
            nt=solve(idx+1,1);

            if(tk.first<nt.first)
            {
                ans= make_pair(tk.first+1,tk.second);
            }
            else
                ans= make_pair(tk.first+1,tk.second+1);
        }
        else
        {
            tk=solve(idx+1,1);

            ans= make_pair(tk.first+1,tk.second+1);
        }
    }

    memo1[idx][prev]=ans.first;
    memo2[idx][prev]=ans.second;
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    long long i,j,k;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    pair<long long,long long> ans=solve(0,0);


    if((ans.second==n && arr[0]!=0) || (ans.second==0 && arr[n-1]!=0))
        ans.first++;

    printf("%lld",ans.first);

    return 0;
}
