#include<bits/stdc++.h>
using namespace std;

vector< string > str(101000);

int main()
{
    int i,j,k;
    int n;
    int idx=-1;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        cin >> str[i];
        k=str[i].length();

        if(k==1)
        {
            if(str[i][0]=='0')
            {
                printf("0\n");
                return 0;
            }
            else if(str[i][0]!='1')
            {
                idx=i;
                continue;
            }
        }

        if(str[i][0]!='1')
        {
            idx=i;
            continue;
        }

        for(j=1;j<k;j++)
        {
            if(str[i][j]!='0')
            {
                idx=i;
                break;
            }
        }
    }

    if(idx!=-1)
    {
        cout << str[idx];
    }
    else
        cout<<1;

    for(i=0;i<n;i++)
    {
        if(i==idx)
            continue;
        k=str[i].length();
        for(j=0;j<k-1;j++)
            cout<<0;
    }

    return 0;
}



















