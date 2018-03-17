#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int visited[101000];

int n;

void dfs(int i)
{
    visited[i]=1;
    if(!visited[arr[i]])
        dfs(arr[i]);
}

int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);

            visited[j]=0;
        }

        int c=0;

        for(j=1;j<=n;j++)
        {
            if(visited[j]==0)
            {
                c++;
                dfs(j);
            }
        }

        printf("%d\n",c-1);


    }

    return 0;
}
