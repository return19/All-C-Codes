#include<bits/stdc++.h>
using namespace std;

string str;
vector<string> v;

int main()
{
    int test,i,j,k;
    int n;



    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        v.resize(0);
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            //scanf("%s",str);
            cin>>str;

            v.push_back(str);
        }

        sort(v.begin(),v.end());
        int flag=0;
        for(j=0;j<n-1;j++)
        {
            if(v[j+1].substr(0,v[j].length())==v[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

    }

    return 0;
}


















