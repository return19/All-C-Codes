#include<bits/stdc++.h>
using namespace std;

long long arr[110000]={0};
long long count_arr[110000]={0};
long long n;

long long FindMaxSum(long long arr[], long long n)
{
  long long incl = arr[0];
  long long excl = 0;
  long long excl_new;
  long long i;

  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;

     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }

   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}


int main()
{
    long long i,j,k;
    long long temp,A=-1;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&temp);

        if(count_arr[temp]==0)
        {
            arr[++A]=temp;
        }

        count_arr[temp]++;
    }

    sort(arr,arr+A+1);

    for(i=0;i<=A;i++)
    {
        count_arr[arr[i]]=arr[i]*count_arr[arr[i]];
    }

    /*for(i=0;i<=15;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    printf("%lld\n",FindMaxSum(count_arr,100005));



    return 0;
}

