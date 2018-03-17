#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

int arr[6][11];
int c[6];

char ans[5][11];

string con[6];
string act[6];

void gen_test()
{
    int i,j,k;


    con[0]="C1 : x < y + z ?";
    con[1]="C2 : y < x + z ?";
    con[2]="C3 : z < x + y ?";
    con[3]="C4 : x = y ?";
    con[4]="C5 : x = z ?";
    con[5]="C6 : y = z ?";

    act[0]="Not a triangle";
    act[1]="Scalene";
    act[2]="Isosceles";
    act[3]="Equilateral";
    act[4]="Impossible";

    for(i=0;i<6;i++)
    {
        con[i].resize(20);
        act[i].resize(20);
    }

    for(i=0;i<6;i++)
        for(j=0;j<11;j++)
            arr[i][j]=-1;

    for(i=0;i<=2;i++)
    {
        if(i==0)
        {
            arr[i][0]=0;
            for(j=1;j<11;j++)   arr[i][j]=1;
        }else if(i==1)
        {
            arr[i][0]=-1;
            arr[i][1]=0;
            for(j=2;j<11;j++)   arr[i][j]=1;
        }else if(i==2)
        {
            arr[i][0]=-1;
            arr[i][1]=0;
            arr[i][2]=0;
            for(j=3;j<11;j++)   arr[i][j]=1;
        }
    }
    int cnt=3;
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=1;k++)
            {
                arr[3][cnt]=i;
                arr[4][cnt]=j;
                arr[5][cnt]=k;
                cnt++;
            }
        }
    }

    for(i=0;i<6;i++)
    {
        cout<<con[i]<<"\t";
        for(j=0;j<11;j++)
        {
            if(arr[i][j]==0)
                cout<<"F"<<"\t";
            else if(arr[i][j]==1)
                cout<<"T"<<"\t";
            else
                cout<<"-"<<"\t";

        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    system("mode 140,40");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = {0, 0, 140, 40};   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window



    int i,j,k;

    gen_test();

    for(j=0;j<11;j++)
    {
        for(i=0;i<6;i++)
            c[i]=arr[i][j];

        if(c[0]==0 || c[1]==0 || c[2]==0)
        {
            ans[0][j]='X';
        }
        else
        {
            int cnt=0;
            if(c[3]==1)
                cnt++;
            if(c[4]==1)
                cnt++;
            if(c[5]==1)
                cnt++;

            if(cnt==0)
                ans[1][j]='X';
            else if(cnt==1)
                ans[2][j]='X';
            else if(cnt==2)
                ans[4][j]='X';
            else
                ans[3][j]='X';
        }
    }

    for(i=0;i<5;i++)
    {
        cout<<act[i]<<"\t";
        for(j=0;j<11;j++)
        {
            if(ans[i][j]=='X')
                cout<<"X"<<"\t";
            else
                cout<<" "<<"\t";
        }
        cout<<endl;
    }

    return 0;
}












