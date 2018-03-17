#include<bits/stdc++.h>
using namespace std;

int arr[1010][1010];
int n,m;

vector< pair<int,int> > res;
vector< pair< int,pair<int,int> > > xr;
int visx[1010],visy[1010];

int rsum[1010],csum[1010];

void check(int x,int y)
{
    int i,j,k;
    int rows=0,cols=0;

     rows=rsum[x];
     cols=csum[y];

        rows /= n;
        cols /= m;

        int temp = (rows ^ cols);

        if(arr[x][y]>temp){
            rsum[x]=rsum[x] - arr[x][y] + temp;
            csum[y]=csum[y] - arr[x][y] + temp;
            arr[x][y]=temp;
            res.push_back(make_pair(x,y));
        }
}

void fillup()
{
    int i,j,k;
    int temp;
    int rows=0,cols=0;
    xr.resize(0);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            visx[i]=0;
            visy[j]=0;
            rows=rsum[i]/n;
            cols=csum[j]/m;
            temp = (rows ^ cols);

            if(temp<arr[i][j])
            {
                xr.push_back(make_pair(temp-arr[i][j],make_pair(i,j)));
            }
        }
    }

    int x,y;
    for(i=0;i<xr.size();i++)
    {
        x=xr[i].second.first;
        y=xr[i].second.second;
        if(visx[x]==0 && visy[y]==0)
        {
            visx[x]=1;
            visy[y]=1;
            check(x,y);
        }
    }
}

void diagfill()
{
    int i,j,k;
    int mx,idx,idy;
    int temp;
    int rows=0,cols=0;
    int x,y;
    int cur=0;
    int dir;

    mx=0;
    for(i=0;i<m;i++)
    {
        x=0;    y=i;
        cur=0;

        while(x<n && y>=0)
        {
            rows=rsum[x]/n;
            cols=csum[y]/m;
            temp = (rows ^ cols);

            if(temp<arr[x][y])
            {
                cur += (arr[x][y]-temp);
            }

              x++;    y--;
        }
        if(mx<cur)
        {
            mx=cur;
            idx=0;
            idy=i;
            dir=1;
        }
    }


    for(i=0;i<n;i++)
    {
        x=i;    y=m-1;
        cur=0;

        while(x<n && y>=0)
        {
            rows=rsum[x]/n;
            cols=csum[y]/m;
            temp = (rows ^ cols);
            if(temp<arr[x][y])
            {
                cur+= (arr[x][y]-temp);
            }
            x++;    y--;
        }

        if(mx<cur)
        {
            mx=cur;
            idx=i;
            idy=m-1;
            dir=1;
        }
    }

    for(i=0;i<m;i++)
    {
        x=0;    y=i;
        cur=0;

        while(x<n && y<m)
        {
            rows=rsum[x]/n;
            cols=csum[y]/m;
            temp = (rows ^ cols);

            if(temp<arr[x][y])
            {
                cur += (arr[x][y]-temp);
            }

              x++;    y++;
        }
        if(mx<cur)
        {
            mx=cur;
            idx=0;
            idy=i;
            dir=2;
        }
    }

    for(i=0;i<n;i++)
    {
        x=i;    y=0;
        cur=0;

        while(x<n && y<m)
        {
            rows=rsum[x]/n;
            cols=csum[y]/m;
            temp = (rows ^ cols);
            if(temp<arr[x][y])
            {
                cur+= (arr[x][y]-temp);
            }
            x++;    y++;
        }

        if(mx<cur)
        {
            mx=cur;
            idx=i;
            idy=0;
            dir=2;
        }
    }

    if(mx==0)
        return;

    if(dir==2)
    {
        while(idx<n && idy<m)
        {
            check(idx,idy);
            idx++;  idy++;
        }
    }
    else
    {
         while(idx<n && idy>=0)
        {
            check(idx,idy);
            idx++;  idy--;
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

    for(i=0;i<n;i++)
    {
        int temp=0;
        for(j=0;j<m;j++)
        {
            temp += arr[i][j];
        }
        rsum[i]=temp;
    }

    for(i=0;i<m;i++)
    {
        int temp=0;
        for(j=0;j<n;j++)
        {
            temp += arr[j][i];
        }
        csum[i]=temp;
    }

    for(i=0;i<7000;i++)
        fillup();

    srand(time(NULL));

    for(i=0;i<2500000;i++)
    {
        x=rand()%n;
        y=rand()%m;

        check(x,y);
    }

    // for(i=0;i<100;i++)
      //  diagfill();

    cout<<res.size()<<endl;

    for(i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }

   /* for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

    return 0;
}














