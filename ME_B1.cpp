
#include<bits/stdc++.h>
using namespace std;

long long Tmatrix[31][31];
long long Fmatrix[31][31];

long long mod(long long a,long long m)
{
   if(a>0) return a%m;
   if(a==0) return 0;
   a=a*-1;
   long long M=a%m;
   if(M==0) return 0;
   return m-M;
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
					temp[i][j]=mod(M[i][j],MOD);
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
    long long ans;
    long long test;
    long long x,y,z;
    long long extrac;

    scanf("%lld",&test);

    for(x=0;x<test;x++)
    {
        scanf("%lld%lld%lld",&k,&m,&n);

        if(k==0)
        {
            scanf("%lld",&z);
            ans=mod(z,m);

            if(ans<0)
                ans=ans+m;

                if(x!=test-1){
                    printf("%lld\n\n",mod(ans,m));
                }
                else{
                    printf("%lld",mod(ans,m));
                    //cout<<"here";
                }
            continue;
        }

        memset(Tmatrix,0,sizeof(Tmatrix));
        memset(Fmatrix,0,sizeof(Fmatrix));

        Tmatrix[0][0]=1;

        for(i=1;i<k;i++)
        {
            Tmatrix[i][i+1]=1;
        }

        Tmatrix[k][0]=1;

        for(i=k;i>=1;i--)
        {
            scanf("%lld",&Tmatrix[k][i]);
        }

        scanf("%lld",&Fmatrix[0][0]);

        for(i=1;i<=k;i++)
        {
            scanf("%lld",&Fmatrix[i][0]);
        }


        if(n<=k-1)
        {
            ans=mod(Fmatrix[n+1][0],m);

            if(ans<0)
                ans=ans+m;

                if(x!=test-1){
                    printf("%lld\n\n",mod(ans,m));
                }
                else{
                    printf("%lld",mod(ans,m));
                    //cout<<"here";
                }
            continue;
        }


        //////////to be removed

      /*  for(i=0;i<k+1;i++)
        {
            for(j=0;j<k+1;j++)
                cout<<Tmatrix[i][j]<<" ";
            cout<<endl;
        }

        for(i=0;i<k+1;i++)
        {

                cout<<Fmatrix[i][0]<<" ";
            cout<<endl;
        }*/

        ////////

        matrix<long long> T(k+1,k+1);
        matrix<long long> F(k+1,1);
        T.assign(k+1,k+1);

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

         //const long long MOD = m;

        ans=((p(T,n-k+1,m)*F)%m)[k][0];
        ans=mod(ans,m);

            if(ans<0)
                ans=ans+m;
        if(x!=test-1){
            printf("%lld\n\n",mod(ans,m));
        }
        else{
            printf("%lld",mod(ans,m));
            //cout<<"here";
        }
    }

    return 0;
}
