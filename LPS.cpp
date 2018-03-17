#include<bits/stdc++.h>
using namespace std;

int n,maxl=1;
char str[100100];

void init_dp()
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        j=i-1;
        k=i+1;
        while(j>=0&&k<n&&str[j]==str[k])
        {
            if(maxl<k-j+1)
            {
                maxl=k-j+1;
            }
            j--;
            k++;
        }
        j=i-1;
        k=i;
        while(j>=0&&k<n&&str[j]==str[k])
        {
            if(maxl<k-j+1)
            {
                maxl=k-j+1;
            }
            k++;
            j--;
        }
    }
}

int main()
{
    int i,j,k;

    scanf("%d",&n);
    scanf("%s",str);

    init_dp();
    printf("%d",maxl);
    return 0;
}
