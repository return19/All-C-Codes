#include<bits/stdc++.h>
using namespace std;

char str[31];

map<string,long long> memo;

char abc[30];

int main()
{

    long long i,j,k;
    long long n,sum=0;

    for(i=0;i<26;i++)
    {
        abc[i]=97+i;
        //cout<<abc[i]<<endl;
    }



    scanf("%s",str);

    n=strlen(str);

    for(i=0;i<n;i++)
    {
        for(j=0;j<26;j++)
        {
            long long x=-1;
            string temp;

            for(k=0;k<n;k++)
            {
                if(k==i)
                {
                    temp.push_back(abc[j]);
                }

                temp.push_back(str[k]);

            }
            if(memo[temp]==0)
            {
                sum++;
            }

           // cout<<temp<<endl;
            memo[temp]++;

        }
    }

    for(i=0;i<26;i++)
    {
        string temp;

        for(j=0;j<n;j++)
            temp.push_back(str[j]);

        temp.push_back(abc[i]);

        if(memo[temp]==0)
            {
                sum++;
            }

           // cout<<temp<<endl;
            memo[temp]++;
    }

    printf("%lld\n",sum);

    return 0;
}
