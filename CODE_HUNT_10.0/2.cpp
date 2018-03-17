#include<bits/stdc++.h>
using namespace std;

char str[11000000];

map<char,int> memo;

map<char,int>::iterator it;

int main()
{
    int i,j,k;
    int n;

    scanf("%s",str);

    i=0;

    while(str[i]!='\0')
    {
        memo[str[i]]++;

        i++;
    }

    int flag=0;

    for(it=memo.begin();it!=memo.end();it++)
    {
        //cout<<it->first<<" "<<it->second<<endl;

        if((it->second)%2!=0)
        {
            flag++;

        }
    }

    //cout<<flag<<" "<<i<<endl;

    if(flag==0&&(i)%2==0)
    {
        printf("YES\n");
    }
    else if(flag==1&&(i)%2!=0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
