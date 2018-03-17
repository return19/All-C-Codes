#include<bits/stdc++.h>
using namespace std;

int arr[15];

int main()
{
    int n;

    int i,j,k;
    int mx=INT_MIN;

    scanf("%d",&n);

    k=0;

    while(n!=0)
    {
        arr[k]=n%10;

        mx=max(mx,arr[k]);

        n/=10;

        k++;
    }

    for(i=0,j=k-1;i<j;i++,j--)
    {
        swap(arr[i],arr[j]);
    }

    printf("%d\n",mx);

    for(i=0;i<mx;i++)
    {

        j=0;

        while(arr[j]==0)
            j++;

        for(;j<k;j++){

            if(arr[j]>0){
                printf("1");
                arr[j]--;
            }
            else
                printf("0");
        }

        printf(" ");

    }

    return 0;
}
