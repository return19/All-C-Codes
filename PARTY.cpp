#include<bits/stdc++.h>
using namespace std;

int val[10010];
int wt[10010];
int table[10010][10010];
int W,n,money=0;

void quicksort(int x[],int y[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
                  temp=y[i];
                  y[i]=y[j];
                  y[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;

         temp=y[pivot];
         y[pivot]=y[j];
         y[j]=temp;
         quicksort(x,y,first,j-1);
         quicksort(x,y,j+1,last);

    }
}

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;

}

int create()
{
    int i,j;

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
            if(i==0||j==0)
                {table[i][j]=0;}
            else if(wt[i-1]<=j)
            {
                table[i][j]=max2(table[i-1][j],val[i-1]+table[i-1][j-wt[i-1]]);
            }
            else
               {
                   table[i][j]=table[i-1][j];
               }
        }
    }
    return table[n][W];
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
        int last=0;
        quicksort(val,wt,0,n-1);
        for(i=0;i<n;i++)
        {
            if(val[i]!=val[i+1])
            {
                quicksort(wt,val,last,i);
                last=i+1;
            }
        }
        //for(i=0;i<n;i++)
          //  cout<<wt[i]<<" "<<val[i]<<endl;
        fun=create();
        y=W;
        for(i=n;i>0;i--)
        {
            if(table[i][y]!=table[i-1][y]){
                money=money+wt[i-1];
                y=y-wt[i-1];
            }
        }

        cout<<money<<" "<<fun<<endl;
        cin>>W;
        cin>>n;
    }

}

















