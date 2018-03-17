#include<bits/stdc++.h>
using namespace std;

queue< pair< pair<int,int>,pair<int,int> > > q;

int arr[110][110];

char str[110];

int move_x[10]={0,-1,0,1};
int move_y[10]={-1,0,1,0};

int r,c;

int check(int x,int y)
{
	if(x>=0 && x<r && y>=0 &&y<c)
		return 1;
	return 0;
}

void maskit(int &mask,int pos)
{
	pos/=10;

	mask=mask|(1<<pos);
}

int ismasked(int mask,int pos)
{
	pos/=10;

	if(mask & (1<<pos))
		return 1;
	return 0;
}

int vis[110][110][70];

int main()
{
	int i,j,k;



	int st_x,st_y;

	scanf("%d%d",&r,&c);

	while( r!=0 && c!=0 )
	{
		for(i=0;i<=r;i++)
            for(j=0;j<=c;j++)
                for(k=0;k<70;k++)
                    vis[i][j][k]=-1;

		for(i=0;i<r;i++)
		{
			scanf("%s",str);

			for(j=0;j<c;j++)
			{
				if(str[j]=='#')
				{
					arr[i][j]=-1;
}
else if(str[j]=='.')
{
	arr[i][j]=1;
}
else if(str[j]=='*')
{
	arr[i][j]=1;
	st_x=i;
	st_y=j;
}
else if(str[j]=='R')
	arr[i][j]=100;
else if(str[j]=='r')
	arr[i][j]=10;
else if(str[j]=='B')
	arr[i][j]=200;
else if(str[j]=='b')
	arr[i][j]=20;
else if(str[j]=='G')
	arr[i][j]=300;
else if(str[j]=='g')
	arr[i][j]=30;
else if(str[j]=='Y')
	arr[i][j]=400;
else if(str[j]=='y')
	arr[i][j]=40;
else
arr[i][j]=5;

}
}

int tx,ty;
int x,y;
int mask;
int m;
int temp;

q.push(make_pair(make_pair(st_x,st_y),make_pair(0,0)));

pair< pair<int,int>,pair<int,int> > p;

int ans=-1;

while(!q.empty())
{
	p=q.front();
	q.pop();

	x=p.first.first;
	y=p.first.second;
	mask=p.second.first;
	m=p.second.second;


	for(i=0;i<4;i++)
{
	tx = x + move_x[i];
	ty= y + move_y[i];

temp=mask;


	if( !check(tx,ty) || arr[tx][ty]==-1)
		continue;

	if(arr[tx][ty]==5)
	{
		ans=m+1;
		break;
}

	if(arr[tx][ty]>=10&&arr[tx][ty]<100)
		maskit(temp,arr[tx][ty]);

	if(vis[tx][ty][temp]==1)
		continue;

	vis[tx][ty][temp]=1;

				if(arr[tx][ty]>=100)
				{
					if(ismasked(mask,arr[tx][ty]/10))
					{
						q.push(make_pair(make_pair(tx,ty),make_pair(mask,m+1)));
}
}
else
{
	q.push(make_pair(make_pair(tx,ty),make_pair(temp,m+1)));
}
}

if(ans!=-1)
	break;

}

while(!q.empty())
	q.pop();
if(ans!=-1)
printf("Escape possible in %d steps.\n",ans);
else
printf("The poor student is trapped!\n");
		scanf("%d%d",&r,&c);
}

	return 0;
}

