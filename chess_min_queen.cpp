#include<bits/stdc++.h>
using namespace std;

int arr[9][9];

int number_of_patterns;

void mark(int x,int y)
{
    int i,j,k;

    for(i=1;i<=8;i++)
    {
        if(arr[x][i]!=1){
            arr[x][i]=2;
        }

        if(arr[i][y]!=1)
            arr[i][y]=2;
    }

    i=x;
    j=y;

    while(i>=1 && i<=8 && j>=1 && j<=8)
    {
        if(arr[i][j]!=1)
            arr[i][j]=2;

        i--;
        j--;
    }

    i=x;
    j=y;

    while(i>=1 && i<=8 && j>=1 && j<=8)
    {
        if(arr[i][j]!=1)
            arr[i][j]=2;

        i++;
        j--;
    }

i=x;
    j=y;

    while(i>=1 && i<=8 && j>=1 && j<=8)
    {
        if(arr[i][j]!=1)
            arr[i][j]=2;

        i--;
        j++;
    }

    i=x;
    j=y;

    while(i>=1 && i<=8 && j>=1 && j<=8)
    {
        if(arr[i][j]!=1)
            arr[i][j]=2;

        i++;
        j++;
    }
}

int solve(int row)
{
    int i,j,k;

    if(row==9)
    {
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)
            {
                if(arr[i][j]==1)
                    mark(i,j);
            }
        }

        int c=0;

        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)
            {
                if(arr[i][j]==1)
                {
                    c++;
                }
                else if(arr[i][j]==0)
                {
                    for(i=1;i<=8;i++)
                        for(j=1;j<=8;j++)
                            if(arr[i][j]==2)
                                arr[i][j]=0;
                    return 8;
                }
            }
        }

        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                if(arr[i][j]==2)
                    arr[i][j]=0;

        return c;
    }

    int ans=solve(row+1);

    for(i=1;i<=8;i++)
    {
        arr[row][i]=1;

        int t=solve(row+1);

        ans=min(ans,t);

        if(row==8 && t==5)
            number_of_patterns++;

        // uncomment this to generate patterns and
        //enter any random number to print next pattern

       /* if(t==5 && row==8)
        {
            for(int x=1;x<=8;x++)
            {
                for(int y=1;y<=8;y++)
                    cout<<arr[x][y]<<" ";
                cout<<endl;
            }

            int temp;

            cin>>temp;
        }*/

        arr[row][i]=0;
    }

    return ans;
}

int main()
{
    int test,i,j,k;

    int ans=solve(1);

    printf("%d %d\n",ans,number_of_patterns);

    return 0;
}
