#include<bits/stdc++.h>
#include <windows.h>

using namespace std;

vector<string> m;
vector<string> d;
vector<string> y;

vector< pair<string,pair< string,string> > > tests;
string ans[5][1010];

void gen_test()
{
    int i,j,k;
    m.push_back("M1");
    m.push_back("M2");
    m.push_back("M3");
    m.push_back("M4");

    d.push_back("D1");
    d.push_back("D2");
    d.push_back("D3");
    d.push_back("D4");
    d.push_back("D5");

    y.push_back("Y1");
    y.push_back("Y2");

    for(i=0;i<d.size();i++)
    {
        for(j=0;j<m.size();j++)
        {
            for(k=0;k<y.size();k++)
            {
                tests.push_back(make_pair(d[i],make_pair(m[j],y[k])));
            }
        }
    }
    cout<<"D : ";
    for(i=0;i<tests.size();i++)
    {
        cout<<tests[i].first<<"  ";
    }
    cout<<endl;
    cout<<"M : ";
    for(i=0;i<tests.size();i++)
    {
        cout<<tests[i].second.first<<"  ";
    }
    cout<<endl;
    cout<<"Y : ";
    for(i=0;i<tests.size();i++)
    {
        cout<<tests[i].second.second<<"  ";
    }
    cout<<endl;
}

int main()
{
    system("mode 163,40");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = {0, 0, 163, 40};   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window



    int i,j,k;

    gen_test();

    for(i=0;i<tests.size();i++)
    {
        string x,y,z;
        x=tests[i].first;
        y=tests[i].second.first;
        z=tests[i].second.second;

        if(y=="M1")
        {
            if(x!="D5")
            {
                ans[0][i]="X";
            }
            else
                ans[1][i]="X";
        }
        else if(y=="M2")
        {
            if(z=="Y1")
            {
                if(x=="D1" || x=="D2")
                    ans[0][i]="X";
                else
                    ans[1][i]="X";
            }
            else
            {
                if(x=="D1")
                {
                    ans[2][i]="X";
                }
                else
                    ans[1][i]="X";
            }
        }
        else if(y=="M3")
        {
            if(x!="D5")
                ans[0][i]="X";
            else
                ans[3][i]="X";
        }else
        {
            if(x=="D5")
                ans[2][i]="X";
            else if(x=="D4")
                ans[1][i]="X";
            else
                ans[0][i]="X";
        }
    }
    cout<<endl;
    for(i=0;i<4;i++)
    {
        cout<<"A"<<i+1<<": ";
        for(j=0;j<tests.size();j++)
        {
            if(ans[i][j]=="")
                cout<<"    ";
            else
                cout<<ans[i][j]<<"   ";
        }
        cout<<endl;
    }

    return 0;
}












