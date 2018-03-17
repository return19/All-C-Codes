#include<bits/stdc++.h>
using namespace std;


int arr[110000];

class cmp
{
public:
    cmp()
    {

    }

    bool operator()(int a,int b)
    {
        return a>b;
    }
};

priority_queue<int,vector<int>,cmp> pq;

int main()
{
    int i,j,k;
    int n;



    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    for(i=k;i<n;i++)
    {
        arr[i-k]=pq.top();
        pq.pop();

        pq.push(arr[i]);
    }

    for(i=n-k;i<n;i++)
    {
        arr[i]=pq.top();
        pq.pop();
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
