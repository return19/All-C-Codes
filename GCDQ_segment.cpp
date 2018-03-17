#include<bits/stdc++.h>
using namespace std;
int arr[10200];
void scanlong(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

 inline int gcd(int a,int b)
{

  int r, i,x;
  while(b!=0){
    x = a % b;
    a = b;
    b = x;
  }
  return a;

}


int middle(int s, int e) {  return s + (e -s)/2;  }


int sum_driver(int *segTree, int ss, int se, int qs, int qe, int index)
{

    if (qs <= ss && qe >= se)
        return segTree[index];


    if (se < qs || ss > qe)
        return 0;


    int mid = middle(ss, se);
    return gcd(sum_driver(segTree, ss, mid, qs, qe, 2*index+1),sum_driver(segTree, mid+1, se, qs, qe, 2*index+2));
}


int final_ans(int *segTree, int n, int qs, int qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return sum_driver(segTree, 0, n-1, qs, qe, 0);
}

int create_driver(int arr[], int ss, int se, int *segTree, int si)
{

    if (ss == se)
    {
        segTree[si] = arr[ss];
        return arr[ss];
    }


    int mid = middle(ss, se);
    segTree[si] =  gcd(create_driver(arr, ss, mid, segTree, si*2+1),create_driver(arr, mid+1, se, segTree, si*2+2));
    return segTree[si];
}


int *create_tree(int arr[], int n)
{

    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;




    int *segTree = new int[max_size];


    create_driver(arr, 0, n-1, segTree, 0);


    return segTree;
}


int main()
{

int test,i,j,q,s,e,x,y,z,n,ans;
int *segTree;
    //cin>>test;
    scanlong(test);

    for(i=0;i<test;i++)
    {
        //cin>>n;
        //cin>>q;
        scanlong(n);
        scanlong(q);


        for(j=0;j<n;j++)
        {
            //cin>>arr[j];
            scanlong(arr[j]);
        }
        segTree=create_tree(arr, n);
       // for(x=0;x<n;x++)
       // {
            //for(y=0;y<n;y++)
                //cout<<dp[x][y]<<" ";
           // cout<<endl;
        //}
        for(j=0;j<q;j++)
        {
            //cin>>s;
            //cin>>e;
            scanlong(s);
            scanlong(e);
           // cout<<dp[s-1][e-1]<<endl;
           s=s-1;

           if(s!=0)
           {
               if(e==n)
               {
                   ans=final_ans(segTree,n,0,s-1);
               }
               else
               {
                   ans=gcd(final_ans(segTree,n,0,s-1),final_ans(segTree,n,e,n-1));
               }
           }
           else
           {
               ans=final_ans(segTree,n,e,n-1);
           }
           printf("%d\n",ans);
        }
    }
    return 0;
}
