#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[201000];
vector< pair<int,int> > q;

vector< pair<int,int> > resq;
vector< pair<int,int> > fq;

int ans[201000];

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        q.push_back(make_pair(x,y));
    }

    for(i=0;i<m;)
    {
        resq.push_back(q[i]);
        j=i+1;
        while(j<m && q[j].first==q[i].first)
        {
            resq[resq.size()-1].second=max(resq[resq.size()-1].second,q[j].second);
            j++;
        }
        i=j;
    }

    for(i=0;i<resq.size();i++)
    {
        if(fq.size()==0||fq[fq.size()-1].second>resq[i].second)
            fq.push_back(resq[i]);
        else
        {
            while(fq.size()!=0 && fq[fq.size()-1].second <=resq[i].second)
            {
                fq.pop_back();
            }
            fq.push_back(resq[i]);
        }
    }

    for(i=0;i<fq.size();i++)
        fq[i].second--;

    int st=0,ed=fq[0].second;
    int eda=ed;

    for(i=ed+1;i<n;i++)
        ans[i]=arr[i];

    sort(arr,arr+ed+1);

    for(i=0;i<fq.size()-1;i++)
    {
        if(fq[i].first==1)
        {
            for(j=0;j<fq[i].second - fq[i+1].second ;j++)
            {
                ans[eda]=arr[ed];
                ed--;
                eda--;
            }
        }
        else
        {
             for(j=0;j<fq[i].second - fq[i+1].second ;j++)
            {
                ans[eda]=arr[st];
                st++;
                eda--;
            }
        }
    }

    if(fq[fq.size()-1].first==1)
    {
        for(j=0;j<fq[fq.size()-1].second+1;j++)
            {
                ans[eda]=arr[ed];
                ed--;
                eda--;
            }
    }
    else
    {
         for(j=0;j<fq[fq.size()-1].second+1;j++)
            {
                ans[eda]=arr[st];
                st++;
                eda--;
            }
    }

    for(i=0;i<n;i++)
        printf("%d ",ans[i]);


    return 0;
}


















