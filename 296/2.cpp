#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > s;
int arr[501000];

char a[501000];
char b[501000];

map< pair<char,char>,int> m1;
map< char,int > wp1,wp2;
map< pair<char,char>,int>::iterator it;

pair<int,int> ans;

int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    scanf("%s%s",a,b);

    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i]){
            m1[make_pair(a[i],b[i])]=1;
            wp1[a[i]]=i+1;
            wp2[b[i]]=i+1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i] && m1[make_pair(b[i],a[i])]==1)
        {
            for(j=0;j<n;j++)
            {
                if(a[j]==b[i] && b[j]==a[i]){
                    swap(b[i],b[j]);
                    ans.first=i;
                    ans.second=j;
                    break;
                }
            }
            int hd=0;
            for(j=0;j<n;j++)
            {
                if(a[j]!=b[j])
                    hd++;
            }
            printf("%d\n",hd);
            printf("%d %d\n",ans.first+1,ans.second+1);
            return 0;
        }
    }

    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(wp2[a[i]]!=0)
            {
                swap(b[i],b[wp2[a[i]]-1]);
                int hd=0;
                for(j=0;j<n;j++)
                {
                    if(a[j]!=b[j])
                        hd++;
                }
                printf("%d\n",hd);
                printf("%d %d\n",i+1,wp2[a[i]]);
                return 0;
            }
        }
    }

    int hd=0;
    for(j=0;j<n;j++)
    {
        if(a[j]!=b[j])
            hd++;
    }
    printf("%d\n",hd);
    printf("-1 -1\n");

    return 0;
}

