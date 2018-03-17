#include<bits/stdc++.h>
using namespace std;

map<char,int> memo1;
map<char,int> memo2;

map<char,int>::iterator it;

char str[1010];

int min2(int x,int y)
{
    if(x<y)
        return x;
    else
        return y;
}

int main()
{
    int i,j,k;


    while(scanf("%s",str)>0){
        memo1.clear();
        memo2.clear();
        i=0;
        while(str[i]!='\0')
        {
            memo1[str[i]]++;
            i++;
        }

        scanf("%s",str);

        i=0;
        while(str[i]!='\0')
        {
            memo2[str[i]]++;
            i++;
        }

        for(it=memo1.begin();it!=memo1.end();it++)
        {
            j=min2(it->second,memo2[it->first]);
            for(i=1;i<=j;i++)
            {
                printf("%c",it->first);
            }
        }
        printf("\n");

        //scanf("%s",str);

    }



    return 0;
}
