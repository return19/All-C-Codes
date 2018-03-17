#include<bits/stdc++.h>
using namespace std;

int n,m;
int x0,y0;
char str[101000];
int s[101000];
int arr[510][510];

int main()
{
    int i,j,k;
    scanf("%d%d%d%d",&n,&m,&x0,&y0);
    scanf("%s",str);
    int l=strlen(str);
    arr[x0-1][y0-1]=1;

    x0--;
    y0--;
    s[0]=1;
    int ans=0;

    for(i=0;i<l;i++)
    {
        if(str[i]=='U')
        {
            x0--;
            if(x0<0)
                x0++;
        }else if(str[i]=='D')
        {
            x0++;
            if(x0>=n)
                x0--;
        }else if(str[i]=='L')
        {
            y0--;
            if(y0<0)
                y0++;
        }else if(str[i]=='R')
        {
            y0++;
            if(y0>=m)
                y0--;
        }
       // cout<<x0<<" "<<y0<<endl;
        if(arr[x0][y0]==1)
        {
            s[i+1]=0;
        }
        else
            s[i+1]=1;
        arr[x0][y0]=1;
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(arr[i][j]==0)
                ans++;

    for(i=0;i<l;i++)
        printf("%d ",s[i]);
    printf("%d ",ans+s[l]);

    return 0;
}
