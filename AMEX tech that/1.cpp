#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int mask[10]={6,8,9,1,0,2,4,3,5,7};
int pos[10]={4,2,5,0,1,3};
vector<string> month;

int n,m;

vector<int> maskid;
vector<string> merchant;
vector<string> offerid;
vector<string> mode;
vector< pair< pair<int,int>,int > > sd;
vector< pair< pair<int,int>,int > > ed;

vector<int> e_maskid;
vector<int> e_act;
vector<string> e_merchant;
vector< pair< pair<int,int>,int > > e_sd;
vector<int> cost;

map<int,int> online;
map<int,int> total;
map<int,int>::iterator it1,it2;
map<int,int> tt;


int convert(int x)
{
    int i,j,k;
    vector<int> arr;
    while(x!=0)
    {
        arr.push_back(x%10);
        x/=10;
    }

    while(arr.size()!=6)
        arr.push_back(0);

    for(i=0,j=arr.size()-1;i<j;i++,j--)
        swap(arr[i],arr[j]);
    for(i=0;i<arr.size();i++)
        arr[i]=mask[arr[i]];
    vector<int> ans;
    for(i=0;i<arr.size();i++){
        ans.push_back(arr[pos[i]]);
    }
    int res=0;
    for(i=0;i<arr.size();i++)
        res=res*10 + ans[i];
    return res;

}

pair< pair< int,int >,int > dd(string s)
{
    int i,j,k;
    int n=s.length();
    i=0;
    int d=0,m=0,y=0;
    while(s[i]!='-')
    {
        d=d*10 + s[i]-'0';
        i++;
    }
    i++;
    if(s[i]=='A' && s[i+1]=='p')
        m=1;
    else if(s[i]=='M' && s[i+1]=='a' && s[i+2]=='y')
        m=2;
    else if(s[i]=='J' && s[i+1]=='u' && s[i+2]=='n')
        m=3;

    i=n-2;
    for(;i<n;i++)
        y=y*10 + s[i]-'0';

    return mp(make_pair(d,m),y);
}

int inbw(int sd_dd,int sd_mm,int sd_yy,int ed_dd,int ed_mm,int ed_yy,int dd,int mm)
{
    if(mm==0)
        return 0;

    if(sd_yy<15)
    {
        sd_mm=1;
        sd_dd=4;
    }

    if(ed_yy>15)
    {
        ed_mm=3;
        ed_dd=28;
    }

    if(sd_mm==mm)
    {
        if(sd_dd>dd)
            return 0;
        if(ed_mm==mm)
        {
            if(ed_dd<dd)
                return 0;
            return 1;
        }
        return 1;
    }else if(ed_mm==mm)
    {
        if(ed_dd<dd)
            return 0;
        return 1;
    }else if(sd_mm<mm && mm<ed_mm)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i,j,k;
    int x,y,z;
    string s;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        maskid.push_back(x);
        cin>>s;
        merchant.push_back(s);
        cin>>s;
        offerid.push_back(s);
        cin>>s;
        mode.push_back(s);
        cin>>s;
        sd.push_back(dd(s));
        cin>>s;
        ed.push_back(dd(s));
    }
    //cout<<"here"<<endl;
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        e_act.push_back(x);
        x=convert(x);
        //cout<<x<<endl;
        e_maskid.push_back(x);
        cin>>s;
        e_merchant.push_back(s);
        cin>>s;
        e_sd.push_back(dd(s));
        scanf("%d",&x);
        cost.push_back(x);
    }

    for(i=0;i<m;i++)
    {
        int id=e_maskid[i];
        int date=e_sd[i].ft.ft;
        int mnth=e_sd[i].ft.sd;
        int year=e_sd[i].sd;
        tt[e_act[i]]+=cost[i];

        if(inbw(4,1,15,28,3,15,date,mnth) && year == 15)
        {
            total[e_act[i]]+=cost[i];
        }

        int curd=100;
        int curm=100;
        int cury=100;
        int res=0;

        for(j=0;j<n;j++)
        {
            if(maskid[j]==id && e_merchant[i]==merchant[j])
            {
                if(cury>=sd[j].sd && curm>=sd[j].ft.sd && curd>sd[j].ft.ft && mode[j]=="Online" && sd[j].sd <=15 && ed[j].sd>=15 && inbw(sd[j].ft.ft,sd[j].ft.sd,sd[j].sd,ed[j].ft.ft,ed[j].ft.sd,ed[j].sd,date,mnth))
                {
                    //cout<<id<<" "<<merchant[j]<<" "<<cost[i]<<endl;
                    //online[e_act[i]]+=cost[i];
                    res=cost[i];
                    curd=sd[j].ft.ft;
                    curm=sd[j].ft.sd;
                    cury=sd[j].sd;
                }
            }
        }

        online[e_act[i]]+=res;
    }

   // cout<<"here"<<endl;

    for(it1=online.begin(),it2=total.begin();it1!=online.end();it1++,it2++)
    {
        double num,den;
        num=(double)it1->second;
        den=(double)it2->second;
        int id=it1->first;

        vector<int> arr;
        while(id!=0)
        {
            arr.push_back(id%10);
            id/=10;
        }
        while(arr.size()!=6)
            arr.push_back(0);
        for(j=arr.size()-1;j>=0;j--)
            printf("%d",arr[j]);
        cout<<" ";

       // cout<<it1->first<<" ";
        //cout<<num<<" "<<den<<endl;
        double ans=100.0*(num/den);

        if(ans+0.5 >= ceil(ans))
            cout<<ceil(ans)<<endl;
        else
            cout<<floor(ans)<<endl;
    }

    return 0;
}

















