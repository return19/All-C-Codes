#include<bits/stdc++.h>
using namespace std;

int n,q;
int arr[30100];
int bit[30101];

void update(int index,int val)
{
    index++;

    if(bit[index])
        return;

    while(index<=n)
    {
        bit[index]+=val;
        index+=index&(-index);
    }
}

int query(int index)
{
    index++;

    int sum=0;

    while(index>0)
    {
        sum=sum+bit[index];

        index-=index&(-index);
    }

    return sum;
}

int main()
{
    int i,j,k;
    int q;
    int x,y;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        update(,1)
    }

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);

        x--;
        y--;

        printf("%d\n",query(y)-query(x));
    }

    return 0;
}
