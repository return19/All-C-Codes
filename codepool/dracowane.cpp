#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[110][110];

int row_sum[110];
int col_sum[110];


vector< pair<int,int> > ans;

void update_sums(int x,int y)
{
    int tmp=row_sum[x]^col_sum[y];
    row_sum[x] += tmp - arr[x][y];
    col_sum[x] += tmp - arr[x][y];
    arr[x][y] = tmp;
}

void print_array()
{
    int i,j;
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

}

void init()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<m;j++)
            sum+=arr[i][j];
        row_sum[i]=sum;
    }

    for(j=0;j<m;j++)
    {
        int sum=0;
        for(i=0;i<n;i++)
            sum+=arr[i][j];
        col_sum[j]=sum;
    }
}

void solve()

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);

    solve();

    print_array();

    printf("%d\n",ans.size());

    for(i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);

    return 0;
}


















