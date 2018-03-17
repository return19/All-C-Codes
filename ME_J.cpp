#include<bits/stdc++.h>
using namespace std;

long long Tmatrix[31][31]={{0,1,0},{0,0,1},{1,0,2}};
long long Fmatrix[31][31]={{1},{2},{5}};



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
    long long ans1;
    long long test;
    long long n;


    scanf("%lld",&test);

    for(j=0;j<test;j++)
    {
        scanf("%lld",&n);

        if(n==1)
        {
            printf("Case %lld: 1\n",j+1);
            continue;
        }
        else if(n==2)
        {
             printf("Case %lld: 2\n",j+1);
            continue;
        }
        else if(n==3)
        {
             printf("Case %lld: 5\n",j+1);
            continue;
        }

                matrix<long long> T(3,3);
                matrix<long long> F(3,1);
                T.assign(3,3);

                //cout<<"here1"<<endl;

                for(long long i=0;i<T.rowSize();i++)
                    for(long long j=0;j<T.columnSize();j++)
                       {
                           T[i][j]=Tmatrix[i][j];
                           //cout<<T[i][j];
                       }
                //cout<<"here2"<<endl;
                for(long long i=0;i<F.rowSize();i++)
                    for(long long j=0;j<F.columnSize();j++)
                       {
                            F[i][j]=Fmatrix[i][j];
                            //cout<<F[i][j];
                       }
                 //cout<<"here3"<<endl;

                long long MOD = 10007;


                ans1=((p(T,n-3,MOD)*F)%MOD)[2][0];

               // cout<<"here3"<<endl;
                printf("Case %lld: %lld\n",j+1,ans1%MOD);






    }

    return 0;


}


