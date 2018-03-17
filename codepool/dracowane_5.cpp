#include<bits/stdc++.h>
using namespace std;
int minVal(int x, int y) { return (x < y)? x: y; }

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

int arr[1010][1010];
int fake[10100];
int n,m;

vector< pair<int,int> > res;
vector< pair< int,pair<int,int> > > xr;
int visx[1010],visy[1010];

int rsum[1010],csum[1010];

set< pair< int,pair<int,int> > > s;
set< pair< int,pair<int,int> > >::iterator it;;
int xval[1010][1010];

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

   // sort(xr.begin(),xr.end());

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

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int i,j,k;
    int x,y;
    int temp;
    int rows=0,cols=0;

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

     int *st = constructST(fake, n*m + 10);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            rows=rsum[x];
            cols=csum[y];

            rows /= n;
            cols /= m;

            int temp = (rows ^ cols);

            one.increase(i*m + j,i*m + j,arr[i][j]);
            cout<<"in"<<endl;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<(one.query(i*m+j,i*m+j)).second<<" ";
        cout<<endl;
    }

    for(k=0;k<100;k++){
        int idx=(one.query(0,n*m-1)).second;
        int x=idx/m;
        int y=idx%m;

        cout<<x<<" "<<y<<endl;
        check(x,y);
        for(i=0;i<n;i++){
            rows=rsum[i];
                cols=csum[y];

                rows /= n;
                cols /= m;

                int temp = (rows ^ cols);
            one.increase(i*m + y,i*m+y,temp-arr[i][y]);
        }
        for(i=0;i<m;i++)
        {
             rows=rsum[x];
                cols=csum[i];

                rows /= n;
                cols /= m;

                int temp = (rows ^ cols);
            one.increase(x*m + i,x*m +i,temp-arr[i][j]);
        }
    }

   /* for(i=0;i<n*m;i++)
        setdo();*/

  /*  for(i=0;i<6000;i++)
        fillup();*/

   /* srand(time(NULL));

    for(i=0;i<4000000;i++)
    {
        x=rand()%n;
        y=rand()%m;

        check(x,y);
    }*/

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














