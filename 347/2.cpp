#include<bits/stdc++.h>
using namespace std;

string s[1100];

int arr[1100];

int main()
{
    int i,j,k;
    int n=1;
    int r;
    int ans=0;

    int pos=1,neg=0;

    string t;

    cin>>s[0];
    s[0]="+";
    cin>>t;

    while(t!="=")
    {
        if(t=="+")
            pos++;
        else
            neg++;

        cin>>s[n];
        s[n]=t;
        n++;
        cin>>t;
    }

    scanf("%d",&r);

    //cout<<pos<<" "<<neg<<" "<<r<<endl;

    if(pos*r -neg >= r)
    {
        if(pos - neg*r > r)
            printf("Impossible\n");
        else{
             printf("Possible\n");

            ans=0;

             for(i=0;i<n;i++)
             {
                 arr[i]=1;
             }

             ans = pos-neg;

             ans = r - ans;

             if(ans>0){

                 for(i=0;i<n;i++)
                 {
                     if(s[i]=="+")
                     {
                         int temp=ans;
                         ans = max( 0,ans-(r-arr[i]) );

                         if(ans==0)
                         {
                             arr[i]+=temp;
                             break;
                         }else{
                            arr[i]=r;
                         }
                     }
                 }
             }else{

                ans *= (-1);
                for(i=0;i<n;i++)
                 {
                     if(s[i]=="-")
                     {
                         int temp=ans;
                         ans = max( 0,ans-(r-arr[i]) );

                         if(ans==0)
                         {
                             arr[i]+=temp;
                             break;
                         }else{
                            arr[i]=r;
                         }
                     }
                 }
             }

             printf("%d ",arr[0]);

             for(i=1;i<n;i++)
             {
                 cout<<s[i]<<" ";
                 printf("%d ",arr[i]);
             }
             printf("= %d\n",r);

        }

    }else{
        printf("Impossible\n");
    }

    return 0;
}


















