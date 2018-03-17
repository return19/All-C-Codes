#include<bits/stdc++.h>
using namespace std;

char str[1100];
char temp[1100];
int main()
{
    int test,i,j,k;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        strcpy(temp,str);

        sort(temp,temp + strlen(temp));



        next_permutation(str,str + strlen(str));
        //cout<<"ans :"<<str<<endl;
        if(strcmp(temp,str)==0)
        {
            printf("no answer\n");
            continue;
        }

            printf("%s\n",str);

    }

    return 0;
}
