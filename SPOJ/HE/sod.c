#include <stdio.h>

int sod(int num)
{
	int sum=0;
	while(num!=0)
	{
		sum=sum+num%10;
		num=num/10;
	}
	return sum;

}

int main()
{
	int test,kase,sum_dig=0,sum_num=0,i,ans;

	scanf("%d",&test);

	for(i=0;i<test;i++)
	{
		scanf("%d",&kase);
		sum_dig+=sod(kase);
		sum_num+=kase;
	}
	sum_dig=sum_dig%9;
	sum_num=sod(sum_num);
	sum_num=sum_num%9;
	ans=sum_dig-sum_num;
	printf("%d",ans);

    return 0;
}
