#include<bits/stdc++.h>
using namespace std;

vector<string> v;
string s;

int dist(int x,int y)
{
    int ans=0;
    int i,j,k;

    if(v[x][y]=='W')
    {
        for(i=0;i<x;i++)
        {
            if(v[i][y]=='B' || v[i][y]=='W')
                return INT_MAX;
            ans++;
        }
    }else{
        for(i=7;i>x;i--)
        {
            if(v[i][y]=='B' || v[i][y]=='W')
                return INT_MAX;
            ans++;
        }
    }
    return ans;
}


int main()
{
    int i,j,k;

    for(i=0;i<8;i++)
    {
        cin>>s;
        v.push_back(s);
    }

    int w=INT_MAX,b=INT_MAX;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
           // cout<<i<<" "<<j<<endl;
            if(v[i][j]=='W')
                w=min(w,dist(i,j));
            else if(v[i][j]=='B')
                b=min(b,dist(i,j));
        }
    }

    if(w<=b)
        printf("A\n");
    else
        printf("B\n");

    return 0;
}
