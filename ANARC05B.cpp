#include<bits/stdc++.h>
using namespace std;

int a[101000];
int b[101000];

int main()
{
    int i,j,k;

    int n,m;

    int s1,s2;

    scanf("%d",&n);

    while(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        scanf("%d",&m);

        for(i=0;i<m;i++)
            scanf("%d",&b[i]);

        i=0;
        j=0;

        s1=0;
        s2=0;

        int ans=0;

        while(i<n&&j<m)
        {
            if(a[i]<b[j])
            {
                s1+=a[i];
                i++;
            }
            else if(a[i]>b[j])
            {
                s2 += b[j];
                j++;
            }
            else
            {
                s1+=a[i];
                s2+=b[j];
                i++;
                j++;

                ans += max(s1,s2);

                s1=0;
                s2=0;
            }
        }

        while(i<n)
            s1 += a[i++];

        while(j<m)
            s2 += b[j++];

        ans += max(s1,s2);

        printf("%d\n",ans);

        scanf("%d",&n);
    }

    return 0;
}









