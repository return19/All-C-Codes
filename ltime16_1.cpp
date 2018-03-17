#include<bits/stdc++.h>
using namespace std;

long long arr[100010];

void quicksort(long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i]<=arr[pivot]&&i<last)
                 i++;
             while(arr[j]>arr[pivot])
                 j--;
             if(i<j){
                 temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
             }
         }

         temp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=temp;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}

int main()
{
    long long test,i,j,k,n;
    long long sum=0;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        quicksort(0,n-1);
        /*for(j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<endl;*/
        sum=0;
        for(j=n-1;j>=0;j--)
        {
            sum=sum+arr[j];
            j--;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
