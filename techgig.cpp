#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int arr[6010][6010];
int vis[6010][6010];

void dfs(int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return;

    if(arr[x][y]==0)
        return;

    if(vis[x][y])
        return;
    //cout<<"here"<<x<<" "<<y<<endl;

    vis[x][y]=1;

    dfs(x-1,y,n,m);
    dfs(x+1,y,n,m);
    dfs(x,y-1,n,m);
    dfs(x,y+1,n,m);
}

int pixelValue(int input1[],int input2[])
{
	//Write code here

    int i,j,k;

    int tot=0;
    int val;

    int n,m;

    n=input1[0];
    m=input1[1];

    int c=n*m;



    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            vis[i][j]=0;
            arr[i][j]=0;
        }

     i=0;
    j=0;

    for(k=0;;k+=2)
    {
        if(c==0)
            break;

        tot=input2[k];
        val=input2[k+1];

        //cout<<tot<<" "<<val<<" "<<c-tot<<endl;

        c -= tot;

        if(tot==0)
            continue;

        while(tot!=0)
        {
            arr[i][j]=val;

            j++;

            if(j==m)
            {
                i++;
                j=0;
            }

            tot--;
        }
    }

    int ans=0;



    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //printf("%d ",arr[i][j]);

            if(arr[i][j]==1 && vis[i][j]==0)
            {
                ans++;
                dfs(i,j,n,m);
            }
        }

        //printf("\n");
    }

   // printf("%d\n",ans);

    return ans;

}

int input1[]={4,5};
int input2[]={4,1,5,0,6,1,2,0,2,1,1,0};

int main()
{
    cout<<pixelValue(input1,input2);

    return 0;
}

