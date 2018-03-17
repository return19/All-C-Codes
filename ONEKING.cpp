#include<bits/stdc++.h>
using namespace std;

long long arr[100200][2];

void quicksort(long long first,long long last){
    long long pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i][0]<=arr[pivot][0]&&i<last)
                 i++;
             while(arr[j][0]>arr[pivot][0])
                 j--;
             if(i<j){
                 temp=arr[i][0];
                  arr[i][0]=arr[j][0];
                  arr[j][0]=temp;

                  temp=arr[i][1];
                  arr[i][1]=arr[j][1];
                  arr[j][1]=temp;
             }
         }

         temp=arr[pivot][0];
         arr[pivot][0]=arr[j][0];
         arr[j][0]=temp;

         temp=arr[pivot][1];
         arr[pivot][1]=arr[j][1];
         arr[j][1]=temp;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}

int main()
{
    long long test,n,min1,count1,i,j;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        count1=1;

        for(j=0;j<n;j++)
        {
            scanf("%lld%lld",&arr[j][0],&arr[j][1]);
        }
        quicksort(0,n-1);
        min1=arr[0][1];
        for(j=1;j<n;j++)
        {
            if(arr[j][0]<=min1)
            {
                if(min1>arr[j][1])
                {
                    min1=arr[j][1];
                }
            }
            else
            {
                count1++;
                min1=arr[j][1];
            }
        }
        printf("%lld\n",count1);
    }
    return 0;
}

