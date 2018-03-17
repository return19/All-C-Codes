#include<bits/stdc++.h>
using namespace std;

map<string,int> memo;

map<string,int>::iterator it;

string str;


int main()
{
    int test,n,i,j,k;
    char a;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memo.clear();
        scanf("%d",&n);
        a=getchar();
        for(j=0;j<n;j++)
        {

            getline(cin,str);
           // cout<<str<<endl;
            memo[str]++;
        }

        for(it=memo.begin();it!=memo.end();it++)
        {
            //printf("%s %d\n",it->first,it->second);
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }

    return 0;
}
