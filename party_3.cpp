#include<bits/stdc++.h>
using namespace std;

int val[10010];
int wt[10010];
int table[10010][10010];
int fee[10010][10010];
int W,n,money=0;

int fm,fun_max;

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;

}

void create()
{
    int i,j;
    fm=999999;
    fun_max=-99999;

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
            if(i==0||j==0)
                {table[i][j]=0;}
            else if(wt[i-1]<=j)
            {
                table[i][j]=max2(table[i-1][j],val[i-1]+table[i-1][j-wt[i-1]]);

                if(table[i-1][j]>(val[i-1]+table[i-1][j-wt[i-1]]))
                {
                    fee[i][j]=fee[i-1][j];
                }
                else if(table[i-1][j]<(val[i-1]+table[i-1][j-wt[i-1]]))
                {
                    fee[i][j]=wt[i-1]+fee[i-1][j-wt[i-1]];
                }

                if(table[i-1][j]==(val[i-1]+table[i-1][j-wt[i-1]]))
                {
                    if(fee[i-1][j]<(wt[i-1]+fee[i-1][j-wt[i-1]]))
                    {
                        fee[i][j]=fee[i-1][j];
                    }
                    else
                    {
                        fee[i][j]=wt[i-1]+fee[i-1][j-wt[i-1]];
                    }
                }
            }
            else
               {
                   table[i][j]=table[i-1][j];
                   fee[i][j]=fee[i-1][j-1];
               }
            if(table[i][j]==fun_max)
            {
                if(fm>fee[i][j])
                {
                    fm=fee[i][j];
                }
            }
            else if(table[i][j]>fun_max)
            {
                fun_max=table[i][j];
                fm=fee[i][j];
            }
        }
    }
//    return table[n][W];
}

int main()
{
    int i,j,fun=0,y;
    cin>>W;
    cin>>n;
    while(W>0||n>0)
    {
        money=0;
        for(i=0;i<n;i++)
        {
            cin>>wt[i];
            cin>>val[i];
        }
        create();
        y=W;
        /*for(i=n;i>0;i--)
        {
            if(table[i][y]!=table[i-1][y]){
                money=money+wt[i-1];
                y=y-wt[i-1];
            }
        }*/

        cout<<fm<<" "<<fun_max<<endl;
        cin>>W;
        cin>>n;
    }

}

















