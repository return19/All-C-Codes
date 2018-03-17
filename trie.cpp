#include<bits/stdc++.h>
using namespace std;


class trie
{
public:

    char data;
    int words;
    int prefix;
    trie* child[26];

    trie()
    {
        data='\0';
        words=0;
        prefix=0;

        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};

void addword(trie* root,char* str)
{
    if(str[0]=='\0')
     {

        root->words=root->words + 1;
        root->prefix=root->prefix + 1;//considered actual words as prefixes as well
     }
    else
    {
        root->prefix=root->prefix + 1;
        char k=str[0];
        str++;

        if(!(root->child[k-'a']))
        {
            root->child[k-'a']=new trie();
        }

        addword(root->child[k-'a'],str);
    }
}

int countwords(trie* root,char* str)
{
    char k=str[0];

    if(k=='\0')
    {
        return root->words;
    }
    else if(!(root->child[k-'a']))
    {
        return 0;
    }
    else
    {
        str++;
        return countwords(root->child[k-'a'],str);
    }

}

int countprefixes(trie* root,char* str)
{
    char k=str[0];

    if(str[0]=='\0')
    {
        return root->prefix;
    }
    else if(!(root->child[k-'a']))
    {
        return 0;
    }
    else
    {
        str++;
        return countprefixes(root->child[k-'a'],str);
    }
}

int main()
{
    trie* tr=new trie();

    char str1[100],str2[100],str3[100];

    cin>>str1>>str2>>str3;


    addword(tr,str1);
    addword(tr,str2);
    addword(tr,str3);

    //cout<<"added"<<endl;

    cin>>str1;

    cout<<countwords(tr,str1)<<endl;

    cin>>str2;

    cout<<countprefixes(tr,str2)<<endl;


    return 0;
}












