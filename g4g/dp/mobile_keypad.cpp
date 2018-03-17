#include<bits/stdc++.h>
using namespace std;

int arr[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

int n;

int find_num(int x,int y,int n)
{
    if(n==1)
        return 1;

    int l=0,r=0,u=0,d=0;

    if(y-1>=0&&arr[x][y-1]!=-1)
        l=find_num(x,y-1,n-1);
    if(y+1<=2&&arr[x][y+1]!=-1)
        r=find_num(x,y+1,n-1);
    if(x-1>=0)
        u=find_num(x-1,y,n-1);
    if(x+1<=3&&arr[x+1][y]!=-1)
        d=find_num(x+1,y,n-1);

    return (l+r+u+d+find_num(x,y,n-1));
}

int main()
{
    int i,j,k;
    int sum=0;

    scanf("%d",&n);

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==-1)
                continue;

            sum+=find_num(i,j,n);
        }
    }

    printf("%d\n",sum);

    return 0;
}
