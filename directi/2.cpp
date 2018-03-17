#include<bits/stdc++.h>
using namespace std;

map<char,char> g;
map<char,int> vis;
map<char,int> val;

map<char,int> cur;

int dfs(char x){
    int i,j,k;
    vis[x]=1;
    cur[x]=1;

    char y = g[x];

    if(g.find(y)!=g.end() && g[y] == y)
    {
        val[x]=-1;
        val[y]=-1;
        cur[x]=0;
        return -1;
    }

    if(48<=y && y<=57)
    {
        val[x] = y;
        cur[x]=0;
        return y;
    }

    if(vis[y] == 1)
    {
        cur[x]=0;
        if(cur[y]==1){
            val[x]='0';
            return '0';
        }else{
            return val[x]=val[y];
        }
    }

    if(g.find(y) == g.end())
    {
        val[x] = -1;
        cur[x]=0;
        return -1;
    }
    val[x]=dfs(y);
    cur[x]=0;
    return val[x];
}

//you may add more methods here

void decode (int n, char orig[], char mapped[], int k, string inputs[], string outputs[]) {
    //add code to this function to solve the problem
    //don't write code in this editor
    //your code will not be saved across submissions
    int i,j;

    g.clear();
    val.clear();
    vis.clear();
    cur.clear();

    for(i=0;i<n;i++){
        g[orig[i]] = (mapped[i]);
    }

    for(i=0;i<n;i++){
        if(vis.find(orig[i]) == vis.end()){
            dfs(orig[i]);
        }
    }

    for(i=0;i<k;i++){
        string temp;
        int f=0;
        int x = inputs[i].length();
        for(j=0;j<x;j++){
            if( g.find(inputs[i][j]) == g.end() || val[inputs[i][j]]==-1)
            {
                temp.push_back('-');
                temp.push_back('1');
                f=1;
                break;
            }
        }
        if(!f)
            for(j=0;j<x;j++)
                temp.push_back(val[inputs[i][j]]);
        outputs[i] = temp;
    }

}

int main (){
    int T, n;
    int k;
    char orig[32], mapped[32];
    string inputs[32], outputs[32];
    int i, j;
    cin >> T;
    for (i=0; i<T; i++){
        cin >> n;
        for (j=0; j<n; j++)
            cin >> orig[j] >> mapped[j];
        cin >> k;
        for (j=0; j<k; j++)
            cin >> inputs[j];

        decode (n, orig, mapped, k, inputs, outputs);

        cout << "#" << i+1 << endl ;
        for (j=0; j<k; j++)
            cout << outputs[j] << endl ;
    }
    return 0;
}
