#include<bits/stdc++.h>
using namespace std;

int MINNUM = -9999999;
int MAXNUM = 9999999;

char s[2][61];
int arr[2][61];

int dp[54][54][54][54][3];

int solve(int x,int y,int a,int b,int t){
    if(x>y  && a>b){
        return 0;
    }

   // cout<<x<<" "<<y<<" "<<t<<endl;

    if(dp[x][y][a][b][t]!=MINNUM)
        return dp[x][y][a][b][t];



    if(t==0){
        int u=MINNUM,d=MINNUM;
        if(x<=y){
            u = max(arr[0][x-1] + solve(x+1,y,a,b,1-t),
                    arr[0][y-1] + solve(x,y-1,a,b,1-t));
        }

        if(a<=b){

            d = max(arr[1][a-1] + solve(x,y,a+1,b,1-t),
                    arr[1][b-1] + solve(x,y,a,b-1,1-t));
        }

        return dp[x][y][a][b][t] = max(u,d);
    } else {
        int u=MAXNUM,d=MAXNUM;
        if(x<=y){
            u = min(-1*arr[0][x-1] + solve(x+1,y,a,b,1-t),
                    -1*arr[0][y-1] + solve(x,y-1,a,b,1-t));
        }

        if(a<=b){

            d = min(-1*arr[1][a-1] + solve(x,y,a+1,b,1-t),
                    -1*arr[1][b-1] + solve(x,y,a,b-1,1-t));
        }

        return dp[x][y][a][b][t] = min(u,d);
    }
}

int main()
{
    int i,j,k;
    scanf("%s",s[0]);
    scanf("%s",s[1]);

    for(i=0;i<2;i++){
        for(j=0;j<52;j++){
            if(s[i][j]=='A'){
                arr[i][j] = 1;
            } else if(s[i][j]=='T'){
                arr[i][j]=10;
            }  else if(s[i][j]=='J'){
                arr[i][j]=11;
            } else if(s[i][j]=='Q'){
                arr[i][j]=12;
            } else if(s[i][j]=='K'){
                arr[i][j]=13;
            } else {
                arr[i][j] = s[i][j] - '0';
            }
        }
    }

    for(i=0;i<54;i++)
        for(j=0;j<54;j++)
            for(k=0;k<54;k++)
                for(int b=0;b<54;b++)
                for(int x=0;x<2;x++)
                    dp[i][j][k][b][x]=MINNUM;

    /*for(i=0;i<2;i++)
    {
        for(j=0;j<52;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

    //cout<<"here"<<endl;
    int ans = solve(1,52,1,52,0);
    printf("%d\n",ans);
    return 0;
}

