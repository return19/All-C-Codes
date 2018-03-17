#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[110][110];

long long row_sum[110];
long long col_sum[110];


vector< pair<long long,long long> > ans;

void update_sums(long long x,long long y)
{
    ans.push_back(make_pair(x,y));
    long long tmp= ((row_sum[x]/n)^(col_sum[y]/m));
    row_sum[x] += tmp - arr[x][y];
    col_sum[x] += tmp - arr[x][y];
    arr[x][y] = tmp;
}

void print_array()
{
    long long i,j;
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
    long long i,j;
    for(i=0;i<n;i++)
    {
        long long sum=0;
        for(j=0;j<m;j++)
            sum+=arr[i][j];
        row_sum[i]=sum;
    }

    for(j=0;j<m;j++)
    {
        long long sum=0;
        for(i=0;i<n;i++)
            sum+=arr[i][j];
        col_sum[j]=sum;
    }
}

int main()
{
    long long i,j,k;
    long long x,y;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%lld",&arr[i][j]);

    init();

   /* for(i=0;i<m;i++)
    {
        x=0;    y=i;
        while(y>=0 && x<n)
        {
            update_sums(x,y);
            x++;    y--;
        }
    }
    for(j=0;j<m;j++)
    {
        x=j;    y=m-1;
        while(y>=0 && x<n)
        {
            update_sums(x,y);
            x++;
            y--;
        }
    }*/

    srand(time(NULL));

    for(i=0;i<1000;i++)
    {
        x=rand()%n;
        y=rand()%m;
        update_sums(x,y);
    }

    printf("%d\n",ans.size());

    for(i=0;i<ans.size();i++)
        printf("%lld %lld\n",ans[i].first,ans[i].second);

    //print_array();

    return 0;
}



















