#include<bits/stdc++.h>
using namespace std;


map<string,int> memo;
int c=0;
int n;
void solve(string str,int idx,string fin,stack<int> s)
{
    if(idx==n)
    {
        while(!s.empty())
        {
            fin.push_back(s.top());
            s.pop();
        }

        if(memo[fin]==0)
            c++;

        memo[fin]++;

        //cout<<fin<<endl;
        return;
    }

    string fin1=fin;

    if(s.empty())
    {
        s.push(str[idx]);

        solve(str,idx+1,fin,s);
        s.pop();
        return;
    }

    char a=s.top();
    fin.push_back(s.top());
    s.pop();

    solve(str,idx,fin,s);
    s.push(a);

    s.push(str[idx]);

    solve(str,idx+1,fin1,s);
    s.pop();
}

int main()
{
    int i,j,k;

    string str;
    cin>>str;

    n=str.length();


    stack<int> st1;

    string s1="";

    solve(str,0,s1,st1);

    printf("%d %d\n",memo[str],c);

    return 0;
}

