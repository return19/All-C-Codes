#include <stdio.h>
#include<math.h>

int main()
{
    int x,y,i,j,mod[100];
    int test,cases[100];


    scanf("%d%d",&x,&y);
    scanf("%ld",&test);

    for(i=0;i<test;i++)
    { scanf("%ld",&cases[i]);
    	mod[i]=(pow(x,cases[i])-cases[i]*y)%1000000007;
    }

    for(i=0;i<test;i++)
    {
    	printf("%ld",mod[i]);
    }

    return 0;
}
