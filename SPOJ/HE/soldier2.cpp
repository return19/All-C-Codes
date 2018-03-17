#include<iostream>
using namespace std;
int arr[100010];
int main()
{
    int test,m,n,i,j,k,sol;

    cin>>test;

    for(i=0;i<test;i++)
    {
        cin>>n;
        cin>>m;
        for(k=0;k<n;k++)
                arr[k]=0;

        for(j=0;j<m;j++)
        {
            cin>>sol;


            for(k=sol-1;k>=0;k--)
            {
                if(arr[k]<(sol-k))
                {
                    arr[k]=sol-k;
                }
                else
                    break;
            }
            for(k=sol+1;k<n;k++)
            {
                if(arr[k]<(k-sol))
                {
                    arr[k]=k-sol;
                }
                else
                    break;
            }
        }
        for(k=0;k<n;k++)
            cout<<arr[k]<<" ";
        cout<<endl;
    }
    return 0;
}
