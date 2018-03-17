#include<bits/stdc++.h>
using namespace std;

long long cost[200][200];

int main()
{
    int i,j;

    memset(cost,10LL,sizeof(int)*10*10);

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
