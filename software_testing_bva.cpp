#include<bits/stdc++.h>
using namespace std;

int arr[110][3];
int range_start=1;
int range_end=200;
vector<int> test;

void gentest()
{
	int i,j,k;

	test.push_back(range_start);
	test.push_back(range_start+1);
	test.push_back(range_end-1);
	test.push_back(range_end);

	for(i=0;i<13;i++)
	{
		for(j=0;j<3;j++)
			arr[i][j]=(range_end+range_start)>>1;
	}

	i=0;

	for(j=0;j<3;j++){
		for(k=0;k<4;k++)
		{
			arr[i][j]=test[i%4];
			i++;
		}
	}

	arr[12][0]=arr[12][1]=arr[12][2]=(range_end+range_start)>>1;
}

int main()
{
	int i,j,k;
	int a,b,c;

	gentest();


    cout<<"a\t"<<"b\t"<<"c\t"<<"Expected Output"<<endl<<endl;

	for(i=0;i<4*3+1;i++){

		a=arr[i][0];
		b=arr[i][1];
		c=arr[i][2];

		cout<<a<<"\t"<<b<<"\t"<<c<<"\t";

		if(a<=0 || b<=0 || c<=0 || (a>=b+c)|| (b>=a+c)||(c>=a+b))
		{
			printf("Not a valid triangle\n");
		}
		else if(a==b && b==c)
		{
			printf("Equilateral\n");
		}
		else if((a==b)||(b==c)||(a==c))
		{
			printf("Isosceles\n");
		}
		else
		{
			printf("Scalene\n");
		}
	}


	return 0;
}

// look at my code it's so amazing
