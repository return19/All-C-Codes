#include<bits/stdc++.h>
using namespace std;

long long Tmatrix[31][31]={{0,1},{1,1}};
long long Fmatrix[31][31]={{1},{1}};

long long MOD=99991;

long long n,k;
long long arr[110];

template<class T> class matrix
{
	public:
		typedef T value_type;
	private:
		vector<vector<T> > M;
	public:
		matrix(){}

		matrix(long long rSize,long long cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));
		}

		void assign(long long rSize,long long cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));
		}

		vector<value_type>& operator[](long long i)
		{
			return M[i];
		}


		long long rowSize() const
		{
			return M.size();
		}
		long long columnSize() const
		{
			if(M.size()==0)
				return 0;
			else
				return M[0].size();
		}
		matrix<value_type> operator *(matrix<value_type> B) //assumes matricces are multiplicable
		{
			matrix<value_type> &A=*this;
			matrix<value_type> temp(A.rowSize(),B.columnSize());

			for(long long i=0;i<temp.rowSize();i++)
				for(long long j=0;j<temp.columnSize();j++)
					for(long long k=0;k<B.rowSize();k++)
						temp[i][j]+=A[i][k]*B[k][j];

			return temp;
		}

		matrix<value_type> operator %(value_type MOD)
		{
			matrix<value_type> temp(rowSize(),columnSize());
			for(long long i=0;i<rowSize();i++)
				for(long long j=0;j<columnSize();j++)
					temp[i][j]=M[i][j]%MOD;
			return temp;
		}
		void clear()
		{
			M.clear();
		}

		static matrix<value_type> identity(long long i)
		{
			matrix<value_type> X;
			X.assign(i,i);
			for(long long j=0;j<i;j++)
				X[j][j]=1;
			return X;
		}
};

template<class T> T p(T n,long long m,long long MOD)
{
    if(m==0)
		return matrix<long long>::identity(n.rowSize());

    T x=p(n,m/2,MOD);
    if(m%2==0)
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

template<class T> void printMatrix(matrix<T> X)
{
	for(long long i=0;i<X.rowSize();i++)
	{
		for(long long j=0;j<X.columnSize();j++)
			cout<<X[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

long long cal_fib(long long x)
{

    if(x==1||x==2)
        return 1;


    matrix<long long> T(2,2);
        matrix<long long> F(2,1);
        T.assign(2,2);


        for(long long i=0;i<T.rowSize();i++)
            for(long long j=0;j<T.columnSize();j++)
               {
                   T[i][j]=Tmatrix[i][j];

               }

        for(long long i=0;i<F.rowSize();i++)
            for(long long j=0;j<F.columnSize();j++)
               {
                    F[i][j]=Fmatrix[i][j];

               }

        return ((p(T,x-2,MOD)*F)%MOD)[1][0];

}

long long sum;

void solve(long long x,long long i,long long cur)
{
    if(i>n)
        return;


    if(x==0)
    {
        sum=(sum+cal_fib(cur))%MOD;
        return;
    }

    solve(x,i+1,cur);
    solve(x-1,i+1,cur+arr[i]);
}

int main()
{
    long long i,j;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    sum=0;

    solve(k,0,0);

    printf("%lld\n",sum%MOD);

    return 0;
}
