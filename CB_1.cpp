#include<bits/stdc++.h>
using namespace std;

map<char,int> husb;
map<char,int> wife;
map<char,int>::iterator it;
char str[50110];
int main()
{
    int test,i,j,k;
    char c;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        husb.clear();
        wife.clear();
        scanf("%s",str);
        j=0;
        while(str[j]!='\0')
        {
            husb[str[j]]++;
            j++;
        }
        scanf("%s",str);
        k=0;
        while(str[k]!='\0')
        {
            wife[str[k]]++;
            k++;
        }
        if(j!=k)
        {
            printf("NO\n");
            continue;
        }
        int flag=0;
        for(it=husb.begin();it!=husb.end();it++)
        {
           // cout<<it->first<<" "<<it->second<<" "<<wife[it->first]<<endl;
            if(it->second!=wife[it->first])
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("YES\n");
        }

    }
    return 0;
}
