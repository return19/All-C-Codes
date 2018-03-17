#include<bits/stdc++.h>
using namespace std;

string s;
string a;

int main()
{
    int i,j,k;
    int test,t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        cin>>s;
        a="";

        n=s.length();

        for(i=0;i<n;i++)
        {
            if(s[i]=='\'')
            {
                i++;
                for(;i<n;i++)
                    a.push_back(s[i]);
            }
        }

        n=a.length();

        if(n==1)
        {

        }else if(n==2)
        {

        }else if(n==3)
        {

        }else{

        }
    }


    return 0;
}

