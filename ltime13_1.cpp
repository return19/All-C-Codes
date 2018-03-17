#include<bits/stdc++.h>
using namespace std;

int x[100010];

void quicksort(int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}


int main()
{
    int test,i,j,k,n;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            scanf("%d",&x[j]);
        }
        quicksort(0,n-1);
        printf("%d\n",x[0]+x[1]);
    }

    return 0;
}















