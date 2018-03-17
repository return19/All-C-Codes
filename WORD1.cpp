#include<bits/stdc++.h>
using namespace std;

map<char,int> first;

map< pair<char,char>,int> pairs;

pair<char,char> p;

char str[1001000];

char strreal[1001000],N;

int main()
{
    int test,i,j,k;
    int n;
    char start,ended,x;
    int slen;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        pairs.clear();
        first.clear();

        scanf("%d",&n);

        N=-1;

        for(j=0;j<n;j++){
            scanf("%s",str);

            start=str[0];

            slen=strlen(str);

            ended=str[slen-1];

            //cout<<"start : "<<start<<" ended : "<<ended<<endl;

            p.first=start;
            p.second=ended;

            pairs[p]++;

            first[start]++;

            strreal[++N]=ended;
        }

        int flag=0;

        for(j=0;j<N;j++)
        {
            x=strreal[j];
            p.first=x;
            p.second=x;
            if(first[x]!=0&&pairs[p]==0)
            {
                first[x]--;
                continue;
            }

            if(first[x]==0)
            {
                flag=1;
                break;
            }

            if(first[x]==1&&pairs[p]==1)
            {
                flag=1;
                break;
            }

            if(first[x]>=pairs[p])
            {
                first[x]--;
                pairs[p]--;
                continue;
            }

        }

        if(flag==1)
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            printf("Ordering is possible.\n");
        }


    }

    return 0;
}
