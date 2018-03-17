#include<bits/stdc++.h>
using namespace std;

int arr[110000];
//given sorted array
int main()
{
    int i,j,k;
    int n,n1;

    scanf("%d%d%d",&n,&k,&n1);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+n);

    int c1,c2;
    //optimized binary search

    c1=lower_bound(arr,arr+n,k)-arr;
    c2=upper_bound(arr,arr+n,k)-arr;

    c1--;

    //cout<<c1<<" "<<c2<<endl;


    //linear search
    /*for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            c1=i-1;
            c2=i+1;
            break;
        }
        else if(arr[i]>k)
        {
            c1=i-1;
            c2=i;
            break;
        }
    }*/

    for(i=0;i<n1;i++)
    {
        if(c1<0||c2>=n)
            break;

        if(abs(arr[c1]-k)<abs(arr[c2]-k))
        {
            cout<<arr[c1]<<" ";
            c1--;
        }
        else
        {
            cout<<arr[c2]<<" ";
            c2++;
        }
    }

    while(i<n1&&c1>=0)
    {
        cout<<arr[c1]<<" ";
        c1--;
        i++;
    }

    while(i<n1&&c2<n)
    {
        cout<<arr[c2]<<" ";
        i++;
        c2++;
    }

    return 0;
}
