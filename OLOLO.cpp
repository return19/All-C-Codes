#include<bits/stdc++.h>
using namespace std;
map<int,int> memo;
map<int,int>::iterator it;


int main()
{
    int index,i,num;
    scanf("%d",&index);
    for(i=0;i<index;i++)
    {
        scanf("%d",&num);
        if(memo[num]==0)
        {
            memo[num]=1;
        }
        else
        {
            memo.erase(num);
        }
    }
    for(it=memo.begin();it!=memo.end();it++)
    {
        cout<<it->first<<endl;
    }
    return 0;
}
