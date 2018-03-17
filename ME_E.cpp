#include<bits/stdc++.h>
using namespace std;

long long Tmatrix[31][31]={{0,1,0},{0,0,1},{1,1,1}};
long long Fmatrix[31][31]={{2},{4},{7}};
long long m1=1000000007;
#include<stdio.h>

/* Function to calculate x raised to the power y */
long long pow2mod(long long k)
{
	long long ret = 1;
	long long a = 2;
	while (k)
	{
		if (k & 1) ret *= a;
		a *= a;
		ret %= m1;
		a %= m1;
		k >>= 1;
	}
	return (ret);
}



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
int main()
{
    long long i,j,k;
    long long d,n,m;
    long long ans,ans1;
    long long test;
    long long a,b,c;

    scanf("%lld",&test);

    for(j=0;j<test;j++)
    {


        scanf("%lld",&n);

        if(n==1)
        {
                printf("0\n");
                continue;
        }
        else if(n==2)
        {
                printf("0\n");
                continue;
        }

        matrix<long long> T(3,3);
        matrix<long long> F(3,1);
        T.assign(3,3);


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


        long long MOD = 1000000007;


        ans=pow2mod(n)%MOD;
        ans1=((p(T,n-3,MOD)*F)%MOD)[2][0];



        if(ans<ans1)
            printf("%lld\n",ans+MOD-ans1);
        else
             printf("%lld\n",ans-ans1);



    }


}
