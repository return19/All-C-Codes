#include<bits/stdc++.h>
using namespace std;

int arr2[5][5]={{-1,-1},
                {1,-1},
                {1,1},
                {-1,1}
               };

int arr3[9][9]={{-1,-1,1},
                {1,-1,1},
                {1,-1,-1},
                {-1,-1,-1},
                {-1,1,-1},
                {1,1,-1},
                {1,1,1},
                {-1,1,1}
                };

int main()
{
    int test,i,j,k;
    int s1,s2,s3;
    int n,d;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&d);

        if(n==2)
        {
            scanf("%d%d",&s1,&s2);

            if(d<4)
            {
                printf("-2\n");
                continue;
            }
            else
            {
                printf("%d %d\n",s1,s2);

                for(j=0;j<4;j++)
                {
                    if(arr2[j][0]==s1&&arr2[j][1]==s2)
                    {
                        for(k=j+1;k%4!=j;k++)
                        {
                            printf("%d %d\n",arr2[k%4][0],arr2[k%4][1]);
                        }
                    }
                }
            }
        }
        else if(n==3)
        {
            scanf("%d%d%d",&s1,&s2,&s3);

            if(d<4)
            {
                printf("-2\n");
                continue;
            }
            else
            {
                 printf("%d %d %d\n",s1,s2,s3);

                 for(j=0;j<8;j++)
                {
                    if(arr3[j][0]==s1&&arr3[j][1]==s2&&arr3[j][2]==s3)
                    {
                        for(k=j+1;k%8!=j;k++)
                        {
                            printf("%d %d %d\n",arr3[k%8][0],arr3[k%8][1],arr3[k%8][2]);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
