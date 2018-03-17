#include<bits/stdc++.h>
using namespace std;
void func()
{
	int n,choice,num,tot;
	n=100+rand()%100;
	cout<<2*n<<"\n";
	while(n--)
	{
		choice = rand()%4 + 1;
		switch(choice)
		{
			case 1: num = rand()%1000;
			        num = rand()%2 ? num : -num;
			        cout<<"1 "<<num<<"\n";
			        break;
		    case 2: tot = rand()%50;
		            num = rand()%1000;
			        num = rand()%2 ? num : -num;
			        cout<<"2 "<<tot<<" "<<num<<"\n";
			        break;
			case 3: cout<<"3 \n";
			        break;
			case 4: tot = rand()%50;
			        cout<<"4 "<<tot<<"\n";
					break;
		}
		cout<<"5\n";
	}
}
int main()
{
	for(int i=0;i<=5;i++)
	{
		char s[] = "input0.txt";
		s[5] = char(i+'1');
		freopen(s,"wt",stdout);
		func();
	}	
}
