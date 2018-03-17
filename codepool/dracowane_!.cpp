#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[110][110];

long long row_sum[110];
long long col_sum[110];


vector< pair<long long,long long> > ans;

int main()
{
    long long i,j,k;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%lld",&arr[i][j]);

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

    for(i=0;i<100;i++)
    {
        long long max_xor_diff=LLONG_MIN;
        long long mxj,mxk;
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                long long temp =(arr[j][k] - ((row_sum[j]/n)^(col_sum[k]/m) ));
                if(max_xor_diff < temp )
                {
                    max_xor_diff=temp;
                    mxj=j;
                    mxk=k;
                }
            }
        }

        ans.push_back(make_pair(mxj,mxk));

        //cout<<mxj<<" "<<mxk<<endl;
        //if(max_xor_diff>=0){
            long long tmp=(row_sum[mxj]/n)^(col_sum[mxk]/m);
            row_sum[mxj] += tmp - arr[mxj][mxk];
            col_sum[mxk] += tmp - arr[mxj][mxk];
            arr[mxj][mxk] = tmp;
        //}
    }
   /* cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

    printf("%lld\n",ans.size());

    for(i=0;i<ans.size();i++)
        printf("%lld %lld\n",ans[i].first,ans[i].second);

    return 0;
}



















