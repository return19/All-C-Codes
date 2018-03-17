#include<bits/stdc++.h>
using namespace std;

char str[110000];

int main()
{
    int i,j,k;
    int a_ec=0,a_oc=0;
    int b_ec=0,b_oc=0;
    int n;
    int l_a,l_b;


    scanf("%s",str);

    n=strlen(str);

    for(i=0;i<n;i++)
        if(str[i]=='a')
        {
            l_a=i;
            break;
        }
    for(i=0;i<n;i++)
        if(str[i]=='b')
        {
            l_b=i;
            break;
        }

    a_oc=1;

    for(i=l_a+1;i<n;i++)
    {
        if(str[i]=='a')
        {

        }
    }

    printf("%d\n%d\n",a_ec+b_ec,b_oc+a_oc);

    return 0;
}
