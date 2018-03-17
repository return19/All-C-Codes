#include<bits/stdc++.h>
using namespace std;

map<char,long long> pos;

map<char,long long> inner_pos;

char str[1500];

void init()
{
    pos['.']=1;
    pos[',']=1;
    pos['?']=1;
    pos['!']=1;
    pos['1']=1;

    pos['a']=2;
    pos['b']=2;
    pos['c']=2;
    pos['2']=2;

    pos['d']=3;
    pos['e']=3;
    pos['f']=3;
    pos['3']=3;

    pos['g']=4;
    pos['h']=4;
    pos['i']=4;
    pos['4']=4;

    pos['j']=5;
    pos['k']=5;
    pos['l']=5;
    pos['5']=5;

    pos['m']=6;
    pos['n']=6;
    pos['o']=6;
    pos['6']=6;

    pos['p']=7;
    pos['q']=7;
    pos['r']=7;
    pos['s']=7;
    pos['7']=7;

    pos['t']=8;
    pos['u']=8;
    pos['v']=8;
    pos['8']=8;

    pos['w']=9;
    pos['x']=9;
    pos['y']=9;
    pos['z']=9;
    pos['9']=9;

    pos['0']=0;
    pos['_']=0;

    /////////////

    inner_pos['.']=1;
    inner_pos[',']=2;
    inner_pos['?']=3;
    inner_pos['!']=4;
    inner_pos['1']=5;

    inner_pos['a']=1;
    inner_pos['b']=2;
    inner_pos['c']=3;
    inner_pos['2']=4;

    inner_pos['d']=1;
    inner_pos['e']=2;
    inner_pos['f']=3;
    inner_pos['3']=4;

    inner_pos['g']=1;
    inner_pos['h']=2;
    inner_pos['i']=3;
    inner_pos['4']=4;

    inner_pos['j']=1;
    inner_pos['k']=2;
    inner_pos['l']=3;
    inner_pos['5']=4;

    inner_pos['m']=1;
    inner_pos['n']=2;
    inner_pos['o']=3;
    inner_pos['6']=4;

    inner_pos['p']=1;
    inner_pos['q']=2;
    inner_pos['r']=3;
    inner_pos['s']=4;
    inner_pos['7']=5;

    inner_pos['t']=1;
    inner_pos['u']=2;
    inner_pos['v']=3;
    inner_pos['8']=4;

    inner_pos['w']=1;
    inner_pos['x']=2;
    inner_pos['y']=3;
    inner_pos['z']=4;
    inner_pos['9']=5;

    inner_pos['0']=2;
    inner_pos['_']=1;
}

int main()
{
    long long test,i,j,k,sum=0,n;

    init();
    long long cur_pos=1;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        cur_pos=1;
        scanf("%s",str);
        j=0;
        while(str[j]!='\0')
        {
            if(cur_pos!=pos[str[j]])
                sum=sum+inner_pos[str[j]]+1;
            else
                sum=sum+inner_pos[str[j]];

            cur_pos=pos[str[j]];
            j++;
        }

        printf("%lld\n",sum);

    }

    return 0;
}











