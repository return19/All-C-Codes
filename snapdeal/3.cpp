#include<bits/stdc++.h>
using namespace std;

int s[25];
int q[25];

int c[25][25];
int n,m;

int mn;
int mx;

int ismasked(int mask,int pos)
{
    if(pos==0)
    {
        if(mask&1)
            return 1;
        return 0;
    }
    else
    {
        if(mask&(1<<pos))
            return 1;
        return 0;
    }
}

void maskit(int &mask,int pos)
{
    if(pos==0)
    {
        mask +=1;
    }
    else
        mask |= (1<<pos);
}

queue< pair<int,int> > qu;

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%d",&s[i]);

    for(j=0;j<m;j++)
        scanf("%d",&q[j]);


    char str[25];

    for(i=0;i<n;i++)
    {
        scanf("%s",str);

        int l=strlen(str);

        for(j=0;j<l;j++)
        {
            if(str[j]=='Y')
                c[i][j]=1;
            else
                c[i][j]=0;
        }
    }


    mn=INT_MAX;
    mx=INT_MIN;


    pair< int,int > p;

    int idx=1,mask=0,sum;

    for(i=0;i<m;i++)
            {
                if(!ismasked(mask,i)&&c[0][i])
                {
                    int temp=mask;
                    maskit(temp,i);

                    qu.push(make_pair(temp,s[0]*q[i]));
                }
            }

        qu.push(make_pair(-1,-1));



    while(!qu.empty())
    {
        p=qu.front();
        qu.pop();


        mask=p.first;
        sum=p.second;

        if(mask==-1&&sum==-1)
        {
            if(qu.empty())
                break;

            idx++;
            qu.push(make_pair(-1,-1));
            continue;
        }

        if(idx==n)
        {
            mn=min(mn,sum);
            mx=max(mx,sum);
        }
        else
        {
            for(i=0;i<m;i++)
            {
                if(!ismasked(mask,i)&&c[idx][i])
                {
                    int temp=mask;
                    maskit(temp,i);

                    qu.push(make_pair(temp,sum+ s[idx]*q[i]));
                }
            }
        }

    }



    printf("%d %d\n",mn,mx);


    return 0;
}
