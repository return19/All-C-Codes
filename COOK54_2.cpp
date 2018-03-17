#include<iostream>
using namespace std;
#include<stdio.h>
double arr[1010][1010],sum;
int n,m;
int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {

        scanf("%d%d",&n,&m);
        sum=n+m-1;
        printf("%f\n",sum);

        /*for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if((j==0&&k==0)||(j==n-1&&k==m-1))
                   {
                       arr[j][k]=1.00000000;
                   }
                 else if(j==0)
                 {
                     arr[j][k]=arr[j][k-1]/2;

                 }
                 else if(k==0)
                 {
                     arr[j][k]=arr[j-1][k]/2;
                 }
                 else if(j==n-1)
                 {
                     arr[j][k]=arr[j-1][k]/2+arr[j][k-1];
                 }
                 else if(k==m-1)
                 {
                     arr[j][k]=arr[j-1][k]+arr[j][k-1]/2;
                 }
                 else
                 {
                     arr[j][k]=arr[j-1][k]/2+arr[j][k-1]/2;
                 }
                 sum=sum+arr[j][k];
            }
        }*/

        /*for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                cout<<arr[j][k]<<"\t";
            }
            cout<<endl;
        }*/

    }
    return 0;
}
