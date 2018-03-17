#include<bits/stdc++.h>
using namespace std;

int n,s;

map<int,int> buy;
map<int,int> sell;

map<int,int>::iterator it;
map<int,int>::reverse_iterator rit;

vector< pair<int,int> > ans;

int main()
{
    int i,j,k;
    char str[5];
    int val,q;
    int bc=0,sc=0;

    scanf("%d%d",&n,&s);

    for(i=0;i<n;i++)
    {
        scanf("%s",str);

        scanf("%d%d",&val,&q);

        if(str[0]=='B')
        {
            buy[val]+=q;
            bc++;
        }
        else
        {
            sell[val]+=q;
            sc++;
        }
    }
    int temp=s;
    for(it=sell.begin();sc>0 && temp>0 && it!=sell.end();it++,sc--,temp--)
    {
       // printf("S %d %d\n",it->first,it->second);
        ans.push_back(make_pair(it->first,it->second));
    }

    for(i=ans.size()-1;i>=0;i--)
        printf("S %d %d\n",ans[i].first,ans[i].second);

    temp=s;

    for(rit=buy.rbegin();bc>0&& temp>0 && rit!=buy.rend();rit++,bc--,temp--)
    {
        printf("B %d %d\n",rit->first,rit->second);
    }

    return 0;
}















