#include<bits/stdc++.h>
using namespace std;

int n;
char arr[20][20];

char brr[20][20];
int vis[20];
int col[20],c=1;
vector<int> v[20],V=0;

void dfs(int x){
    int i,j;
    vis[x]=1;
    v[V].push_back(x);
    int ans=0;
    for(i=0;i<2*n;i++){
        if(i!=x && arr[x][i] == 'Y' && vis[i] == 0)
            dfs(i);
    }
}

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);

        for(i=0;i<2*n;i++)
            scanf("%s",arr[i]);

        for(i=0;i<2*n;i++){
            for(j=0;j<2*n;j++){
                brr[i][j]=arr[i][j];
            }
        }

        for(i=0;i<2*n;i++){
            for(j=0;j<2*n;j++){
                if(brr[i][j] == 'Y')
                    brr[j][i] = brr[i][j];
            }
        }

        for(i=0;i<2*n;i++)
            vis[i]=0;

        for(i=0;i<2*n;i++){
            if(!vis[i]){
                dfs(i);
                c++;
                V++
            }
        }


        int a[20];
        int ans=solve(0,a,0,0);

        printf("%d\n",ans);
    }

    return 0;
}
