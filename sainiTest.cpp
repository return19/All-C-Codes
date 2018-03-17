#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
int arr[110][110];
pair<int,int> par[110][110];
int mx[10]={-1,1,0,0};
int my[10]={0,0,-1,1};

int qx[10100];
int qy[10100];

map< pair<int,int>,int> memo;

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

// just create par[] array and initialize it with -1

pair<int,int> root(int x,int y){
    if(par[x][y].ft < 0)
        return mp(x,y);
    return par[x][y] = root(par[x][y].ft, par[x][y].sd);
}
void merge_dsu(int x,int y,int a,int b){	//	x and y are some tools (vertices)
    x = root(x,y).ft;
    y = root(x,y).sd;

    a = root(a,b).ft;
    b = root(a,b).sd;

    if((x==a)&&(y==b))
        return;

	if(par[a][b].ft < par[x][y].ft){	// balancing the height of the tree
		swap(x, a);
		swap(y, b);
	}
	par[x][y].ft += par[a][b].ft;
	par[a][b] = mp(x,y);
}

int isConnected(){
    int i,j,k;
    memo.clear();
    for(i=0;i<n;i++)
        if(arr[i][0]==1)
            memo[root(i,0)]=1;

    for(i=0;i<n;i++){
        if(arr[i][0] && memo.find(root(i,m-1))!=memo.end())
            return 0;
    }
    return 1;
}

int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
            par[i][j].ft=-1;
        }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==1){
                for(k=0;k<4;k++){
                    int tx = i + mx[k];
                    int ty = j + my[k];
                    if(check(tx,ty) && arr[tx][ty]){
                        merge_dsu(i,j,tx,ty);
                    }
                }
            }
        }
    }

    int q;
    int x,y;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d%d",&qx[i],&qy[i]);
    }

   /* for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<root(i,j).ft<<":"<<root(i,j).sd<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    if(!isConnected())
    {
        printf("0\n");
        return 0;
    }

    for(i=0;i<q;i++){
        arr[qx[i]][qy[i]]=1;
        for(k=0;k<4;k++){
            int tx = qx[i] + mx[k];
            int ty = qy[i] + my[k];

            if(check(tx,ty) && arr[tx][ty])
                merge_dsu(qx[i],qy[i],tx,ty);
        }


       /* for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                cout<<root(j,k).ft<<":"<<root(j,k).sd<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;*/

        if(!isConnected()){
            //cout<<"here"<<endl;
            printf("%d\n",i+1);
            return 0;
        }
    }

    return 0;
}





/*
4 6
011010
000010
100001
001000
7
0 3
1 5
1 3
0 0
1 2
2 4
2 1
*/








