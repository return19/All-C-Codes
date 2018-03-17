#include<bits/stdc++.h>
using namespace std;
// 3

int arr[110][110];
int n;
int vis[110];
int in[110];
vector<string> v;
string s;

stack<int> st;

int dfs(int x,int c)
{
    vis[x]=c;

    int i,j,k;

    for(i=0;i<26;i++)
    {
        if(i!=x && arr[x][i]==1)
        {
            if(vis[i]==c)
                return 1;
            else if(!vis[i])
            {
                if(dfs(i,c))
                    return 1;
            }
        }
    }
    vis[x]=1;

    return 0;
}

void dfs2(int x)
{
    vis[x]=1;
    int i;

    for(i=0;i<26;i++)
    {
        if(x!=i && arr[x][i]==1 && !vis[i])
            dfs2(i);
    }

    st.push(x);
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<v[i].length() && j<v[i+1].length();j++)
        {
            if(v[i][j] != v[i+1][j])
            {
                arr[v[i][j]-'a'][v[i+1][j]-'a']=1;
                in[v[i][j]-'a']=1;
                in[v[i+1][j]-'a']=1;
                break;
            }
        }

        if( j==min(v[i].length(),v[i+1].length()) && v[i].length() > v[i+1].length() )
        {
                printf("Impossible\n");
                return 0;

        }
    }

    int c=2;
    for(i=0;i<26;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,c))
            {
                printf("Impossible\n");
                return 0;
            }
            c++;
        }
    }

    for(i=0;i<26;i++)
        vis[i]=0;

    for(i=0;i<26;i++)
    {
        if(!vis[i] && in[i])
        {
            dfs2(i);
        }
    }

    for(i=0;i<26;i++)
        vis[i]=0;

    while(!st.empty())
    {
        int temp=st.top();
        st.pop();
        vis[temp]=1;
        printf("%c",temp+97);
    }

    for(i=0;i<26;i++)
    {
        if(!vis[i])
            printf("%c",i+97);
    }
    printf("\n");

    return 0;
}

