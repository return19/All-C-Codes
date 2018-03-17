#include<stdlib.h>
#include<stdio.h>
using namespace std;

long long arr1[1000010];
long long arr2[1000010];

long long  _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right);

long long mergeSort(long long arr[], long long array_size)
{
    long long *temp = (long long *)malloc(sizeof(long long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

long long _mergeSort(long long arr[], long long temp[], long long left, long long right)
{
  long long mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;

    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
  long long i, j, k;
  long long inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];


      inv_count = inv_count + (mid - i);
    }
  }


  while (i <= mid - 1)
    temp[k++] = arr[i++];


  while (j <= right)
    temp[k++] = arr[j++];


  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}




int main()
{
    long long n,q,i,j,k;

    long long l,r;
    scanf("%lld%lld",&n,&q);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr1[i]);
    }

    for(i=0;i<q;i++)
    {
        scanf("%lld%lld",&l,&r);

        l--;
        r--;
        for(j=l,k=0;j<=r;j++,k++)
        {
            arr2[k]=arr1[j];
        }

        printf("%lld\n",mergeSort(arr2,r-l+1));
    }

    return 0;
}




