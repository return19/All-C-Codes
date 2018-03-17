#include<bits/stdc++.h>
using namespace std;

string s;
string cnt;
int pos[300];

int main()
{
    int i,j,k;
    int n,m;
    string x,y;
    scanf("%d%d",&n,&m);

    cin>>s;

    for(i=0;i<26;i++){
        cnt.push_back('a'+i);
        pos['a'+i]=i;
    }

    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        int px=pos[x[0]];
        int py=pos[y[0]];

        swap(cnt[px],cnt[py]);
        swap(pos[x[0]],pos[y[0]]);
    }

    for(i=0;i<n;i++)
    {
        s[i]=cnt[s[i]-'a'];
    }

    cout<<s<<endl;

    return 0;
}












