#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

char arr[1010][1010];
long long n,m;
long long xt,yt;
long long xm,ym;

char convert(long long x,long long y,long long c){
    if(arr[x][y]=='+')  return '+';
    if(arr[x][y]=='-')
        if(c%2==0)  return '-';
        else    return '|';
    if(arr[x][y]=='|')
        if(c%2==0)  return '|';
        else    return '-';
    if(arr[x][y]=='^'){
        if(c%4==0)
            return '^';
        else if(c%4==1)
            return '>';
        else if(c%4==2)
            return 'v';
        else
            return '<';
    }
    if(arr[x][y]=='>'){
        if(c%4==3)
            return '^';
        else if(c%4==0)
            return '>';
        else if(c%4==1)
            return 'v';
        else
            return '<';
    }
    if(arr[x][y]=='v'){
        if(c%4==2)
            return '^';
        else if(c%4==3)
            return '>';
        else if(c%4==0)
            return 'v';
        else
            return '<';
    }
    if(arr[x][y]=='<'){
        if(c%4==1)
            return '^';
        else if(c%4==2)
            return '>';
        else if(c%4==3)
            return 'v';
        else
            return '<';
    }

    char s[10]={'L','U','R','D'};

    if(arr[x][y]=='L')
        return s[c%4];
    if(arr[x][y]=='U')
        return s[(c+1)%4];
    if(arr[x][y]=='R')
        return s[(c+2)%4];
    if(arr[x][y]=='D')
        return s[(c+3)%4];
    if(arr[x][y]=='*')
        return '*';

}

long long move_x[10]={-1,1,0,0};
long long move_y[10]={0,0,1,-1}; // UDRL

queue< pair< pair<long long,long long>,pair<long long,long long> > > q; // x,y,c,ans

long long check(long long x,long long y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}
long long memo[1010][1010][4];

long long solve(){
    long long i,j,k;
    q.push(mp(mp(xt,yt),mp(0,0)));
    memo[xt][yt][0]=0;

    while(!q.empty())
    {
        pair< pair<long long,long long>,pair<long long,long long> > p;
        p=q.front();
        q.pop();

        long long x,y,c,ans;
        x=p.ft.ft;
        y=p.ft.sd;
        c=p.sd.ft;
        ans=p.sd.sd;

        if(memo[x][y][(c+1)%4]>ans+1)
            q.push(mp(mp(x,y),mp(c+1,ans+1)));

        char temp=convert(x,y,c);

        for(i=0;i<4;i++){
            long long tx,ty;
            tx=x + move_x[i];
            ty=y + move_y[i];

            if(!check(tx,ty))
                continue;
            if(arr[tx][ty]=='*')
                continue;

            if(temp=='|' && (i==2||i==3))
                continue;
            if(temp=='-' && (i==0||i==1))
                continue;
            if(temp=='L' && i==3) continue;

            if(temp=='R' && i==2) continue;

            if(temp=='U' && i==0) continue;

            if(temp=='D' && i==1) continue;

            if(temp=='^' && i!=0) continue;
            if(temp=='v' && i!=1) continue;
            if(temp=='>' && i!=2) continue;
            if(temp=='<' && i!=3) continue;

            if(tx==xm && ty==ym)
                return ans+1;

            if(memo[tx][ty][c%4]<ans+1)
                continue;

            memo[tx][ty][c%4]=ans;

            q.push(mp(mp(tx,ty),mp(c,ans+1)));
        }
    }
    return -1;
}

int main()
{
    long long i,j,k;
    long long x,y,z;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=0;k<4;k++)
                memo[i][j][k]=LLONG_MAX;


    scanf("%lld%lld%lld%lld",&xt,&yt,&xm,&ym);
    xt--;
    yt--;
    xm--;
    ym--;

    long long ans=solve();
    printf("%lld\n",ans);

    return 0;
}

