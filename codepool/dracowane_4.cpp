#include<bits/stdc++.h>
using namespace std;

int arr[1010][1010];
int n,m;

vector< pair<int,int> > res;

void check(int x,int y)
{
    int i,j,k;
    int rows=0,cols=0;

        for(j=0;j<m;j++)
            rows += arr[x][j];
        for(j=0;j<n;j++)
            cols += arr[j][y];

        rows /= n;
        cols /= m;

        int temp = (rows ^ cols);

        if(arr[x][y]>temp){
            arr[x][y]=temp;
            res.push_back(make_pair(x,y));
        }
}

void spiralPrint(int m, int n)
{
    int i, k = 0, l = 0;

    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
           // printf("%d ", arr[k][i]);
            check(k,i);
        }
        k++;

        for (i = k; i < m; ++i)
        {
          //  printf("%d ", arr[i][n-1]);
            check(i,n-1);
        }
        n--;

        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                //printf("%d ", arr[m-1][i]);
                check(m-1,i);
            }
            m--;
        }

        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                //printf("%d ", arr[i][l]);
                check(i,l);
            }
            l++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int i,j,k;
    int x,y;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(i=0;i<100;i++)
    spiralPrint(n,m);

    cout<<res.size()<<endl;

    for(i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }

    return 0;
}















