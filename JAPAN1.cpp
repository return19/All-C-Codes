#include<bits/stdc++.h>
using namespace std;

long max2(long x,long y)
{
	if(x>y)
	return x;
	else
	return y;
}

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;


	public:
		BIT(){}

		BIT(size_t n)
		{
			assign(n);
		}

		void assign(long n)
		{
			tree.clear();
			tree.resize(n+1);
		}

	 	value_type query(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}

		value_type update(size_t a,size_t b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,-value);

		}
		void clear()
		{
			tree.clear();
		}

		void increase(size_t idx, const value_type &val)
		{
			while (idx <= tree.size()-1)
			{
				tree[idx] += val;
				idx += (idx & (- idx));
			}
		}
};

typedef struct a1
{
    long x;
    long y;
}ar;

long cmp(ar a,ar b)
{
    if(a.x!=b.x)
    {
        return (a.x<b.x);
    }

    return (a.y<b.y);
}


ar arr[10000010];
BIT<long> bt(10010);

int main()
{
    long n,m,k;
    long i,j,x,y;
    long test;
    long sum;

    scanf("%ld",&test);

    for(i=0;i<test;i++)
    {


       // memset(arr,0,sizeof(arr));

        scanf("%ld%ld%ld",&n,&m,&k);
        bt.assign(max2(n,m)+10);

        sum=0;

        for(j=1;j<=k;j++)
        {
            scanf("%ld%ld",&arr[j].y,&arr[j].x);
        }

        sort(arr+1,arr+k+1,cmp);
        /*cout<<endl;
        for(j=1;j<=k;j++)
            cout<<arr[j].x<<" "<<arr[j].y<<endl;
*/
        for(j=1;j<=k;j++)
        {
            x=arr[j].x;
            y=arr[j].y;

            sum=sum+bt.query(n+1)-bt.query(y);
           // cout<<bt.query(n+1)<<" "<<bt.query(y)<<endl;

            bt.increase(y,1);

        }

        printf("Test case %ld: %ld\n",i+1,sum);
    }

    return 0;
}




















