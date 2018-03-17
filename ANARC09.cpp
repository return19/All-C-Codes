#include<bits/stdc++.h>
using namespace std;

char str[2010];

stack<char> s;

int main()
{
    int i,j,k,count1=0;

    scanf("%s",str);

    i=1;

    while(str[0]!='-')
    {
        count1=0;

        j=0;
        while(str[j]!='\0')
        {
            if(str[j]=='{')
            {
                s.push('{');
            }
            else
            {
                if(!s.empty())
                {
                    s.pop();
                }
                else
                {
                    count1++;
                    s.push('{');
                }
            }
            j++;
        }

        while(!s.empty())
        {
            count1++;
            s.pop();
            s.pop();
        }

        printf("%d. %d\n",i,count1);

        scanf("%s",str);
        i++;
    }

    return 0;
}











