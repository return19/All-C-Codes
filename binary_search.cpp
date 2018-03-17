#include<bits/stdc++.h>
using namespace std;

int arr[10100];

int main()
{
    int n;
    int i,j,k;

    cin>>n;

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<100;i++)
    {
        scanf("%d",&j);

        cout<<lower_bound(arr,arr+n,j)-arr<<endl;
        cout<<upper_bound(arr,arr+n,j)-arr<<endl;
    }

    return 0;
}
