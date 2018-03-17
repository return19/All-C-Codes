#include <stdio.h>

int main()
{
    int test,n,k,fnl[1000],i,d,r;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
    	scanf("%d%d",&n,&k);
    	d=n/k;
    	r=n%k;

    	if(d%2!=0)
    	{
    		fnl[i]=0;
    		if(r<=1)
    		{
    			fnl[i]=1;
    		}

    	}
    	else if(d%2==0)
    	{
    		fnl[i]=1;
    		if(r<=1)
    		{
    			fnl[i]=0;
    		}

    	}
    }

    for(i=0;i<test;i++)
    {   if(fnl[i]==1)
        {
    	printf("Rani\n");
        }
        else
        {
        	printf("Nandu\n");
        }
    }

    return 0;
}
