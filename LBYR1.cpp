#include<bits/stdc++.h>
using namespace std;

char arr[1110][1110];


int move_x[10];
int move_y[10];
int visited[1110][1110];
int best=0;
int c,r;
int start,last;

void dfs(int x,int y,int len)
{
   int i,j,k;

   int temp_x,temp_y;



   visited[x][y]=1;

   for(i=0;i<4;i++)
   {
       temp_x=x+move_x[i];
       temp_y=y+move_y[i];

       if(temp_x>=0&&temp_x<r&&temp_y>=0&&temp_y<c)
       {
           if(arr[temp_x][temp_y]=='.'&&!visited[temp_x][temp_y])
           {

                if(best<len+1){
                    best=len+1;

                    start=temp_x;
                    last=temp_y;
               }

               dfs(temp_x,temp_y,len+1);
           }
       }
   }



}

int main()
{
    int test,i,j,k;
    char sac;


    scanf("%d",&test);

    move_x[0]=0;
    move_x[1]=-1;
    move_x[2]=0;
    move_x[3]=1;

    move_y[0]=-1;
    move_y[1]=0;
    move_y[2]=1;
    move_y[3]=0;

    for(i=0;i<test;i++)
    {
        best=0;
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&c,&r);

        for(j=0;j<r;j++)
        {
            scanf("%s",arr[j]);
        }

        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                if(arr[j][k]=='.')
                {
                    dfs(j,k,0);
                    break;
                }
            }
        }

        memset(visited,0,sizeof(visited));
        dfs(start,last,0);


        printf("Maximum rope length is %d.\n",best);

    }

    return 0;
}
