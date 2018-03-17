
#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> memo;
map<int,int> pos;
int arr[101000];
int ans[101000];

int main()
{
    int i,j,k;
    int x;

      memo.clear();
    pos.clear();

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        pos[x]=i+1;
        memo[x]++;
    }

    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }

    int f=0;

    for(i=0;i<m;i++)
    {
        //cout<<"memo "<<arr[i]<<" "<<memo[arr[i]]<<endl;
        if(memo[arr[i]]==0)
        {
            f=2;
            break;
        }

        if(memo[arr[i]]>1)
        {
           f=1;
        }
        ans[i]=pos[arr[i]];

    }

    if(f==1)
    {
        printf("Ambiguity\n");
        return 0;
    }
    else if(f==2)
    {
        printf("Impossible\n");
        return 0;
    }

    printf("Possible\n");

    for(i=0;i<m;i++)
        printf("%d ",ans[i]);

    return 0;
}



