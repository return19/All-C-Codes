#include<bits/stdc++.h>
using namespace std;

int a1[110000];
int a2[110000];
int a3[110000];

int main()
{
    int i,j,k;

    int n1,n2,n3;

    scanf("%d",&n1);

    for(i=0;i<n1;i++)
    {
        scanf("%d",&a1[i]);
    }

        scanf("%d",&n2);

    for(i=0;i<n2;i++)
    {
        scanf("%d",&a2[i]);
    }

        scanf("%d",&n3);

    for(i=0;i<n3;i++)
    {
        scanf("%d",&a3[i]);
    }

    i=0;
    j=0;
    k=0;

    int ans=0;

    while(i<n1&&j<n2&&k<n3)
    {
        if(a1[i]==a2[j]&&a2[j]==a3[k])
        {
            ans++;
            cout<<a1[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(a1[i]<=a2[j]&&a1[i]<=a3[k])
            i++;
        else if(a2[j]<=a1[i]&&a2[j]<=a3[k])
            j++;
        else
            k++;
    }

    printf("\n%d\n",ans);

    return 0;
}
