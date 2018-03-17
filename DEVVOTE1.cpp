
#include<bits/stdc++.h>
using namespace std;

int memo[10];

int main()
{
    int test,i,j,k,n;
    int a,b,c,d,e,f,g;

    int max1=-1;
    int count1=0;
    int sum=0;
    scanf("%d",&test);
    n=7;

    for(a=0;a<n;a++)
    {
        for(b=0;b<n;b++)
        {
            if(a!=b)
            for(c=0;c<n;c++)
            {
                if(b!=c)
                for(d=0;d<n;d++)
                {
                    if(c!=d)
                    for(e=0;e<n;e++)
                    {
                        if(d!=e)
                        for(f=0;f<n;f++)
                        {
                            if(e!=f)
                            for(g=0;g<n;g++)
                            {
                                if(g!=f)
                                {
                                    count1++;

                                    memset(memo,0,sizeof(memo));

                                    memo[a]++;
                                    memo[b]++;
                                    memo[c]++;
                                    memo[d]++;
                                    memo[e]++;
                                    memo[f]++;
                                    memo[g]++;
                                    max1=-1;
                                    for(i=0;i<n;i++)
                                    {
                                        if(max1<memo[i])
                                            max1=memo[i];
                                    }



                                    for(i=0;i<n;i++)
                                    {
                                        if(memo[i]==max1)
                                        {
                                            sum++;
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"count1 :"<<count1<<"    sum :"<<sum<<endl;

    printf("%d\n",sum/count1);

    return 0;
}

