#include<bits/stdc++.h>
using namespace std;

long long Tmatrix[31][31]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
long long Fmatrix[31][31]={{0},{0},{0},{0},{0},{0}};



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
    long long ans1,ans2;
    long long test;
    long long a1,b1,c1;
    long long a2,b2,c2;

    long long f0,f1,f2;
    long long g0,g1,g2;

    long long q;
    long long it1;

    scanf("%lld",&test);

    for(j=0;j<test;j++)
    {
        printf("Case %lld:\n",j+1);

        scanf("%lld%lld%lld",&a1,&b1,&c1);
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        scanf("%lld%lld%lld",&f0,&f1,&f2);
        scanf("%lld%lld%lld",&g0,&g1,&g2);

        Tmatrix[2][1]=b1;
        Tmatrix[2][2]=a1;
        Tmatrix[2][3]=c1;

        Tmatrix[5][0]=c2;
        Tmatrix[5][4]=b2;
        Tmatrix[5][5]=a2;

        Fmatrix[0][0]=f0;
        Fmatrix[1][0]=f1;
        Fmatrix[2][0]=f2;
        Fmatrix[3][0]=g0;
        Fmatrix[4][0]=g1;
        Fmatrix[5][0]=g2;

        scanf("%lld",&m);

        scanf("%lld",&q);

        for(it1=0;it1<q;it1++)
        {
            scanf("%lld",&n);

            if(n==0)
            {
                printf("%lld %lld\n",f0%m,g0%m);
                continue;
            }
            else if(n==1)
            {
                printf("%lld %lld\n",f1%m,g1%m);
                continue;
            }
            else if(n==2)
            {
                printf("%lld %lld\n",f2%m,g2%m);
                continue;
            }


                matrix<long long> T(6,6);
                matrix<long long> F(6,1);
                T.assign(6,6);

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

                long long MOD = m;


                ans1=((p(T,n-2,MOD)*F)%MOD)[2][0];
                ans2=((p(T,n-2,MOD)*F)%MOD)[5][0];



               // cout<<"here3"<<endl;
                printf("%lld %lld\n",ans1%MOD,ans2%MOD);


        }

        //memset(Tmatrix,0,sizeof(Tmatrix));
       // memset(Fmatrix,0,sizeof(Fmatrix));


        //cout<<"here3"<<endl;


    }

	/*matrix<long long> T(5,5);
	matrix<long long> F(5,1);
	T.assign(5,5);

	for(int i=0;i<T.rowSize();i++)
		for(int j=0;j<T.columnSize();j++)
			T[i][j]=Tmatrix[i][j];

	for(int i=0;i<F.rowSize();i++)
		for(int j=0;j<F.columnSize();j++)
			F[i][j]=Fmatrix[i][j];

	const int MOD = 10000007;


	for(int i=0;i<30;i++)
		cout<<((p(T,i,MOD)*F)%MOD)[4][0]<<endl;*/


}

