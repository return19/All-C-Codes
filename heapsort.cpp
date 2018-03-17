#include<bits/stdc++.h>
using namespace std;
int arr[100100];
int n;

void percolateDown(int x){
    int l = 2*x + 1;
    int r = 2*x + 2;

    int mx = arr[x];
    int mxIdx = x;

    if(l<n && arr[l]>mx)
    {
        mx = arr[l];
        mxIdx = l;
    }

    if(r<n && arr[r]>mx){
        mx = arr[r];
        mxIdx = r;
    }

    if(mx != arr[x]){
        swap(arr[x],arr[mxIdx]);
        percolateDown(mxIdx);
    }
}

void heapsort(){

    int i,j,k;

    for(i=n/2 + 1;i>=0;i--)
        percolateDown(i);
    int N = n;
    for(i=0;i<N-1;i++){
        swap(arr[0],arr[N-i-1]);
        n--;
        percolateDown(0);
    }
}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    int N = n;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    heapsort();

    for(i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
