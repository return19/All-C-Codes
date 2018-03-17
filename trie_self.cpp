#include<bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie * parent;
    struct trie* child[26];
    int occ;
};

void init(trie ** root)
{
    for(int i=0;i<26;i++)
        (*root)->child[i]=NULL;

    (*root)->occ=0;
}

void insert_trie(trie *trienode,char str[],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        if(trienode->child[str[i]-'a']==NULL)
        {
            trie *newnode=(trie*)malloc(sizeof(trie));
            init(&newnode);

            newnode->parent=trienode;
            trienode->child[str[i]-'a']=newnode;
            //cout<<"here1"<<endl;
        }
        //cout<<"here"<<endl;
        trienode=trienode->child[str[i]-'a'];
    }

    trienode->occ++;
}

int search_trie(trie *trienode,char str[],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        if(trienode->child[str[i]-'a']==NULL)
            return 0;

        trienode=trienode->child[str[i]-'a'];
    }

    if(trienode->occ>0)
        return 1;
    return 0;
}

void lexico_print_trie(trie *trienode,string word)
{
    int i,j,k;

    int c=trienode->occ;
    //cout<<"lex"<<endl;

    while(c)
    {
        cout<<word<<endl;
        c--;
    }

    for(i=0;i<26;i++)
    {
        if(trienode->child[i])
        {
            string temp=word;
            temp.push_back('a' + i);
            lexico_print_trie(trienode->child[i],temp);
        }
    }
}

trie* tr;

char str[101000];

int main()
{
    int i,j,k;
    int n;

    tr=(trie*)malloc(sizeof(trie));
    init(&tr);

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",str);

        insert_trie(tr,str,strlen(str));
    }

    cout<<search_trie(tr,"abhi",4)<<endl;

    cout<<search_trie(tr,"abi",3)<<endl;

    cout<<search_trie(tr,"abhinan",7)<<endl;

    lexico_print_trie(tr,"");

    return 0;
}
