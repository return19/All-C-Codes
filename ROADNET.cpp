#include<bits/stdc++.h>
using namespace std;

int n;


int graph[1000][1000];

int main()
{
    int test,i,j,k,l;
    int ans;
    int flag;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%d",&graph[j][k]);
            }
        }

        for(j=0;j<n;j++)
        {

            for(k=j+1;k<n;k++)
            {
                flag=0;
                for(l=0;l<n;l++)
                {
                    if((j!=l)&&(k!=l)&&(graph[j][k]==graph[j][l]+graph[l][k]))
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0){

                    printf("%d %d\n",j+1,k+1);
                }
            }
        }



        if(i!=test-1)
        printf("\n");

    }

    return 0;
}















