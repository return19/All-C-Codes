#include<bits/stdc++.h>
using namespace std;

int p[101000];
int arr[101000];

int main()
{
    int i,j,k;
    int n;
    int q,x;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

        int temp=arr[i];
        int srt=sqrt(temp);
        for(j=2;j<=srt+1;j++)
        {
            while(temp%j==0)
            {
                p[j]++;
                temp/=j;
            }
        }
        if(temp>1)
            p[temp]++;
    }

    //for(i=0;i<10;i++)
      //  cout<<p[i]<<" ";
    //cout<<endl;

    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&x);
        int srt=sqrt(x);
        int ans=INT_MAX;
        for(j=2;j<=srt+1;j++)
        {
            int c=0;
            while(x%j==0)
            {
                c++;
                x/=j;
            }
            if(c>0)
            {
                ans=min(ans,p[j]/c);
            }
        }

        if(x>1)
            ans=min(ans,p[x]);
        printf("%d\n",ans);
    }



    return 0;
}










