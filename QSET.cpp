#include<bits/stdc++.h>
using namespace std;

long arr[100200];
long temp[10];
int main()
{
    long n,m,len,sum,i,j,last,count1=0;
    long type,x,y;
    scanf("%ld%ld",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%1ld",&arr[i]);
    }
    //
   // for(i=0;i<n;i++)
   //     cout<<arr[i]<<" ";
    for(i=0;i<m;i++)
    {
        scanf("%ld%ld%ld",&type,&x,&y);
        if(type==1)
        {
            arr[x-1]=y;
        }
        else if(type==2)
        {
            x--;
            y--;
            sum=0;
            count1=0;
            for(j=0;j<3;j++)
                temp[j]=0;
            temp[0]++;
            for(j=x;j<=y;j++)
            {
                sum=(sum+arr[j])%3;
                temp[sum]++;
            }
            for(j=0;j<3;j++)
            {
                count1=count1+(temp[j]*(temp[j]-1))/2;
            }
            printf("%ld\n",count1);
        }
    }
    return 0;
}







