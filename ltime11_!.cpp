#include<bits/stdc++.h>
using namespace std;

int arr[10010][10010];
int movex[]={1,1,-1,-1,2,2,-2,-2};
int movey[]={2,-2,2,-2,1,-1,1,-1};
/*map<int,int> row;
map<int,int> col;
map<int,int> d1;
map<int,int> d2;*/
 int row[10010],col[10010],d1[10010],d2[10010],d3[10010];
int main()
{
    int test,i,j,k,l,n,m,x,y,p,q;
    int count1,tempx,tempy,count2;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        /*row.clear();
        col.clear();
        d1.clear();
        d2.clear();*/
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        memset(d3,0,sizeof(d3));
        memset(arr,0,sizeof(arr));
        count1=0;
        scanf("%d%d",&n,&m);

        for(j=0;j<m;j++)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            arr[x][y]=5;
             row[x]=-1;
            col[y]=-1;
            d1[x+y]=-1;
            if(x-y>=0)
                d2[x-y]=-1;
            else
            {
                d3[y-x]=-1;
            }

            /*for(k=0;k<n;k++)
                if(arr[x][k]!=5)
                    arr[x][k]=-1;
            for(k=0;k<n;k++)
                if(arr[k][y]!=5)
                    arr[k][y]=-1;
            for(k=x,l=y;k<n&&l<n;k++,l++)
                if(arr[k][l]!=5)
                    arr[k][l]=-1;

            for(k=x,l=y;k>=0&&l>=0;k--,l--)
                if(arr[k][l]!=5)
                    arr[k][l]=-1;
            for(k=x,l=y;k>=0&&l<n;k--,l++)
                if(arr[k][l]!=5)
                    arr[k][l]=-1;
            for(k=x,l=y;k<n&&l>=0;k++,l--)
                if(arr[k][l]!=5)
                    arr[k][l]=-1;*/

        }

        for(k=0;k<n;k++)
            {
                for(l=0;l<n;l++)
                {
                    count2=0;
                    if(arr[k][l]!=5)
                    {
                        if(k-l<0)
                        {
                            if(d3[l-k]==-1)
                                continue;
                        }
                        if(row[k]==-1||col[l]==-1||d1[k+l]==-1||d2[k-l]==-1)
                            continue;
                        for(p=0;p<8;p++)
                        {
                            tempx=k+movex[p];
                            tempy=l+movey[p];
                            if(tempx>=0&&tempx<n&&tempy>=0&&tempy<n)
                            {
                                if(arr[tempx][tempy]==5)
                                    count2++;
                                if(count2>=2)
                                {
                                    count1++;
                                    break;
                                }
                            }
                        }
                    }
                    /*count2=0;
                    if(arr[k][l]==0)
                    {
                        for(p=0;p<8;p++)
                        {

                            tempx=k+movex[p];
                            tempy=l+movey[p];

                            if(tempx>=0&&tempx<n&&tempy>=0&&tempy<n)
                            {
                                if(arr[tempx][tempy]==5)
                                    count2++;
                                if(count2>=2)
                                {
                                    count1++;
                                    break;
                                }
                            }
                        }
                    }*/
                }
            }


        /*for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                cout<<arr[j][k]<<" ";
            cout<<endl;
        }*/
        printf("%d\n",count1);
    }
}
