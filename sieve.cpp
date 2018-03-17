int s[101000];
vector<int> p;
void sieve(){
    int i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=100010;i++){
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<=100010;j+=i){
                s[j]=1;
            }
        }
    }
}
