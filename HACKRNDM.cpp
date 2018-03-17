#include<bits/stdc++.h>
using namespace std;

map<int,int> memo;
map<int,int>::iterator it;

vector<int> v;
int main()
{
    int i,j,n,k;
    int temp;
    int count1=0;
    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        memo[temp]=1;
        v.push_back(temp);
    }
/*
    for(it=memo.begin();it!=memo.end();it++)
    {
        if(memo.find(it->first+k))
                count1++;

       // cout<<"hi"<<endl;
    }
*/

    for(i=0;i<n;i++)
    {
        if(memo[v[i]+k])
            count1++;
    }


    printf("%d\n",count1);

    return 0;
}
