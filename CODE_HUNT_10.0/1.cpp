#include<bits/stdc++.h>
using namespace std;

char str[11000000];

int main()
{
    int test,i,j,k;
    int n;
    int flag=0;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        n=strlen(str);

        flag=0;

        for(j=1;j<n;j++)
        {
            //cout<<abs(str[j]-str[j-1])<<" "<<abs(str[n-j-1]-str[n-j+1-1])<<endl;

            if(abs(str[j]-str[j-1])!=abs(str[n-j-1]-str[n-j+1-1]))
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Funny\n");
        }
        else
        {
            printf("Not Funny\n");
        }
    }

    return 0;
}
