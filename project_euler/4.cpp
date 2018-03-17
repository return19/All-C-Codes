#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int n;

int arr[10];

int palin_check(int x)
{
    int i,j,k;

    k=0;

    while(x!=0)
    {
        arr[k]=x%10;
        k++;
        x /= 10;
    }


    for(i=0,j=k-1 ; i<j ; i++,j--)
        if(arr[i]!=arr[j])
            return 0;

    return 1;
}

void pre()
{
    int i,j,k;

    for(i=100;i<=999;i++)
        for(j=i+1;j<=999;j++)
            if(palin_check(i*j))
                v.push_back(i*j);

    sort(v.begin(),v.end());

}

int main()
{
    int test,i,j,k,t;

    scanf("%d",&test);

    pre();

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        int lb=lower_bound(v.begin(),v.end(),n)-v.begin();

        printf("%d\n",v[lb-1]);
    }

    return 0;
}
