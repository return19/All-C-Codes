#include<bits/stdc++.h>
using namespace std;

int k,n,m;

struct elem
{
    double cost;
    double val;
    int index;
};

elem arr[110];

int cmp(elem a,elem b)
{
    if(a.val==b.val)
        return a.cost<b.cost;
    return a.val>b.val;
}

double memo[25][110][60][5];
int idx[25][110][60][5];
int which[25][110][60][5];

int st=-1;
int track;

double solve(int days,int money,int last,int f)
{
	if(days==0){
		return 0;
	}

int i,j;

    if(last!=-1&&memo[days][money][last][f]!=-1)
        return memo[days][money][last][f];

double ans=INT_MIN;
int sel;
int id;
int temp;

for(i=0;i<n;i++)
{
		if(money>=arr[i].cost)
		{
			if(last!=i){
			temp=arr[i].val + solve(days-1,money-arr[i].cost,i,1);

                if(temp>ans){
                ans=temp;
                sel=1;
                id=i;
                }
			}
			else if(last==i&&f==1)
			{
			temp=arr[i].val/2 + solve(days-1,money-arr[i].cost,i,2);

            if(temp>ans){

            ans=temp;
            sel=2;
            id=i;
            }
        }
else{
    temp=solve(days-1,money-arr[i].cost,i,2);

    if(temp>ans){
    ans=temp;
    sel=2;
    id=i;
    }
}
}
}
//cout<<"id is : "<<id<<endl;
//cout<<days<<" "<<money<<" "<<last<<" "<<f<<" "<<ans<<endl;

    st=id;


    track=sel;

if(last==-1)
    return ans;


idx[days][money][last][f]=id;
which[days][money][last][f]=sel;



return memo[days][money][last][f]=ans;
}

int main()
{
	int test,i;
int t;

int a,b,c,d;

	cin>>k>>n>>m;

	while(k!=0&&n!=0&&m!=0)
	{
	    st=-1;



        for(a=0;a<=k+2;a++)
            for(b=0;b<=m+2;b++)
                for(c=0;c<=n+2;c++)
                    for(d=0;d<=4;d++){
                        memo[a][b][c][d]=-1;
                        //cout<<"here"<<endl;
                    }

		for(i=0;i<n;i++)
		{
			cin>>arr[i].cost>>arr[i].val;
			arr[i].index=i+1;
        }

        sort(arr,arr+n,cmp);

       /* for(i=0;i<n;i++)
		{
			cout<<arr[i].cost<<" "<<arr[i].val<<endl;
        }*/


double ans=solve(k,m,-1,0);

//cout<<"here"<<endl;

if(ans<0)
    printf("0.0\n");
else
    printf("%.1lf\n",ans);

if(ans>=0)
{

    printf("%d ",arr[st].index);

    if(track==1)
    {
        b=m-arr[st].cost;
        c=st;
        d=1;
        m=m-arr[st].cost;
    }
    else
    {
        b=m-arr[st].cost;
        c=st;
        d=2;
        m=m-arr[st].cost;
    }



    for(int e=k-1;e>0;e--)
    {
        a=e;

        printf("%d ",arr[idx[a][b][c][d]].index);

        track=which[a][b][c][d];

        st=idx[a][b][c][d];

            if(track==1)
            {
                b=m-arr[st].cost;
                c=st;
                d=1;
                m=m-arr[st].cost;
            }
            else
            {
                b=m-arr[st].cost;
                c=st;
                d=2;
                m=m-arr[st].cost;
            }
    }

}
printf("\n");

cin>>k>>n>>m;

}

    return 0;
}

