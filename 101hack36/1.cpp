#include<bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main()
{
    int i,j,k;
    cin>>str;

    int n=str.length();

    for(i=0;i<n;i++)
    {
        if(s.empty())   s.push(str[i]);
        else{
            if(s.top()==str[i])
                s.pop();
            else
                s.push(str[i]);
        }
    }

    if(s.empty())
        printf("Empty String\n");
    else{
        string t;
        while(!s.empty())
        {
            t.push_back(s.top());
            s.pop();
        }
        n=t.length();

        for(i=0,j=n-1;i<j;i++,j--)
            swap(t[i],t[j]);
        cout<<t<<endl;
    }

    return 0;
}
