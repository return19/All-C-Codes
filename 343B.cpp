#include<bits/stdc++.h>
using namespace std;

stack<int> s;
char str[101000];
int main()
{
    int i,j,k;
    int n;
    int temp;

    scanf("%s",str);

    n=strlen(str);

    for(i=0;i<n;i++)
    {
        if(str[i]=='+')
            temp=0;
        else
            temp=1;

        if(s.empty())
        {
            s.push(temp);
            continue;
        }

        if(s.top()==temp)
            s.pop();
        else
            s.push(temp);
    }

    if(s.empty())
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
