#include<bits/stdc++.h>
using namespace std;

map< string,int > memo;
map<string,int>::iterator it;

string arr[110];

int main()
{
    int test,i,j,k;
    int t;
    int n,m;
    int x,y;

    string str;


    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
        {
            cin>>str;

            arr[i]=str;

            memo[str]=1;
        }

        for(i=0;i<m;i++)
        {
            scanf("%d",&x);

            for(j=0;j<x;j++)
            {
                cin>>str;

                if(memo[str]>=1)
                    memo[str]=2;
            }
        }

        for(i=0;i<n;i++)
        {
            if(memo[arr[i]]==2)
                printf("YES ");
            else
                printf("NO ");
        }
        printf("\n");

        memo.clear();

    }

    return 0;
}
